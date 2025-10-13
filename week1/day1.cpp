#include <iostream>
#include <cstdint>
#include <sys/types.h>

struct Header {
    uint32_t riff;
    uint32_t wave;
    uint16_t fmt;

    Header(uint32_t r, uint32_t w, uint16_t f) : riff(r), wave(w), fmt(f) {}
};

int main() {
    Header h1(1, 2, 3);
    std::cout << std::hex << h1.riff << " " << h1.wave << " " << h1.fmt << std::endl;
    return 0;
}