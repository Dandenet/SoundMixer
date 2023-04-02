#define BOOST_TEST_MODULE SoundMixerTest
#include <boost/test/unit_test.hpp>
#include <SampleTrack.hpp>
#include <fstream>



BOOST_AUTO_TEST_SUITE(SampleTrack_Test)

BOOST_AUTO_TEST_CASE(OpenTrackTest)
{
    BOOST_CHECK_THROW(SampleTrack(""), std::exception);
    BOOST_CHECK_NO_THROW(SampleTrack("test.wav"));
}

BOOST_AUTO_TEST_CASE(TrackDurationTest)
{
    SampleTrack sampleTrack("test.wav");
    BOOST_CHECK_EQUAL(sampleTrack.GetDuration(), 153);
}

BOOST_AUTO_TEST_CASE(TrackBufferTest)
{
    SampleTrack sampleTrack("test.wav");
    Buffer buffer = sampleTrack.GetBuffer();
    auto& data = buffer.Data();

    std::ifstream file("data");

    for (int64_t i = 0; !file.eof(); ++i) {
        float value;
        file >> value;

        BOOST_REQUIRE_EQUAL(data[i], value);
    }

}

BOOST_AUTO_TEST_CASE(TrackBufferTimeTest)
{
    SampleTrack sampleTrack("test.wav");

    int32_t timeStart = 10;
    int32_t timeEnd = 20;

    Buffer buffer1 = sampleTrack.GetBuffer();
    Buffer buffer2 = sampleTrack.GetBuffer(timeStart, timeEnd);

    auto& data1 = buffer1.Data();
    auto& data2 = buffer2.Data();

    int64_t frameStart = timeStart * buffer1.GetNumChannels() * buffer1.GetSempleRate();
    int64_t frameEnd   = timeEnd   * buffer1.GetNumChannels() * buffer1.GetSempleRate();

    for (int64_t i = frameStart, j = 0; i < frameEnd; ++i, ++j)
    {
        BOOST_REQUIRE_EQUAL(data1[i], data2[j]);
    }

}

BOOST_AUTO_TEST_SUITE_END()
