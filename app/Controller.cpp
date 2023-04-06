#include "Controller.hpp"
#include <QUrl>

Controller::Controller(QObject *parent)
    : QObject{parent}
{

}

SoundTrackListModel* Controller::getModel()
{
    return &mModel;
}

void Controller::addSoundTrack(const QUrl& url)
{
    mModel.Add(url.toLocalFile());
}

void Controller::removeSoundTrack(int index)
{
    mModel.Delete(index);
}

void Controller::mix()
{
    mModel.Mix();
}
