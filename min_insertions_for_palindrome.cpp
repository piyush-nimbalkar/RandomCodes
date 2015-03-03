#include <iostream>

using namespace std;

int min(int a, int b)
{
    return (a < b ? a : b);
}

int rec_find_min_insertions(string str, int start, int end)
{
    if (start >= end)
        return 0;

    if (str[start] == str[end])
        return rec_find_min_insertions(str, start+1, end-1);

    return min(rec_find_min_insertions(str, start, end-1), rec_find_min_insertions(str, start+1, end)) + 1;
}

int find_min_insertions(string str)
{
    int i, j;
    int **memo = new int*[str.length()];

    for (i = 0; i < str.length(); i++)
        memo[i] = new int[str.length()];

    for (int len = 0; len < str.length(); len++) {
        for (i = 0; i < str.length() - len; i++) {
            j = i + len;
            if (i == j)
                memo[i][j] = 0;
            else if (i+1 == j)
                memo[i][j] = (str[i] == str[j] ? 0 : 1);
            else if (str[i] == str[j])
                memo[i][j] = memo[i+1][j-1];
            else
                memo[i][j] = min(memo[i+1][j], memo[i][j-1]) + 1;
        }
    }
    return memo[0][str.length()-1];
}


int main(int argc, char *argv[])
{
    string str("abcdedfdedcba");
    // cout << "Minimum Insertions: " << rec_find_min_insertions(str, 0, str.length()-1) << endl;
    cout << "Minimum Insertions: " << find_min_insertions(str) << endl;
    return 0;
}
