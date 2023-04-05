#ifndef SAMPLETRACK_H
#define SAMPLETRACK_H

#include "Buffer.hpp"

#include <stdint.h>
#include <string>
#include <memory>
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

    std::shared_ptr<Buffer> GetBuffer();
    std::shared_ptr<Buffer> GetBuffer(int32_t timeStart, int32_t timeEnd);

    static void Save(const std::shared_ptr<Buffer>& buffer,
                     const std::string& trackName);

private:
    int32_t mSamplerate;
    int32_t mChannels;
    int64_t mFrames;

    SNDFILE* mFile;

    void LoadFromFile(const std::string& file);
};

#endif // SAMPLETRACK_H
