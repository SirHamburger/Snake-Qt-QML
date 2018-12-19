#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlContext>
#include <QQuickView>

#include <message.h>

#include <iostream>


int main(int argc, char *argv[])
{

        //QQuickWindow::setSceneGraphBackend(QSGRendererInterface::Software);


    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    app.setOrganizationName("Some Company");
    app.setOrganizationDomain("somecompany.com");
    app.setApplicationName("Amazing Application");

    QQmlApplicationEngine engine ;
//std::cout << "Test";

    QQuickView view;
    Message msg;
    engine.rootContext()->setContextProperty("msg", &msg);
//    view.setSource(QUrl::fromLocalFile("main.qml"));
//    view.show();


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    if (engine.rootObjects().isEmpty())
        return -1;

    //for(int i = 0; i < 10000000; i++);
        //msg.sendKoordinates(i,i);


      // engine.load(QUrl(QStringLiteral("qrc:/SettingsWindow.qml")));
    return app.exec();
}
