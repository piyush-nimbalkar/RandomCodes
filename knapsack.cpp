#include <iostream>

using namespace std;


const int SIZE = 20;


int max(int a, int b)
{
    return (a > b ? a : b);
}

void display_matrix(int matrix[][SIZE], int *weight, int rows, int cols)
{
    int i, w;
    cout << endl << "\t|   ";
    for (i = 0; i <= cols; i++)
        cout << i << "\t   ";
    cout << endl;
    for (i = 0; i <= cols+1; i++)
        cout << "--------";
    cout << endl;

    for (i = 0; i <= rows; i++) {
        cout << weight[i-1] << "\t|   ";
        for (w = 0; w <= cols; w++)
            cout << matrix[i][w] << "\t   ";
        cout << endl;
    }
}

void knapsack(int weight[], int value[], int capacity, int size)
{
    int i, w;
    int matrix[SIZE][SIZE];

    for (i = 0; i <= size; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                matrix[i][w] = 0;
            else if (weight[i-1] <= w)
                matrix[i][w] = max(matrix[i-1][w], matrix[i-1][w-weight[i-1]] + value[i-1]);
            else
                matrix[i][w] = matrix[i-1][w];
        }
    }

    display_matrix(matrix, weight, size, capacity);

    cout << "\nWeights in knapsack: ";
    i = size, w = capacity;
    while (i > 0) {
        if (matrix[i][w] == matrix[i-1][w])
            i--;
        else {
            w -= weight[--i];
            cout << weight[i] << " ";
        }
    }
    cout << endl << endl;
}



int main(int argc, char *argv[])
{
    int size, capacity, i;
    int values[SIZE], weights[SIZE];

    cout << "Enter number of weights: ";
    cin >> size;

    cout << "Enter weights: ";
    for (i = 0; i < size; i++)
        cin >> weights[i];

    cout << "Enter values: ";
    for (i = 0; i < size; i++)
        cin >> values[i];

    cout << "Enter capacity: ";
    cin >> capacity;

    knapsack(weights, values, capacity, size);
    return 0;
}
