#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include "Semaphore.hpp"
#include <array>

class RingBuffer {

    static constexpr int  RING_SIZE = 20;
    std::array<char,RING_SIZE> m_buff;
    int m_w{0};
    int m_r{0};
    Semaphore m_free{RING_SIZE};
    Semaphore m_taken{0};
    std::mutex m_mut;
public:
    RingBuffer()=default;
    void write(const char c);
    char read();
};

#endif