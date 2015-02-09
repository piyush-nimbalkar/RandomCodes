#include <iostream>

using namespace std;


int main(int argc, char *argv[])
{
    int N, L, B;

    cout << "Enter (N, L, B): ";
    cin >> N >> L >> B;

    int number_of_glasses = 0;
    int remaining_beer = B * 750;
    float result;

    for (int level = 1; level <= L; level++) {
        number_of_glasses += level;
        if (remaining_beer > number_of_glasses*250) {
            remaining_beer -= number_of_glasses*250;
        } else {
            result = (float)remaining_beer / number_of_glasses;
            remaining_beer = 0;
        }
    }

    cout << result << endl;
    return 0;
}
