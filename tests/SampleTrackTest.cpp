#define BOOST_TEST_MODULE SoundMixerTest
#include <boost/test/unit_test.hpp>
#include <SampleTrack.hpp>



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

BOOST_AUTO_TEST_SUITE_END()
