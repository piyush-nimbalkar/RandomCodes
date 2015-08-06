#include <iostream>

using namespace std;

int min(int a, int b)
{
    return (a < b ? a : b);
}

int min_edit_distance_rec(string &s1, string &s2, int i, int j)
{
    if (i == 0 && j == 0)
        return 0;
    if (i == 0)
        return j;
    if (j == 0)
        return i;

    int del = min_edit_distance_rec(s1, s2, i-1, j) + 1;
    int ins = min_edit_distance_rec(s1, s2, i, j-1) + 1;
    int rep = min_edit_distance_rec(s1, s2, i-1, j-1) + (s1[i-1] != s2[j-1]);

    return min(min(ins, del), rep);
}


int min_edit_distance(string s1, string s2)
{
    int **memo;
    int i, j;
    int del, ins, rep;

    memo = new int * [s1.length() + 1];
    for (i = 0; i <= s1.length(); i++)
        memo[i] = new int[s2.length() + 1];

    for (i = 0; i <= s1.length(); i++)
        memo[i][0] = i;

    for (j = 0; j <= s2.length(); j++)
        memo[0][j] = j;

    for (i = 1; i <= s1.length(); i++) {
        for (j = 1; j <= s2.length(); j++) {
            del = memo[i][j-1] + 1;
            ins = memo[i-1][j] + 1;
            rep = memo[i-1][j-1] + (s1[i-1] != s2[j-1]);
            memo[i][j] = min(min(ins, del), rep);
        }
    }

    for (i = 0; i <= s1.length(); ++i) {
        for (j = 0; j <= s2.length(); j++) {
            cout << memo[i][j] << "  ";
        }
        cout << endl;
    }

    return memo[s1.length()][s2.length()];
}


bool is_one_edit_apart(string s1, string s2)
{
    int i, edits = 0;

    string small = s1.length() <= s2.length() ? s1 : s2;
    string large = s1.length() <= s2.length() ? s2 : s1;

    if (large.length() - small.length() > 1)
        return false;
    else if (large.length() == small.length()) {
        for (i = 0; i < small.length(); i++)
            if (small[i] != large[i] && ++edits > 1)
                return false;
    } else {
        for (i = 0; i < small.length(); i++)
            if (small[i] != large[i + edits] && ++edits > 1)
                return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    string s1, s2;
    cin >> s1 >> s2;
    // cout << is_one_edit_apart(s1, s2) << endl;
    // cout << "Min Edit Distance: "<< min_edit_distance_rec(s1, s2, s1.length(), s2.length()) << endl;
    cout << "Min Edit Distance: "<< min_edit_distance(s1, s2) << endl;
    return 0;
}
