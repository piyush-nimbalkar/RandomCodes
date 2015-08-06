#include <iostream>
#include <vector>

using namespace std;

void ones_comp(int num, vector<bool> &comp)
{
    if (num <= 1)
        comp.push_back(!num);
    else {
        int remainder = num % 2;
        ones_comp(num/2, comp);
        comp.push_back(!remainder);
    }
}

int main(int argc, char *argv[])
{
    int num;
    vector<bool> comp;
    cin >> num;
    ones_comp(num, comp);

    int two_pow = 1;
    int result = 0;
    for (int i = comp.size()-1; i >= 0; i--) {
        result += (comp[i] * two_pow);
        two_pow *= 2;
    }
    cout << result;
    return 0;
}
