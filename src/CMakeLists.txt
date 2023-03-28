find_package(SndFile CONFIG REQUIRED)
add_executable(SoundMixer main.cpp)
target_link_libraries(SoundMixer PRIVATE SndFile::sndfile)
