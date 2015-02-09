#include <iostream>

using namespace std;


void max_subarray(int *array, int size)
{
    int sum = 0, start = 0;
    int max_start = 0, max_end = 0, max_sum = -99999;

    for (int i = 0; i < size; i++) {
        sum += array[i];
        if (sum > max_sum) {
            max_sum = sum;
            max_start = start;
            max_end = i;
        }
        if (sum <= 0) {
            sum = 0;
            start = i+1;
        }
    }

    cout << "\nMax Subarray: ";
    for (int i = max_start; i <= max_end; i++)
        cout << array[i] << " ";
    cout << "\nSum: " << max_sum << endl;
}

int main(int argc, char *argv[])
{
    int array[50], size;

    cout << "Enter size: ";
    cin >> size;

    for (int i = 0; i < size; i++)
        cin >> array[i];

    max_subarray(array, size);

    return 0;
}
