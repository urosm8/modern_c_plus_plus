#include <iostream>
#include<thread>
#include "RingBuffer.hpp"


int main(int argc, char const *argv[])
{
    RingBuffer r1{},r2{};

    std::thread ulaz{[&r1](){
        while (true)
        {
            char c;
            std::cin>>c;
            r1.write(c);
        }
        
    }};
    std::thread obrada{[&r1,&r2](){
        while (true)
        {
            char c = r1.read();
            r2.write(std::toupper(c));
        }
        
    }};

    std::thread izlaz{[&r2](){
        while (true)
        {
            std::cout<<r2.read()<<std::endl;
        }
        
    }};


    ulaz.join();
    obrada.join();
    izlaz.join();
    return 0;
}
