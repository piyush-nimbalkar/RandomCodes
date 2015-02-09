#include <iostream>
#include <stack>

using namespace std;


void dp_lcs(string &x, string &y)
{
    int **c;
    int i, j;

    c = new int * [x.size() + 1];
    for (i = 0; i <= x.size(); i++)
        c[i] = new int[y.size() + 1];

    for (i = 0; i <= x.size(); i++)
        c[i][0] = 0;

    for (j = 0; j <= y.size(); j++)
        c[0][j] = 0;

    for (i = 1; i <= x.size(); i++) {
        for (j = 1; j <= y.size(); j++) {
            if (x[i-1] == y[j-1])
                c[i][j] = c[i-1][j-1] + 1;
            else if (c[i-1][j] >= c[i][j-1])
                c[i][j] = c[i-1][j];
            else
                c[i][j] = c[i][j-1];
        }
    }

    cout << endl;
    for (i = 0; i <= x.size(); i++) {
        for (j = 0; j <= y.size(); j++)
            cout << c[i][j] << " ";
        cout << endl;
    }

    stack<char> lcs_stack;
    cout << "\nLongest Subsequence: ";
    i = x.size(); j = y.size();
    while (i > 0 && j > 0) {
        if (x[i-1] == y[j-1]) {
            lcs_stack.push(x[i-1]);
            i--; j--;
        } else if (c[i-1][j] >= c[i][j-1])
            i--;
        else
            j--;
    }

    while (!lcs_stack.empty()) {
        cout << lcs_stack.top();
        lcs_stack.pop();
    }
    cout << endl;

    for (i = 0; i <= x.size(); i++)
        delete(c[i]);
    delete(c);
}


int max(int a, int b)
{
    return (a > b ? a : b);
}

int recursive_lcs(string &x, string &y, int xlen, int ylen)
{
    if (xlen == 0 || ylen == 0)
        return 0;
    if (x[xlen-1] == y[ylen-1])
        return recursive_lcs(x, y, xlen-1, ylen-1) + 1;
    return max(recursive_lcs(x, y, xlen-1, ylen), recursive_lcs(x, y, xlen, ylen-1));
}


int main(int argc, char *argv[])
{
    string a, b;

    cout << "Enter first sequence: ";
    cin >> a;
    cout << "Enter second sequence: ";
    cin >> b;

    dp_lcs(a, b);
    cout << "LCS Length: " << recursive_lcs(a, b, a.size(), b.size()) << endl << endl;
    return 0;
}
