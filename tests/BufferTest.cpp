#define BOOST_TEST_MODULE BufferTest
#include <boost/test/unit_test.hpp>
#include <Buffer.hpp>

BOOST_AUTO_TEST_SUITE(BufferTest)

BOOST_AUTO_TEST_CASE(OpenTrackTest)
{
    BOOST_CHECK_THROW(SampleTrack(""), std::exception);
    BOOST_CHECK_NO_THROW(SampleTrack("test.wav"));
}

BOOST_AUTO_TEST_SUITE_END()
