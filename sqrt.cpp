#include <iostream>
#include <cmath>

using namespace std;


double square_root(double num)
{
    double start, mid, end;
    double old_mid = 0;
    double mid_sq;

    if (num < 1) {
        start = num;
        end = 1.0;
    } else {
        start = 1;
        end = num;
    }
    mid = (start + end) / 2;

    while (abs(old_mid - mid) > 0.00001) {
        mid_sq = mid * mid;
        cout << mid << endl;
        if (mid_sq < num) {
            start = mid;
        } else {
            end = mid;
        }
        old_mid = mid;
        mid = start + (end - start) / 2;
    }

    return old_mid;
}


int main(int argc, char *argv[])
{
    cout << square_root(16.0144) << endl;
    return 0;
}
