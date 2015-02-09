#include <iostream>

using namespace std;

int nth_fib(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    return nth_fib(n - 1) + nth_fib(n - 2);
}


int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    cout << nth_fib(n);
    return 0;
}
