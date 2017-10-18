#ifndef ADAPTER_H
#define ADAPTER_H

#include <QObject>
#include <QQmlEngine>

class Adapter : public QObject
{
    Q_OBJECT
public:
    explicit Adapter(QObject *parent = nullptr);

    QQmlEngine *engine() const;
    void setEngine(QQmlEngine *engine);

signals:

public slots:
    void clearComponentCache();

private:
    QQmlEngine* m_engine;
};

#endif // ADAPTER_H
