#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 10;

class String
{
    int length;
    char string[MAX];

public:
    String() { }
    String(char *);
    void permutations(int);
    void rec_permutations(int, char *, int);
};

String :: String(char *str)
{
    length = strlen(str);
    strcpy(string, str);
}

void String :: permutations(int k)
{
    char kstring[MAX];
    kstring[k] = 0;
    rec_permutations(k, kstring, 0);
}

void String :: rec_permutations(int k, char *kstring, int index)
{
    if (index == k) {
        cout << kstring << endl;
        return;
    }
    for (int i = 0; i < length; i++) {
        kstring[index] = string[i];
        rec_permutations(k, kstring, index + 1);
    }
}


int main(int argc, char *argv[])
{
    int k;
    char str[MAX];

    cout << "Enter the string: ";
    cin >> str;
    cout << "Enter k: ";
    cin >> k;

    String s(str);
    s.permutations(k);
    return 0;
}
