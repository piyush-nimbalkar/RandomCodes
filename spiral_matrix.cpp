#include <iostream>
#include <iomanip>

using namespace std;

const int N = 5;

void print_spiral(int matrix[][N])
{
    int i;

    cout << "\nSpiral Matrix: ";
    for (int depth = 0; depth < (N+1)/2; depth++) {
        for (i = depth; i < (N-depth); i++)
            cout << matrix[depth][i] << "  ";

        for (i = depth+1; i < (N-depth); i++)
            cout << matrix[i][N-depth-1] << "  ";

        for (i = (N-depth-2); i >= depth; i--)
            cout << matrix[N-depth-1][i] << "  ";

        for (i = (N-depth-2); i > depth; i--)
            cout << matrix[i][depth] << "  ";
    }
    cout << endl;
}

void transpose(int matrix[][N])
{
    int i, j;

    for (i = 0; i < N; ++i) {
        for (j = i+1; j < N; ++j) {
            matrix[i][j] = matrix[i][j] ^ matrix[j][i];
            matrix[j][i] = matrix[i][j] ^ matrix[j][i];
            matrix[i][j] = matrix[i][j] ^ matrix[j][i];
        }
    }
}

int rotate_right(int matrix[][N])
{
    int i, j;

    transpose(matrix);
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N/2; ++j) {
            matrix[i][j]     = matrix[i][j] ^ matrix[i][N-j-1];
            matrix[i][N-j-1] = matrix[i][j] ^ matrix[i][N-j-1];
            matrix[i][j]     = matrix[i][j] ^ matrix[i][N-j-1];
        }
    }
}


int main(int argc, char *argv[])
{
    int i, j, num = 1;
    int matrix[N][N];

    for (i = 0; i < N; ++i)
        for (j = 0; j < N; ++j)
            matrix[i][j] = num++;

    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j)
            cout << setw(4) << matrix[i][j];
        cout << endl;
    }

    print_spiral(matrix);
    rotate_right(matrix);

    cout << "\nRotate Right:" << endl;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j)
            cout << setw(4) << matrix[i][j];
        cout << endl;
    }

    return 0;
}
