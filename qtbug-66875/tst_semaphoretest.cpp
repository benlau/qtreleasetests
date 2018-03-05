#include <QString>
#include <QtTest>
#include <QtConcurrent>
#include <QThreadPool>

class SemaphoreTest : public QObject
{
    Q_OBJECT

public:
    SemaphoreTest();

private Q_SLOTS:
    void bug();
};

SemaphoreTest::SemaphoreTest()
{

}

QSemaphore semaphore(1);

void worker(int value) {
    qDebug() << value << "entry";
    semaphore.acquire();
    semaphore.release();
    qDebug() << value << "exit";
}

void SemaphoreTest::bug()
{
    int count = 4;
    QList<int> input;
    for (int i = 0 ;i < count;i++) {
        input << i;
    }

    semaphore.acquire();

    QFuture<void> future = QtConcurrent::map(input, worker);

    QEventLoop loop;
    QTimer::singleShot(1000, [&]() {
        loop.quit();
    });
    loop.exec();

    qDebug() << "release semaphore in main thread";
    semaphore.release();

    QTRY_COMPARE(future.isFinished(), true);
}

QTEST_MAIN(SemaphoreTest)

#include "tst_semaphoretest.moc"
