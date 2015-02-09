#include <iostream>

using namespace std;

class Board
{
    int matrix[100][100];
    int size;

public:
    Board() {}
    Board(int);
    int nqueens(int);
    int attack(int, int);
    void display();
};

Board :: Board(int s)
{
    int i, j;

    size = s;
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            matrix[i][j] = 0;
}

int Board :: attack(int row, int col)
{
    int i, j;

    for(i = 0; i < row; i++)
        if(matrix[i][col])
            return 1;

    for(i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        if(matrix[i][j])
            return 1;

    for(i = row-1, j = col+1; i >= 0 && j < size; i--, j++)
        if(matrix[i][j])
            return 1;

    return 0;
}

int Board :: nqueens(int row)
{
    if (row == size)
        return 1;
    for(int j = 0; j < size; j++) {
        if(!attack(row, j)) {
            matrix[row][j] = 1;
            if(nqueens(row + 1))
                return 1;
            else
                matrix[row][j] = 0;
        }
    }
    return 0;
}

void Board :: display()
{
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++)
            cout << matrix[i][j] << "  ";
         cout << endl;
    }
    cout << endl;
}


int main()
{
    int size = 10;
    Board b = size;
    b.display();
    b.nqueens(0);
    b.display();
    return 0;
}
