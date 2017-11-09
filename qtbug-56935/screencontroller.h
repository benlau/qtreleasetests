#ifndef SCREENCONTROLLER_H
#define SCREENCONTROLLER_H

#include <QObject>
#include <QSharedPointer>
#include <QTimer>
#include <QList>

#include "viewer.h"

struct Screen
{
    QString qmlPath;
    int     switchTimeout;
    QSharedPointer<QObject> contextObject;
};

class ScreenController : public QObject
{
    Q_OBJECT

public:
    explicit ScreenController(QObject *parent = 0);
    virtual ~ScreenController();

public:
    void init();

private Q_SLOTS:
    void sltShowNextScreen();
    void sltStartHideTimer();
    void sltHideCurrentScreen();

private:
    QTimer mTimer;
    Viewer mViewer;
    Screen *mScreen;
};

#endif // SCREENCONTROLLER_H
