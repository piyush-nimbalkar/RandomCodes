#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 20;
typedef vector<vector<int> > vvector;

void increasing_subsequences(int *array, int size)
{
    int i, j;
    vvector::iterator it;
    vvector master;

    for (i = 0; i < size; i++) {
        for (it = master.begin(); it != master.end(); it++) {
            if (it->back() < array[i])
                it->push_back(array[i]);
        }
        vector<int> temp;
        temp.push_back(array[i]);
        master.push_back(temp);
    }

    cout << "\nIncreasing subsequences:" << endl;
    for (it = master.begin(); it != master.end(); it++) {
        for (vector<int>::iterator j = it->begin(); j != it->end(); j++)
            cout << *j << " ";
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    int array[SIZE], size;

    cout << "Enter size: ";
    cin >> size;

    for (int i = 0; i < size; ++i)
        cin >> array[i];

    increasing_subsequences(array, size);

    return 0;
}
