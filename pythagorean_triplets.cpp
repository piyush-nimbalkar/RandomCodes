#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;


class Array
{
    int *array;
    int length;
public:
    Array() { array = NULL; length = 0; }
    Array(int *, int);
    void print_pythagorean_triplets();
    ~Array() { delete(array); }
};

Array :: Array(int *arr, int size)
{
    length = size;
    array = new int[length];
    for (int i = 0; i < length; i++)
        array[i] = arr[i];
}

void Array :: print_pythagorean_triplets()
{
    map<int, bool> squares;

    for (int k = 0; k < length; k++)
        squares[array[k] * array[k]] = true;

    for (map<int, bool>::iterator i = squares.begin(); i != squares.end(); i++)
        for (map<int, bool>::iterator j = i; j != squares.end(); j++)
            if (squares.count(i->first + j->first) > 0)
                cout << sqrt(i->first) << "\t" << sqrt(j->first) << "\t" << sqrt(i->first + j->first) << endl;
}

// void print_pythagorean_triplets()
// {
    // int arr[] = {2, 3, 4, 6, 7, 12, 13, 15, 5, 17, 14, 22};
    // vector<int> array(arr, arr+12);
    // map<int, bool> squares;

    // for (int k = 0; k < 12; k++)
        // squares[array[k] * array[k]] = true;

    // for (map<int, bool>::iterator i = squares.begin(); i != squares.end(); i++)
        // for (map<int, bool>::iterator j = i; j != squares.end(); j++)
            // if (squares.count(i->first + j->first) > 0)
                // cout << sqrt(i->first) << "\t" << sqrt(j->first) << "\t" << sqrt(i->first + j->first) << endl;
// }


int main(int argc, char *argv[])
{
    int arr[] = {2, 3, 4, 6, 7, 12, 13, 15, 5, 17, 14, 22};
    Array a(arr, 12);
    a.print_pythagorean_triplets();
    // print_pythagorean_triplets();
    return 0;
}
