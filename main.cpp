#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "processmanager.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    ProcessManager * processManager = ProcessManager::getInstance();
    engine.rootContext()->setContextProperty("processManager", processManager);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
