#include <iostream>
#include <thread>

int main(int argc, char const *argv[])
{
    std::thread t1{[]()
                   {
                       std::this_thread::sleep_for(std::chrono::seconds(3));
                       std::cout << "1"<<std::endl;
                   }};

    std::thread t2{[&t1]()
                   {
                       t1.join();
                       std::cout << "2"<<std::endl;
                   }};

    std::thread t3{[&t2]()
                   {
                       t2.join();
                       std::cout << "3"<<std::endl;
                   }};


    t3.join();
    return 0;
}
