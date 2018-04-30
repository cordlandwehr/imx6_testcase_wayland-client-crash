#include <QUrl>
#include <QDebug>
#include <QGuiApplication>
#include <QQuickView>
#include <QQmlContext>

#include "proxy.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    Proxy *proxy = new Proxy;

    QQuickView view;
    view.rootContext()->setContextProperty("gProxy", proxy);
    view.setSource(QUrl("qrc:///qml/main.qml"));
    view.show();

    return app.exec();
}
