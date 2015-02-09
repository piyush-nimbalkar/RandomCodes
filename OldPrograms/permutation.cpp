#include <iostream>
#include <cstring>

using namespace std;

void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

void permutation(char* str, int start, int length)
{
    if(start == length)
        cout << str << endl;

    for(int i = start; i < length; i++) {
        swap(str[start], str[i]);
        permutation(str, start + 1, length);
        swap(str[i], str[start]);
    }
}



int main(int argc, char *argv[])
{
    char str[10];
    char temp;
    cin >> str;
    permutation(str, 0, strlen(str));
    return 0;
}
