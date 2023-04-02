#ifndef BUFFER_H
#define BUFFER_H
#include <stdint.h>
#include <vector>
#include <assert.h>

class Buffer
{
public:
    Buffer(int32_t nChannels, int64_t nSamples, int32_t samplerate);

    inline int64_t GetNumSamples()
    {
        return mSamples;
    }

    inline int32_t GetNumChannels()
    {
        return mChannels;
    }

    inline int32_t GetSempleRate()
    {
        return mSamplerate;
    }

    std::vector<float>& Data()
    {
        return mBuffer;
    }

    const std::vector<float>& Data() const
    {
        return mBuffer;
    }

private:
    int64_t mSamples;
    int32_t mSamplerate;
    int32_t mChannels;

    std::vector<float> mBuffer;
};

#endif // BUFFER_H
