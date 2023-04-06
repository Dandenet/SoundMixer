#include "SoundTrackListModel.hpp"
#include <Mixer.hpp>
#include <Buffer.hpp>
#include <SampleTrack.hpp>

SoundTrackListModel::SoundTrackListModel(QObject* parent) :
    QAbstractListModel(parent) {}

SoundTrackListModel::~SoundTrackListModel()
{
    for (auto& track : mSoundTracks)
        delete track;
}

int SoundTrackListModel::rowCount(const QModelIndex& parent) const
{
    return static_cast<int>(mSoundTracks.size());
}

QVariant SoundTrackListModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid()) {
        return {};
    }

    if (index.row() >= mSoundTracks.size())
        return {};

    if (role == Qt::DisplayRole)
        return QVariant::fromValue(mSoundTracks[index.row()]);

    return {};
}

void SoundTrackListModel::Add(const QString& trackName)
{
    int row = static_cast<int>(mSoundTracks.size());
    beginInsertRows(QModelIndex(), row, row);

    try {
        mSoundTracks.push_back(new SoundTrack(trackName));
    } catch (const std::exception& e) {
        qDebug() << e.what();
    }


    endInsertRows();
}

void SoundTrackListModel::Delete(int index)
{
    beginRemoveRows(QModelIndex(), index, index);

    mSoundTracks.erase(mSoundTracks.begin() + index);

    endRemoveRows();
}

void SoundTrackListModel::Mix()
{
    try {
        Mixer mixer;
        for (auto& soundTrack : mSoundTracks)
            mixer.Attach(soundTrack->GetBuffer());

        SampleTrack::Save(mixer.Mix(), "save.wav");

    } catch (const std::exception& e) {
        qDebug() << e.what();
    }
}
