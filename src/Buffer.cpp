#include "Buffer.hpp"
#include <cassert>

Buffer::Buffer(int32_t nChannels, int64_t nSamples, int32_t samplerate) :
    mSamples(nSamples),   mSamplerate(samplerate),
    mChannels(nChannels), mBuffer(nChannels * nSamples)
{
}

void Buffer::Normalize()
{
    // find the maximum absolute amplitude
    float maxAbsAmpl = 0.f;
    for (size_t i = 0; i < mBuffer.size(); ++i)
        maxAbsAmpl = std::max(std::abs(mBuffer[i]), maxAbsAmpl);

    // normalize the mix buffer amplitude
    for (size_t i = 0; i < mBuffer.size(); ++i)
        mBuffer[i] /= maxAbsAmpl;

}


