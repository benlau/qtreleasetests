// Object API
#include "viewer.h"

// QtCore API
#include <QTimer>

// QtQml API
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQmlContext>

// QtQuick API
#include <QQuickView>
#include <QQuickItem>

Viewer::Viewer(QWindow *parent)
    : QObject(parent),
      mEngine(this),
      mView(&mEngine, parent),
      mComponent(Q_NULLPTR),
      mItem(Q_NULLPTR)
{
    mView.create();
    mView.setGeometry(0,0,400,240);

    connect(&mView, &QQuickView::frameSwapped,
            this,   &Viewer::sltShown);
}

Viewer::~Viewer()
{
}

// --- public ---
void Viewer::create(QUrl url)
{
    mComponent = new QQmlComponent(&mEngine, url);

    QObject *component = mComponent->create();
    if(component == Q_NULLPTR) {
        qCritical() << "Component creation failed for url " << url;
        return;
    }

    mItem = qobject_cast<QQuickItem*>(component);
    if(mItem == Q_NULLPTR) {
        qCritical() << "Cast to QQuickItem failed";
        return;
    }

    connect(&mView, &QQuickView::frameSwapped,
            this,   &Viewer::sltItemDisplayed);

    mItem->setParentItem(mView.contentItem());
}

void Viewer::registerObject(QObject *obj)
{
    if(obj != Q_NULLPTR) {
        mEngine.rootContext()->setContextProperty("context", obj);
    } else {
        qWarning() << "Viewer::registerObject called with null QObject";
    }
}

void Viewer::show()
{
    mView.show();
}

void Viewer::hide()
{
    if(mItem == Q_NULLPTR) {
        qCritical() << "mItem is NULL";
    }

    delete mComponent;
    delete mItem;

    mEngine.clearComponentCache(); // <-- this in combination with "BaseItem" will make it crash

    QTimer::singleShot(0, this, SLOT(sltHidden()));
}

// --- private slots ---
void Viewer::sltShown()
{
    disconnect(&mView, &QQuickView::frameSwapped,
               this,   &Viewer::sltShown);
    emit sgnShown();
}

void Viewer::sltHidden()
{
    emit sgnHidden();
}

void Viewer::sltItemDisplayed()
{
    disconnect(&mView, &QQuickView::frameSwapped,
               this,   &Viewer::sltItemDisplayed);
    emit sgnItemDisplayed();
}



