
find_package (Boost COMPONENTS unit_test_framework REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

enable_testing ()

add_executable (SampleTrackTest SampleTrackTest.cpp)
target_link_libraries (SampleTrackTest SoundMixerLib ${Boost_LIBRARIES})
add_test (SoundMixerTest ${CMAKE_CURRENT_SOURCE_DIR})

add_executable (MixerTest MixerTest.cpp)
target_link_libraries (MixerTest SoundMixerLib ${Boost_LIBRARIES})
add_test (MixerTest ${CMAKE_CURRENT_SOURCE_DIR})
