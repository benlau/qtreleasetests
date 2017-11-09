// Object API
#include "screencontroller.h"

// QtCore API
#include <QThread>

// QtQml API
#include <QtQml>

// QtGui API
#include <QGuiApplication>

// Application API
#include "viewer.h"

ScreenController::ScreenController(QObject *parent)
    : QObject(parent),
      mTimer(this),
      mScreen(Q_NULLPTR)
{
}

ScreenController::~ScreenController()
{
}

// --- public ---
void ScreenController::init()
{
    const int screenTimeout = 1;
    mScreen = new Screen(Screen {
                             "qrc:/ui/Crash.qml",
                             screenTimeout,
                             QSharedPointer<QObject>()
                         });

    mTimer.setSingleShot(true);
    connect(&mTimer,  &QTimer::timeout,
            this,     &ScreenController::sltHideCurrentScreen);

    connect(&mViewer, &Viewer::sgnShown,
            this,     &ScreenController::sltShowNextScreen);
    connect(&mViewer, &Viewer::sgnHidden,
            this,     &ScreenController::sltShowNextScreen);
    connect(&mViewer, &Viewer::sgnItemDisplayed,
            this,     &ScreenController::sltStartHideTimer);
    mViewer.show();
}

// --- private slots ---
void ScreenController::sltShowNextScreen()
{
    if (mScreen == Q_NULLPTR) {
        QCoreApplication::flush();
        QGuiApplication::instance()->quit();
        return;
    }

    if (!mScreen->contextObject.isNull()) {
        mViewer.registerObject(mScreen->contextObject.data());
    }

    mViewer.create(QUrl(mScreen->qmlPath));
}

void ScreenController::sltStartHideTimer()
{
    mTimer.start(mScreen->switchTimeout);
}

void ScreenController::sltHideCurrentScreen()
{
    mViewer.hide();
    delete mScreen;
    mScreen = Q_NULLPTR;
}
