#include <iostream>

using namespace std;

int s[9][9];

bool hcheck(int n, int i)
{
    int j;
    for (j = 0; j < 9; j++)
        if(s[i][j] == n || s[i][j] == n * 10)
            return false;
    return true;
}

bool vcheck(int n, int j)
{
    int i;
    for (i = 0; i < 9; i++)
        if (s[i][j] == n || s[i][j] == n * 10)
            return false;
    return true;
}

bool scheck(int n, int i, int j)
{
    int i1, j1;

    while(i % 3 != 0)
        i--;
    while(j % 3 != 0)
        j--;

    for (i1 = i; i1 < i + 3; i1++)
        for (j1 = j; j1 < j + 3; j1++)
            if (s[i1][j1] == n || s[i1][j1] == n * 10)
                return false;
    return true;
}

int main(int argc, char *argv[])
{
    int i, j, m;

    for (i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            cin >> m;
            s[i][j] = m * 10;
        }
    }

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            int temp = 1;
            if (s[i][j] > 9)
                continue;
up:
            int k = temp;
            for (int n = temp; n < 10; n++) {
                if(hcheck(n, i) && vcheck(n, j)&& scheck(n, i, j)) {
                    s[i][j] = n;
                    break;
                } else {
                    k++;
                }
            }
            if (k == 10) {
                s[i][j] = 0;
                do {
                    j--;
                    if (j < 0) {
                        j = 8;
                        i--;
                    }
                    if (i < 0)
                        goto down;
                } while (s[i][j] >= 10);
                temp = s[i][j];
                goto up;
            }
        }
    }

    cout << "\n-------------------------\n";
    for (i = 0; i < 9; i++) {
        cout << "| ";
        for(j = 0; j < 9; j++) {
            cout << (s[i][j] > 9 ? s[i][j] / 10 : s[i][j]) << " ";
            if (j % 3 == 2)
                cout << "| ";
        }
        if (i % 3 == 2)
            cout << "\n-------------------------";
        cout << endl;
    }

 down:
    return 0;
}

// Sample Input
// 0 6 0 0 0 7 0 9 0
// 4 0 0 0 2 0 3 0 0
// 0 3 0 0 0 9 0 0 4
// 3 0 4 2 0 6 1 5 0
// 1 0 0 8 0 0 0 0 0
// 0 2 0 1 0 4 7 8 6
// 0 4 9 7 8 0 5 0 1
// 0 5 3 0 0 1 2 4 7
// 0 0 2 0 5 0 0 0 0

// 0 4 0 0 2 0 6 0 0
// 0 0 6 0 0 0 0 0 4
// 0 1 0 0 3 0 8 0 0
// 0 0 4 0 0 5 0 3 0
// 5 0 0 0 0 0 1 0 0
// 0 0 0 0 0 3 0 2 0
// 0 9 0 0 0 0 0 5 0
// 2 0 0 6 0 0 0 0 1
// 1 0 0 9 0 0 0 0 0
