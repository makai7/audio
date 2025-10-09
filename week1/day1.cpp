#include <iostream>
#include <cstdint>
int main() {
    struct Header {
        uint32_t riff;
        uint32_t wave;
        uint16_t fmt;   
    };
    Header header;

}