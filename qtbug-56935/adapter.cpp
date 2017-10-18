#include <QtQml>
#include <QQmlEngine>
#include "adapter.h"

Adapter::Adapter(QObject *parent) : QObject(parent)
{

}

void Adapter::clearComponentCache()
{
    m_engine->clearComponentCache();
}

QQmlEngine *Adapter::engine() const
{
    return m_engine;
}

void Adapter::setEngine(QQmlEngine *engine)
{
    m_engine = engine;
}


static QObject *provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);

    Adapter* object = new Adapter();
    object->setEngine(engine);

    return object;
}

void init()
{
    qmlRegisterSingletonType<Adapter>("Adapter", 1, 0, "Adapter", provider);
}

Q_COREAPP_STARTUP_FUNCTION(init)
