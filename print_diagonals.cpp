#include <iostream>

using namespace std;


class Matrix
{
    int size;
    int **matrix;
public:
    Matrix() { }
    Matrix(int size);
    void get_input();
    void print_diagonals();
    ~Matrix();
};

Matrix :: Matrix(int s)
{
    size = s;

    matrix = new int *[size];
    for (int i = 0; i < size; i++)
        matrix[i] = new int[size];
}

Matrix :: ~Matrix()
{
    for (int i = 0; i < size; i++)
        delete matrix[i];
    delete matrix;
}

void Matrix :: get_input()
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            cin >> matrix[i][j];
}

void Matrix :: print_diagonals()
{
    int i, j, k;

    cout << "Diagonals:\n";
    for (i = 0; i < size; i++) {
        for (j = i, k = 0; j >= 0; j--, k++)
            cout << matrix[j][k] << " ";
        cout << endl;
    }
    for (i = 1; i < size; i++) {
        for (j = i, k = size-1; j < size; j++, k--)
            cout << matrix[k][j] << " ";
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    int size;
    cin >> size;
    Matrix m(size);
    m.get_input();
    m.print_diagonals();
    return 0;
}
