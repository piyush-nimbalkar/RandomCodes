#include <iostream>

using namespace std;

void bubble_sort(int array[], int size)
{
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < (size - i); j++) {
            if (array[j] > array[j + 1]) {
                array[j] = array[j] ^ array[j + 1];
                array[j + 1] = array[j] ^ array[j + 1];
                array[j] = array[j] ^ array[j + 1];
            }
        }
    }
}


int partition(int array[], int start, int end)
{
    int pivot = array[start];
    int i = start + 1, j = end;
    while (i < j) {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i < j) {
            array[i] = array[i] ^ array[j];
            array[j] = array[i] ^ array[j];
            array[i] = array[i] ^ array[j];
        }
    }
    array[start] = array[j];
    array[j] = pivot;
    return j;
}

void quick_sort(int array[], int start, int end)
{
    if (start < end) {
        int pivot = partition(array, start, end);
        quick_sort(array, start, pivot - 1);
        quick_sort(array, pivot + 1, end);
    }
}


void merge(int array[], int start, int mid, int end)
{
    int i, j = mid + 1, k;
    int first_half[30];

    for (i = start; i <= mid; i++)
        first_half[i] = array[i];

    i = k = start;
    while (i <= mid && j <= end) {
        if (first_half[i] <= array[j])
            array[k++] = first_half[i++];
        else
            array[k++] = array[j++];
    }

    while (i <= mid)
        array[k++] = first_half[i++];
}

void rec_merge_sort(int array[], int start, int end)
{
    if (start < end) {
        int mid = (start + end) / 2;
        rec_merge_sort(array, start, mid);
        rec_merge_sort(array, mid + 1, end);
        merge(array, start, mid, end);
    }
}

void display(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << "  ";
    cout << endl;
}

int main(int argc, char *argv[])
{
    int array[30], size;
    cout << "Number of elements: ";
    cin >> size;
    for (int i = 0; i < size; i++)
        cin >> array[i];
    // bubble_sort(array, size);
    // rec_quick_sort(array, 0, size - 1);
    rec_merge_sort(array, 0, size - 1);
    display(array, size);
    return 0;
}
