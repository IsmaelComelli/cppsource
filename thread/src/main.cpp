#include <iostream>
#include <thread>
#include <chrono>

bool bFinish = false;

void funcThread()
    {
    while (!bFinish)
        {
        std::cout << "Working..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }

int main(int argc, char **argv)
    {
    std::thread T1 (funcThread);

    std::cin.get();
    bFinish = true;
    
    T1.join();

    return 0;
    }