#include <iostream>
#include <list>

using namespace std;

// Just get the max length of the subsequence
void dp_mic(int *array, int size)
{
    int i, j;
    int *memo = new int[size];

    for (i = 0; i < size; i++)
        memo[i] = 1;

    for (i = 1; i < size; i++)
        for (j = 0; j < i; j++)
            if (array[i] > array[j] && memo[i] < memo[j] + 1)
                memo[i] = memo[j] + 1;

    int max = memo[0];
    for (i = 1; i < size; i++)
        if (memo[i] > max)
            max = memo[i];

    delete[] memo;

    cout << "Length : " << max << endl;
}

int rec_mic(int *array, int size, int index, int maximum)
{
    if (index == size)
        return 0;

    int inc = 0;
    if (array[index] >= maximum)
        inc = rec_mic(array, size, index+1, array[index]);
    int exc = rec_mic(array, size, index+1, maximum);

    return max(exc, inc+1);
}

list<int> rec_mic_list(int *array, int size, int index, int maximum)
{
    list<int> temp;
    if (index == size)
        return temp;

    list<int> inc;
    if (array[index] >= maximum)
        inc = rec_mic_list(array, size, index+1, array[index]);
    inc.push_front(array[index]);

    list<int> exc = rec_mic_list(array, size, index+1, maximum);

    if (inc.size() > exc.size())
        return inc;
    else
        return exc;
}

void mic(int *array, int size)
{
    list<int> result = rec_mic_list(array, size, 0, -9999);

    cout << "Length : " << rec_mic(array, size, 0, -9999) << endl;
    for (list<int>::iterator it = result.begin(); it != result.end(); it++)
        cout << *it << "  ";
    cout << endl;
}

int main(int argc, char *argv[])
{
    int size = 9;
    int array[9] = {10, 22, 9, 23, 21, 50, 41, 60, 80};

    // mic(array, size);
    dp_mic(array, size);

    return 0;
}
