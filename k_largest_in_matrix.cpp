#include<iostream>
using namespace std;

const int ROW = 4;
const int COL = 4;
const int STOP = -1;

int main() {

    int i, j, k;
    int matrix[ROW][COL] =  {{ 5,  7,  8,  9 },
                             { 6,  9, 10, 13 },
                             { 7, 11, 12, 15 },
                             { 8, 13, 16, 17 }};

    cout << "Enter k: ";
    cin >> k;

    cout << endl;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
    cout << endl;

    for (int p = 0; p < k-1; p++) {
        for (i = ROW-1, j = COL-1; ; ) {

            if (j == 0 || (j > 0 && matrix[i][j-1] == STOP)) {
                if (i <= 0 || matrix[i-1][j] == STOP) {
                    matrix[i][j] = STOP;
                    break;
                }
                matrix[i][j] = matrix[i-1][j];
                i--;
                continue;
            }

            if (i == 0 || (i > 0 && matrix[i-1][j] == STOP)) {
                if (j <= 0 || matrix[i][j-1] == STOP) {
                    matrix[i][j] = STOP;
                    break;
                }
                matrix[i][j] = matrix[i][j-1];
                j--;
                continue;
            }

            if (matrix[i][j-1] > matrix[i-1][j]) {
                matrix[i][j] = matrix[i][j-1];
                j--;
            } else {
                matrix[i][j] = matrix[i-1][j];
                i--;
            }
        }
    }

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
    return 0;
}
