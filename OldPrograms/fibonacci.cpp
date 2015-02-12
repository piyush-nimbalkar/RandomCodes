#include <iostream>

using namespace std;

int nth_fib_rec(int n)
{
    if (n == 1)
        return (n-1);
    return nth_fib_rec(n-1) + nth_fib_rec(n-2);
}

int nth_fib_memo(int n, int *memo)
{
    if (n == 1 || n == 2)
        return memo[n];

    memo[n] = nth_fib_memo(n-1, memo) + memo[n-2];
    return memo[n];
}

int nth_trib_rec(int n)
{
    if (n == 1 || n == 2)
        return n-1;
    if (n == 3)
        return 1;
    return nth_trib_rec(n-1) + nth_trib_rec(n-2) + nth_trib_rec(n-3);
}

int nth_trib_memo(int n, int *memo)
{
    if (n == 1 || n == 2 || n == 3)
        return memo[n];

    memo[n] = nth_trib_memo(n-1, memo) + memo[n-2] + memo[n-3];
    return memo[n];
}

int nth_trib(int n)
{
    int a = 0, b = 1, c = 1, d;

    if (n == 1 || n == 2)
        return n-1;
    if (n == 3)
        return 1;

    n -= 3;
    while (n > 0) {
        d = a + b + c;
        a = b;
        b = c;
        c = d;
        n--;
    }
    return d;
}

int main(int argc, char *argv[])
{
    int arr[10] = {0, 0, 1, 1};
    int n;
    cin >> n;

    // cout << nth_fib_rec(n) << endl;
    // cout << nth_fib_memo(n, arr) << endl;
    // cout << nth_trib_rec(n) << endl;
    // cout << nth_trib(n) << endl;
    cout << nth_trib_memo(n, arr) << endl;
    for (int i = 1; i <= n; ++i)
        cout << arr[i] << "  ";

    return 0;
}
