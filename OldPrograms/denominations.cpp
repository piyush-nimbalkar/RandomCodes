#include <iostream>

using namespace std;

const int size = 4;
int array[size] = {25, 10, 5, 1};

class Coin
{
    int value;

public:
    Coin() { }
    Coin(int v) { value = v; }
    int get_value() { return value; }
};

class Denomination
{
    Coin coins[size];

public:
    Denomination() { }
    Denomination(int *);
    void print_combinations(int);
    int combinations(int, int, int *, int);
};

Denomination :: Denomination(int *values)
{
    for (int i = 0; i < size; i++)
        coins[i] = values[i];
}

void Denomination :: print_combinations(int amount)
{
    int result[100], index = 0;
    cout << "\nTotal combinations : " << combinations(amount, 0, result, index) << endl;
}

int Denomination :: combinations(int amount, int count, int result[], int index)
{
    if (amount == 0) {
        for (int k = 0; k < index; k++)
            cout << result[k] << " ";
        cout << endl;
        return 1;
    }
    int total = 0;
    for (int i = count ; i < size; i++)
        if (amount >= coins[i].get_value()) {
            result[index] = coins[i].get_value();
            total += combinations(amount - coins[i].get_value(), i, result, index + 1);
        }
    return total;
}




int main(int argc, char *argv[])
{
    Denomination d(array);
    d.print_combinations(25);
    return 0;
}
