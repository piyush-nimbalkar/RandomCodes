#include <iostream>
#include <thread>

// using namespace std;

void stars()
{
    for (int i = 0; i < 100; i++)
        std::cout << "*";
}

void dashes()
{
    for (int i = 0; i < 100; i++)
        std::cout << "-";
}


int main(int argc, char *argv[])
{
    std::thread t1(stars);
    std::thread t2(dashes);

    t1.join();
    t2.join();
}
