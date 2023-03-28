#include "SampleTrack.hpp"

#include <sstream>
#include <exception>





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
