#include <iostream>

using namespace std;

int max_palindrome(string str)
{
    int i, j, len;
    int **memo = new int*[str.length()];

    for (i = 0; i < str.length(); i++)
        memo[i] = new int[str.length()];

    for (len = 0; len < str.length(); len++) {
        for (i = 0; i < str.length() - len; i++) {
            j = i + len;
            if (i == j)
                memo[i][j] = 1;
            else if (i+1 == j)
                memo[i][j] = (str[i] == str[j] ? 2 : 1);
            else if (str[i] == str[j])
                memo[i][j] = memo[i+1][j-1] + 2;
            else
                memo[i][j] = max(memo[i+1][j], memo[i][j-1]);
        }
    }
    return memo[0][str.length()-1];
}

int rec_max_palindrome(string str, int start, int end)
{
    if (start > end)
        return 0;
    if (start == end)
        return 1;

    if (str[start] == str[end])
        return rec_max_palindrome(str, start+1, end-1) + 2;
    else
        return max(rec_max_palindrome(str, start, end-1), rec_max_palindrome(str, start+1, end));
}

int main(int argc, char *argv[])
{
    string str("abcdcxcb");
    cout << str << endl;
    // cout << rec_max_palindrome(str, 0, str.length()-1) << endl;
    cout << max_palindrome(str) << endl;
    return 0;
}
