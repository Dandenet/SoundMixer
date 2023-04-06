#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

#include "SoundTrackListModel.hpp"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);

    Q_INVOKABLE SoundTrackListModel* getModel();
    Q_INVOKABLE void addSoundTrack(const QUrl& url);
    Q_INVOKABLE void removeSoundTrack(int index);
    Q_INVOKABLE void mix();

private:
    SoundTrackListModel mModel;

};

#endif // CONTROLLER_H
