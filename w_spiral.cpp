#include<iostream>
using namespace std;
#define MAX 5


void print_spiral(int arr[][MAX]) {

    for (int depth = 0; depth < (MAX/2 + MAX%2); depth++) {

        // horizontal left to right
        for(int i = depth; i < MAX - depth; i++) {
            cout << "\t" << arr[depth][i];
        }
        // vertical top to bottom
        for(int i = depth+1; i < MAX - depth; i++) {
            cout << "\t" << arr[i][MAX-1-depth];
        }
        // horizontal right to left
        for(int i = depth+1; i < MAX - depth; i++) {
            cout << "\t" << arr[MAX-1-depth][MAX-1-i];
        }
        //vertical bottom to top
        for(int i = depth+1; i < MAX - depth -1; i++) {
            cout << "\t" << arr[MAX-1-i][depth];
        }

    }
    cout << endl;

}


int main() {
    int arr[MAX][MAX], i, j, num;
    num = 1;

    for (i=0; i<MAX; i++) {
        for (j=0; j<MAX; j++) {
            arr[i][j] = num++;
        }
    }


    cout << endl << "Given array:" << endl;
    for (i=0; i<MAX; i++) {
        for (j=0; j<MAX; j++) {
            cout << "\t" << arr[i][j];
        }
        cout << endl;
    }

    cout << endl << "Spiral order for given array:" << endl;
    print_spiral(arr);

}
