#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <mutex>
#include <condition_variable>

class Semaphore {
    int m_s = 0;
    std::mutex m_mut;
    std::condition_variable m_cv;
public:
    Semaphore() = default;
    Semaphore(int x):m_s(x){}

    void singal(){
        std::unique_lock<std::mutex> lock(m_mut);
        m_s+=1;
        m_cv.notify_one();
    }

    void wait(){
        std::unique_lock<std::mutex> lock(m_mut);
        m_cv.wait(lock,[this](){return m_s!=0;});
        m_s-=1;
    }
};

#endif