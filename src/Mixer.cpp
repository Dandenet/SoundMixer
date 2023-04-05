#include "Mixer.hpp"
#include "Buffer.hpp"

Mixer::Mixer()
{

}

void Mixer::Attach(const std::shared_ptr<Buffer>& buffer)
{
    mBuffers.push_back(buffer);
}

void Mixer::Detach(const std::shared_ptr<Buffer>& buffer)
{
    mBuffers.remove(buffer);
}

std::shared_ptr<Buffer> Mixer::Mix()
{
    int32_t numChannels = 0;
    int64_t numSamples  = 0;
    int32_t sampleRate  = 0;

    for (auto& buffer : mBuffers) {
        numChannels = std::max(numChannels, buffer->GetNumChannels());
        numSamples  = std::max(numSamples, buffer->GetNumSamples());
        sampleRate  = buffer->GetSempleRate(); // Mix with different sample rates doesn't support
    }

    auto mixBuffer = std::make_shared<Buffer>(numChannels, numSamples, sampleRate);
    auto& mixBufferData = mixBuffer->Data();

    auto it = mBuffers.begin();
    if (it == mBuffers.end())
        return {};

    size_t bufferSize = (*it)->Data().size() * sizeof(float);
    memcpy(mixBufferData.data(), (*it)->Data().data(), bufferSize);

    /* Mixes two track with a linear algorithm.
     * Adds a sample of the first track to a sample of the second track
     * It then normalize the amlitude, and goes to the next track
    */
    for (it = std::next(mBuffers.begin()); it != mBuffers.end(); ++it)
    {
        auto& currentBufferData = (*it)->Data();
        for (size_t i = 0; i < currentBufferData.size(); ++i)
            mixBufferData[i]+= currentBufferData[i];

        // find the maximum absolute amplitude
        float maxAbsAmpl = 0.f;
        for (size_t i = 0; i < mixBufferData.size(); ++i)
            maxAbsAmpl = std::max(std::abs(mixBufferData[i]), maxAbsAmpl);

        // normalize the mix buffer amplitude
        for (size_t i = 0; i < mixBufferData.size(); ++i)
            maxAbsAmpl /= maxAbsAmpl;
    }

    return mixBuffer;
}
