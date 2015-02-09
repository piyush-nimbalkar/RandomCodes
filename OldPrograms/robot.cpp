#include <iostream>

using namespace std;

const int max_size = 10;

class Grid
{
    int size;
    int matrix[max_size][max_size];

public:
    Grid() { }
    Grid(int);
    void count_paths();
    int rec_count_paths(int, int);
};

Grid :: Grid(int s)
{
    size = s;
}

void Grid :: count_paths()
{
    cout << rec_count_paths(size - 1, size - 1) << endl;
}

int Grid :: rec_count_paths(int row, int col)
{
    if (row == 0 || col == 0)
        return 1;
    return rec_count_paths(row - 1, col) + rec_count_paths(row, col - 1);
}

int main(int argc, char *argv[])
{
    Grid grid(3);
    grid.count_paths();
    return 0;
}
