
#include <bit>
#include <iostream>
#include <string>
#include <atomic>
#include <thread>

#include <list>

std::atomic<int> flag;
std::list<std::thread> threadList; 

//
int main(){
    std::cout << "hello" << std::endl;
    while(flag < 10)
    {
        threadList.push_back(std::thread ([]{
            std::cout << flag++ << std::endl;
        }));
    }
    for(auto &&thread : threadList)
    {
        thread.join();
    }
    return 0;
}