#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "SoundTrackListModel.hpp"
#include "Controller.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    qmlRegisterType<SoundTrackListModel>("SoundMixer", 1, 0, "SoundTracks_qml");
    qmlRegisterType<Controller>("SoundMixer", 1, 0, "Controller_qml");
    qmlRegisterUncreatableType<SoundTrack>("SounMixer", 1, 0, "SoundTrack_qml", "Cannot create SoundTrack in QML");

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/app/qml/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
