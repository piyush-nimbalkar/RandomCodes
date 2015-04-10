#include <iostream>

using namespace std;

int kth_largest(int *a, int *b, int index1, int index2, int k)
{
    if (index1 < 0)
        return b[index2 - k + 1];
    if (index2 < 0)
        return a[index1 - k + 1];
    if (k == 1)
        return max(a[index1], b[index2]);

    int new_index1 = index1 - k/2;
    int new_index2 = index2 - k/2;
    int first  = new_index1 < -1 ? a[0] : a[new_index1 + 1];
    int second = new_index2 < -1 ? b[0] : b[new_index2 + 1];

    int result;
    if (first >= second)
        result = kth_largest(a, b, new_index1, index2, k - (new_index1 < 0 ? index1+1 : k/2));
    else
        result = kth_largest(a, b, index1, new_index2, k - (new_index2 < 0 ? index2+1 : k/2));
    return result;
}

int main(int argc, char *argv[])
{
    int size1 = 4, size2 = 6;
    int a[] = {1, 13, 26, 30};
    int b[] = {2, 4, 15, 18, 28, 35};

    cout << "Kth Largest: " << kth_largest(a, b, size1-1, size2-1, 10) << endl;
    cout << "Kth Largest: " << kth_largest(a, b, size1-1, size2-1, 9) << endl;
    cout << "Kth Largest: " << kth_largest(a, b, size1-1, size2-1, 8) << endl;
    cout << "Kth Largest: " << kth_largest(a, b, size1-1, size2-1, 7) << endl;
    cout << "Kth Largest: " << kth_largest(a, b, size1-1, size2-1, 6) << endl;
    cout << "Kth Largest: " << kth_largest(a, b, size1-1, size2-1, 5) << endl;
    cout << "Kth Largest: " << kth_largest(a, b, size1-1, size2-1, 4) << endl;
    cout << "Kth Largest: " << kth_largest(a, b, size1-1, size2-1, 3) << endl;
    cout << "Kth Largest: " << kth_largest(a, b, size1-1, size2-1, 2) << endl;
    cout << "Kth Largest: " << kth_largest(a, b, size1-1, size2-1, 1) << endl;

    return 0;
}
