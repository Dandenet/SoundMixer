#define BOOST_TEST_MODULE MixerTest
#include <boost/test/unit_test.hpp>
#include <cmath>
#include <Buffer.hpp>
#include <Mixer.hpp>

constexpr float eps = 1.e-7f;

BOOST_AUTO_TEST_SUITE(Mixer_Test)

BOOST_AUTO_TEST_CASE(MixBuffers)
{
    const int32_t numChannels = 2;
    const int64_t numSampels1 = 5;
    const int64_t numSampels2 = 4;
    const int64_t sampleRate  = 1;

    std::shared_ptr<Buffer> buffer1( new Buffer(numChannels, numSampels1, sampleRate));
    std::shared_ptr<Buffer> buffer2( new Buffer(numChannels, numSampels2, sampleRate));

    float array1[numChannels * numSampels1] = {
        0.f,    0.f,    0.1f,   0.1f, 0.2f,
        0.1f,   0.1f,   0.2f,   1.0f, 1.0f,
    };

    float array2[numChannels * numSampels2] = {
        0.f,    0.f,    0.1f,   0.1f, 0.2f,
        0.1f,   0.1f,   0.2f,
    };

    float array3[numChannels * numSampels1] = {
        0.f,    0.f,    0.2f,   0.2f, 0.4f,
        0.2f,   0.2f,   0.4f,   1.0f, 1.0f,
    };

    memmove(buffer1->Data().data(), &array1, sizeof(array1));
    memmove(buffer2->Data().data(), &array2, sizeof(array2));

    Mixer mixer;
    mixer.Attach(buffer1);
    mixer.Attach(buffer2);

    auto resBuffer = mixer.Mix();
    auto& result = resBuffer->Data();

    for (int32_t i = 0; i < numChannels * numSampels1; ++i)
    {
        BOOST_REQUIRE_LE(std::abs(result[i] - array3[i]), eps);
    }
}


BOOST_AUTO_TEST_SUITE_END()
