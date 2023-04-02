find_package(SndFile CONFIG REQUIRED)

SET(ROOT_SOURCE SampleTrack.cpp
                Buffer.cpp)

set(HEADER_LIST "${SoundMixer_SOURCE_DIR}/include/SampleTrack.hpp"
                "${SoundMixer_SOURCE_DIR}/include/Buffer.hpp")

add_library(SoundMixerLib ${ROOT_SOURCE} ${HEADER_LIST})
target_link_libraries(SoundMixerLib PRIVATE SndFile::sndfile)
target_include_directories(SoundMixerLib PUBLIC ../include)

add_executable(SoundMixer main.cpp)
target_link_libraries(SoundMixer SoundMixerLib)
