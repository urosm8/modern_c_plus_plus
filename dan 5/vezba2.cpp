#include <iostream>
#include <thread>
#include <mutex>

int i1 = 0, i2 = 0;
std::mutex m1, m2;

void writer()
{
    while (true)
    {
        std::lock(m1, m2);

        if ((i1 == 0 && i2 == 0) || (i1 == 5 && i2 == 6))
        {
            i1 = 1;
            i2 = 2;
        }
        else
        {
            i1 += 2;
            i2 += 2;
        }
        m1.unlock();
        m2.unlock();

        std::this_thread::sleep_for(std::chrono::milliseconds((int)(1.*std::rand()/RAND_MAX+1000)));
    }
}

void reader()
{
    while (true)
    {
        std::lock(m1, m2);

        if (i1 != 0)
            std::cout << i1 + i2 << std::endl;

        m1.unlock();
        m2.unlock();

        std::this_thread::sleep_for(std::chrono::milliseconds((int)(1.*std::rand()/RAND_MAX+1000)));
    }
}

int main(int argc, char const *argv[])
{
    std::srand(std::time(0));
    std::thread wt(writer);
    std::thread rt(reader);

    wt.join();
    rt.join();
    return 0;
}
