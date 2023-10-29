#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QFont>
#include "StatusClient.hpp"

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    //QFontDatabase::addApplicationFont(":/fonts/DejaVuSans.ttf");
    //app.setFont(QFont("DejaVu Sans"));

    StatusClient *statusclient = new StatusClient();

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("car", statusclient);

    const QUrl url(QStringLiteral("qrc:/qml/dashboard.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);


    return app.exec();
}
