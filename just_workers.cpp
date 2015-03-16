#include <iostream>

using namespace std;

void divide_work(int *arr, int size, int k)
{
    int i, j, p;
    int min_sum, cur_sum;
    int **memo = new int*[k];

    for (i = 0; i < k; i++)
        memo[i] = new int[size];

    memo[0][size-1] = arr[size-1];
    for (i = size-2; i >= 0; i--)
        memo[0][i] = memo[0][i+1] + arr[i];

    for (i = 1; i < k; i++) {
        for (j = 0; j < size - i; j++) {
            min_sum = 9999;
            cur_sum = 0;
            for (p = j; p < size - i; p++) {
                cur_sum += arr[p];
                min_sum = min(min_sum, max(cur_sum, memo[i-1][p+1]));
            }
            cout << min_sum << " " << i << " " << j << endl;
            memo[i][j] = min_sum;
        }
    }

    for (i = 0; i < k; i++) {
        for (j = 0; j < size; j++)
            cout << memo[i][j] << "  ";
        cout << endl;
    }
    cout << endl;
    cout << memo[k-1][0] << endl;
}


int main(int argc, char *argv[])
{
    int size = 9;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // vector<int> arr(array, array+size);

    divide_work(array, size, 4);
    return 0;
}
