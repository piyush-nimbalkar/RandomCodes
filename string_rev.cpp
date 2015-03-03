#include <iostream>
#include <algorithm>

using namespace std;


void reverse_words(string &str)
{
    int start = -1, end;

    reverse(str.begin(), str.end());

    for (int i = 0; i <= str.length(); i++) {
        if (str[i] == 0 || str[i] == ' ') {
            if (start != -1) {
                reverse(str.begin() + start, str.begin() + i);
                start = -1;
            }
        }
        else if (start == -1)
            start = i;
    }
    cout << str << endl;
}

int main(int argc, char *argv[])
{
    string input("hello this is a new  string");
    reverse_words(input);
    return 0;
}
