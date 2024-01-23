#include <iostream>
#include <thread>

void helloFunction(){
    std::cout << "Hello World I am running on thread";
}
int main(){
    
    std::thread thread1(helloFunction);
    std::cout << "I am main thread";
    return 0;
}