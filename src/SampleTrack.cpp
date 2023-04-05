#include "SampleTrack.hpp"

#include <sstream>
#include <exception>
#include <iostream>





SampleTrack::SampleTrack()
{

}

SampleTrack::SampleTrack(const std::string &trackName)
{
    LoadFromFile(trackName);
}

SampleTrack::~SampleTrack()
{
    sf_close(mFile);
}


int32_t SampleTrack::GetSamplerate() const
{
    return mSamplerate;
}

int64_t SampleTrack::GetFrames() const
{
    return mFrames;
}

uint64_t SampleTrack::GetDuration() const
{
    return mFrames / mSamplerate;
}

std::shared_ptr<Buffer> SampleTrack::GetBuffer()
{
    sf_seek(mFile, 0, SEEK_SET);

    std::shared_ptr<Buffer> buffer(new Buffer(mChannels, mFrames, mSamplerate));
    auto& data = buffer->Data();
    sf_read_float(mFile, data.data(), mFrames * mChannels);
    return buffer;
}

std::shared_ptr<Buffer> SampleTrack::GetBuffer(int32_t timeStart, int32_t timeEnd)
{
    assert(timeEnd > timeStart);

    int64_t numFrames = (timeEnd - timeStart) * mSamplerate;
    int64_t offset = timeStart * mSamplerate;
    sf_seek(mFile, offset, SEEK_SET);


    std::shared_ptr<Buffer> buffer( new Buffer(mChannels, numFrames, mSamplerate));
    auto& data = buffer->Data();
    sf_read_float(mFile, data.data(), numFrames * mChannels);
    return buffer;
}

void SampleTrack::LoadFromFile(const std::string &file)
{
    SF_INFO info;
    mFile = sf_open(file.c_str(), SFM_READ, &info);
    if (!mFile)
    {
        std::stringstream ss;
        ss << "Error opening file " << file << ": " << sf_strerror(mFile);
        throw std::exception(ss.str().c_str());
    }

    mChannels = info.channels;
    mFrames = info.frames;
    mSamplerate = info.samplerate;

}
