#ifndef SAMPLETRACK_H
#define SAMPLETRACK_H

#include "Buffer.hpp"

#include <stdint.h>
#include <string>
#include <sndfile.h>

class SampleTrack
{
public:
    SampleTrack();
    SampleTrack(const std::string& trackName);
    ~SampleTrack();

    int32_t GetSamplerate() const;
    int32_t GetChannels() const;
    int64_t GetFrames() const;

    uint64_t GetDuration() const;

    Buffer GetBuffer();
    Buffer GetBuffer(int32_t timeStart, int32_t timeEnd);

private:
    int32_t mSamplerate;
    int32_t mChannels;
    int64_t mFrames;

    SNDFILE* mFile;

    void LoadFromFile(const std::string& file);
};

#endif // SAMPLETRACK_H
