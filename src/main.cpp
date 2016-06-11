#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQmlContext>
#include "mycoap.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QQmlComponent component(&engine, QUrl(QStringLiteral("qrc:/main.qml")));
    QObject *object = component.create();
    QObject *rootObject = object->findChild<QObject*>("textObject");
    if (rootObject) {
        qDebug()<<"textObject!";
        MyCoAP *mcoap = new MyCoAP(rootObject);
        // mcoap->observe(QUrl("coap://vs0.inf.ethz.ch/obs"));
        mcoap->observe(QUrl("coap://vs0.inf.ethz.ch/obs"));
    }
    return app.exec();
}
