//#include "mainwindow.h"
#include "idlefilter.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    IdleFilter *idleFilter = new IdleFilter();
    app.installEventFilter(idleFilter);


    QQmlApplicationEngine engine;

    QUrl url (QStringLiteral("qrc:/main.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [&engine, url, idleFilter](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
        QObject::connect(idleFilter, SIGNAL(signalAppIsActive()), engine.rootObjects().first(), SIGNAL(appIsActive()));
        QObject::connect(idleFilter, SIGNAL(signalAppIsInactive()), engine.rootObjects().first(), SIGNAL(appIsInactive()));
    }, Qt::QueuedConnection);
    engine.load(url);



    return app.exec();
}
