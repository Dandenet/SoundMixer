#include "Buffer.hpp"
#include <cassert>

Buffer::Buffer(int32_t nChannels, int64_t nSamples, int32_t samplerate) :
    mSamples(nSamples),   mSamplerate(samplerate),
    mChannels(nChannels), mBuffer(nChannels * nSamples)
{
}


