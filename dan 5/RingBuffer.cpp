#include "RingBuffer.hpp"

void RingBuffer::write(const char c){
    m_free.wait();
    std::lock_guard<std::mutex> l(m_mut);
    m_buff[m_w]=c;
    m_w = (m_w+1)%m_buff.size();
    m_taken.singal();
}


char RingBuffer::read(){
    m_taken.wait();
    std::lock_guard<std::mutex> l(m_mut);
    char c = m_buff[m_r];
    m_r = (m_r+1)%m_buff.size();
    m_free.singal();
    return c;
}