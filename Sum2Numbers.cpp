#include <iostream>
#include <thread>

void sum(int num1, int num2){
    std::cout <<num1 + num2;
}
int main(){

    std::thread sumthread(sum,12,12);
    sumthread.join();
    return 0;
}