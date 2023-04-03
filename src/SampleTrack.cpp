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

Buffer SampleTrack::GetBuffer()
{
    sf_seek(mFile, 0, SEEK_SET);

    Buffer buffer = Buffer(mChannels, mFrames, mSamplerate);

    const size_t maxNumFrames = 1024;
    float frames[maxNumFrames];

    size_t startToInsert = 0;
    sf_count_t framesNum = 0;
    auto& data = buffer.Data();
    while ((framesNum = sf_read_float(mFile, frames, maxNumFrames)))
    {
        for (int64_t j = 0; j < framesNum; ++j)
        {
            data[startToInsert] = frames[j];
            startToInsert++;
        }
    }

    return buffer;
}

Buffer SampleTrack::GetBuffer(int32_t timeStart, int32_t timeEnd)
{
    assert(timeEnd > timeStart);

    int64_t numFrames = (timeEnd - timeStart) * mSamplerate * mChannels;
    int64_t offset = timeStart * mSamplerate;
    sf_seek(mFile, offset, SEEK_SET);


    Buffer buffer(mChannels, numFrames, mSamplerate);

    const int64_t maxNumFrames = 1024;
    float frames[maxNumFrames];

    size_t startToInsert = 0;
    sf_count_t numFramesRead;
    auto& data = buffer.Data();

    while((numFramesRead = sf_read_float(mFile, frames, std::min(maxNumFrames, numFrames))))
    {
        for (int64_t j = 0; j < numFramesRead; ++j)
        {
            data[startToInsert] = frames[j];
            startToInsert++;
        }

        numFrames -= numFramesRead;
    }

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
