#include <SampleTrack.hpp>
#include <Buffer.hpp>
#include <Mixer.hpp>

#include <iostream>

int main()
{
    try {
        SampleTrack track1("test.wav");
        SampleTrack track2("test2.wav");

        Mixer mixer;

        mixer.Attach(track1.GetBuffer());
        mixer.Attach(track2.GetBuffer());

        SampleTrack::Save(mixer.Mix(), "save.wav");

    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
