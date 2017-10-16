#include <QtQuickTest/quicktest.h>
#include <QtGlobal>
#include <QtConcurrent>
#include <unistd.h>
#include <signal.h>

int main(int argc, char **argv)
{
    qputenv("QTEST_FUNCTION_TIMEOUT", "1000");

    bool running = true;

    QThreadPool pool;
    QFuture<void> future = QtConcurrent::run(&pool, [&]() {
        qDebug() << "Start watchdog";
        sleep(3);
        if (running) {
            qDebug() << "Timeout. Watchdog kill current process";
            kill(getpid(), SIGKILL);
            return;
        }
        qDebug() << "Watchdog quit";
    });

    quick_test_main(argc, argv, "QuickTests", QUICK_TEST_SOURCE_DIR);
    running = false;
    future.waitForFinished();

    return 0;
}
