#include <iostream>

using namespace std;


class NQueens
{
    int size;
    int **matrix;
public:
    NQueens() { }
    NQueens(int);
    int solve(int);
    int is_position_available(int, int);
    void display();
};

NQueens :: NQueens(int n)
{
    int i, j;
    size = n;

    matrix = new int *[size];
    for (i = 0; i < size; i++)
        matrix[i] = new int[size];

    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            matrix[i][j] = 0;
}

bool NQueens :: is_position_available(int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
        if (matrix[i][col])
            return false;

    for (i = row-1, j = col+1; i >= 0 && j < size; i--, j++)
        if (matrix[i][j])
            return false;

    for (i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        if (matrix[i][j])
            return false;

    return true;
}

bool NQueens :: solve(int index)
{
    if (index == size)
        return true;

    for (int i = 0; i < size; i++) {
        if (is_position_available(index, i)) {
            matrix[index][i] = 1;
            if (solve(index + 1))
                return true;
            matrix[index][i] = 0;
        }
    }
    return false;
}

void NQueens :: display()
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j])
                cout << "x ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    NQueens obj(10);
    obj.display();
    obj.solve(0);
    obj.display();
    return 0;
}
