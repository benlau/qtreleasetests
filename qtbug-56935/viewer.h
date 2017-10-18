#ifndef VIEWER_H
#define VIEWER_H

#include <QObject>
#include <QHash>
#include <QQmlEngine>
#include <QQuickView>

class QQmlComponent;
class QQuickItem;
class QWindow;

class Viewer: public QObject
{
    Q_OBJECT

public:
    explicit Viewer(QWindow *parent = 0);
    virtual ~Viewer();

public:
    void create(QUrl url);
    void registerObject(QObject *obj);

    void show();
    void hide();

Q_SIGNALS:
    void sgnShown();
    void sgnHidden();
    void sgnItemDisplayed();

private Q_SLOTS:
    void sltShown();
    void sltHidden();
    void sltItemDisplayed();

private:
    QQmlEngine      mEngine;
    QQuickView      mView;
    QQmlComponent   *mComponent;
    QQuickItem      *mItem;
};

#endif // VIEWER_H
