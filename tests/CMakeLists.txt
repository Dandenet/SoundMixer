
find_package (Boost COMPONENTS unit_test_framework REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

enable_testing ()

add_executable (SoundMixerTest SampleTrackTest.cpp)
target_link_libraries (SoundMixerTest SoundMixerLib ${Boost_LIBRARIES})
add_test (SoundMixerTest ${CMAKE_CURRENT_SOURCE_DIR})
