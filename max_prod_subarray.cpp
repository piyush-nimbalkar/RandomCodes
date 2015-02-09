#include <iostream>

using namespace std;


int main(int argc, char *argv[])
{
    // int arr[] = {2, 3, 0 , -6, 4, -3, -10, 0, 100};
    // int length = 9;
    int arr[] = {1, 2, -1, 4, 0, 5, -6, -5, -6, 2, 0, 3, -4, 3, -2, 4, -3};
    int length = 17;
    int prod = 1, max = 1, global_max = 1;

    for (int j = 0; j < length; j++) {
        prod = 1;
        for (int i = j; i < length; i++) {
            prod = prod * arr[i];
            if (prod > max)
                max = prod;
            if (prod == 0)
                break;
        }
    }

    cout << max << endl;
    return 0;
}
