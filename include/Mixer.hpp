#ifndef MIXER_H
#define MIXER_H

#include <list>
#include <memory>


class Buffer;

class Mixer {

public:
    Mixer();

    void Attach(const std::shared_ptr<Buffer>& buffer);
    void Detach(const std::shared_ptr<Buffer>& buffer);

    std::shared_ptr<Buffer> Mix();

private:
    std::list<std::shared_ptr<Buffer>> mBuffers;
};

#endif // MIXER_H
