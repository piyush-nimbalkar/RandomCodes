#include <iostream>

using namespace std;

int max_palindrome(string str)
{
    int i, j, len;
    int **memo = new int*[str.length()];

    int start = 0, length = 0;
    for (i = 0; i < str.length(); i++)
        memo[i] = new int[str.length()];

    for (len = 0; len < str.length(); len++) {
        for (i = 0; i < str.length() - len; i++) {
            j = i + len;
            if (i == j)
                memo[i][j] = true;
            else if (i+1 == j)
                memo[i][j] = (str[i] == str[j] ? true : false);
            else if (str[i] == str[j]) {
                if (memo[i+1][j-1]) {
                    start = i;
                    length = len;
                    memo[i][j] = true;
                } else
                    memo[i][j] = false;
            } else
                memo[i][j] = memo[i+1][j] || memo[i][j-1];
        }
    }
    return length+1;
}


int main(int argc, char *argv[])
{
    string str("abcdabcxcba");
    cout << max_palindrome(str) << endl;
    return 0;
}
