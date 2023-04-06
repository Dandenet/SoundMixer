#include "SoundTrack.hpp"

SoundTrack::SoundTrack(QObject* parent) : QObject(parent)
{

}

SoundTrack::SoundTrack(const QString& name, QObject* parent) :
    QObject(parent), mName(name),
    mStartTime(0), mTrack(mName.toStdString())
{
    mEndTime = mTrack.GetDuration();
}


QString SoundTrack::GetName() const
{
    return mName;
}

int SoundTrack::GetStartTime() const
{
    return mStartTime;
}

int SoundTrack::GetEndTime() const
{
    return mEndTime;
}

std::shared_ptr<Buffer> SoundTrack::GetBuffer()
{
    return mTrack.GetBuffer(mStartTime, mEndTime);
}

void SoundTrack::SetStartTime(int newStartTime)
{
    if (mStartTime == newStartTime)
        return;
    mStartTime = newStartTime;
    emit startTimeChanged();
}

void SoundTrack::SetEndTime(int newEndTime)
{
    if (mEndTime == newEndTime)
        return;
    mEndTime = newEndTime;
    emit endTimeChanged();
}

void SoundTrack::increaseStartTime()
{
    if (mEndTime - mStartTime > 1) {
        SetStartTime(mStartTime + 1);
    }
}

void SoundTrack::decreaseStartTime()
{
    if (mStartTime > 1) {
        SetStartTime(mStartTime - 1);
    }
}

void SoundTrack::increaseEndTime()
{
    if (mTrack.GetDuration() - mEndTime > 1) {
        SetEndTime(mEndTime + 1);
    }
}

void SoundTrack::decreaseEndTime()
{
    if (mEndTime - mStartTime  > 1) {
        SetEndTime(mEndTime - 1);
    }
}
