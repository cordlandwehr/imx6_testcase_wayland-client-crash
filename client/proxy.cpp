#include "proxy.h"
#include <QQuickView>
#include <QTimer>
#include <QDebug>
#include <QQmlContext>

void Proxy::spawnWindow()
{
    auto view = new QQuickView;
    view->rootContext()->setContextProperty("gProxy", this);
    view->setSource(QUrl("qrc:///qml/window.qml"));
    view->show();
    windows.append(view);
}

void Proxy::killLatestWindow()
{
    // delay destruction until we hit another render sync
    QTimer::singleShot(10, this, [=]{
        if (windows.isEmpty()) {
          qDebug() << "no window, aborting";
          return;
        }
        windows.top()->close();
        windows.top()->deleteLater();
        windows.pop();
    });
}
