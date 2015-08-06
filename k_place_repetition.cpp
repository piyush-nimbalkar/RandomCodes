#include <iostream>
#include <map>

using namespace std;


bool find_duplicates(int *arr, int size, int k)
{
    map<int, int> hash;

    for (int i = 0; i < size; i++) {
        // cout << arr[i] << "  " << i << endl;
        if ((hash.count(arr[i]) > 0) && (i - hash[arr[i]] <= k))
            return true;
        hash[arr[i]] = i;
    }
    return false;
}


int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 3, 4, 3, 6};
    cout << (find_duplicates(arr, 6, 2) ? "true" : "false") << endl;
    return 0;
}
