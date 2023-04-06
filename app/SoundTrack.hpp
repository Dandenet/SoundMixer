#ifndef SOUNDTRACK_H
#define SOUNDTRACK_H

#include <QObject>
#include <QProperty>
#include <SampleTrack.hpp>
#include <Buffer.hpp>

class SoundTrack : public QObject
{
    Q_PROPERTY(QString name READ GetName CONSTANT)
    Q_PROPERTY(int startTime READ GetStartTime WRITE SetStartTime NOTIFY startTimeChanged)
    Q_PROPERTY(int endTime READ GetEndTime WRITE SetEndTime NOTIFY endTimeChanged)
    Q_OBJECT

public:
    SoundTrack(QObject* parent = nullptr);
    SoundTrack(const QString& name, QObject* parent = nullptr);

    QString GetName() const;
    int GetStartTime() const;
    int GetEndTime() const;
    std::shared_ptr<Buffer> GetBuffer();

    void SetStartTime(int newStartTime);
    void SetEndTime(int newEndTime);

    Q_INVOKABLE void increaseStartTime();
    Q_INVOKABLE void decreaseStartTime();

    Q_INVOKABLE void increaseEndTime();
    Q_INVOKABLE void decreaseEndTime();


signals:
    void startTimeChanged();
    void endTimeChanged();

private:
    QString  mName;
    int      mStartTime;
    int      mEndTime;

    SampleTrack mTrack;
};

Q_DECLARE_METATYPE(SoundTrack*)

#endif // SOUNDTRACK_H
