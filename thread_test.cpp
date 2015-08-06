#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void print(char c)
{
    mtx.lock();
    for (int i = 0; i < 100; i++)
        cout << c;
    mtx.unlock();
}

void print_with_guard(char c)
{
    lock_guard<mutex> lck(mtx);
    for (int i = 0; i < 100; i++)
        cout << c;
}

int main(int argc, char *argv[])
{
    thread t1(print_with_guard, '-');
    thread t2(print_with_guard, '*');

    t1.join();
    t2.join();

    return 0;
}
