#ifndef SOUNDTRACKLISTMODEL_H
#define SOUNDTRACKLISTMODEL_H

#include <QAbstractListModel>
#include <vector>
#include "SoundTrack.hpp"

class SoundTrackListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    SoundTrackListModel(QObject* parent = nullptr);
    ~SoundTrackListModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void Add(const QString& trackName);
    void Delete(int index);
    void Mix();

private:
    std::vector<SoundTrack*> mSoundTracks;
};

#endif // SOUNDTRACKLISTMODEL_H
