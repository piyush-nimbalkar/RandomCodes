#include <iostream>
#include <cstring>

using namespace std;

class Random
{
    string matrix[10][10];
    int no_of_rows, no_of_cols;

public:
    Random() { }
    Random(int, int);
    void combinations(int, string);
};

Random :: Random(int rows, int cols)
{
    no_of_rows = rows;
    no_of_cols = cols;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> matrix[i][j];
}

void Random :: combinations(int row_number, string str)
{
    if (row_number == no_of_rows) {
        cout << str << endl;
        return;
    }
    for (int i = 0; i < no_of_cols; i++) {
        string temp = str + matrix[row_number][i];
        combinations(row_number + 1, temp);
    }
}

int main(int argc, char *argv[])
{
    Random obj(4, 3);
    obj.combinations(0, "");
    return 0;
}
