#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str[] = "aaaaadfaaasd";
    int i, j, tail = 1, len;
    len = strlen(str);
    for(i = 1; i < len; i++) {
        for(j = 0; j < tail; j++)
            if(str[i] == str[j])
                break;
        if (j == tail)
            str[tail++] = str[i];
    }
    str[tail] = 0;
    cout << str << endl;
    return 0;
}
