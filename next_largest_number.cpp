#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    string str("92341");
    string::iterator it;

    for (it = str.end(); it != str.begin(); it--) {
        if (*(it-1) < *it) {
            *(it-1) = *it ^ *(it-1);
            *(it)   = *it ^ *(it-1);
            *(it-1) = *it ^ *(it-1);
            break;
        }
    }

    sort(it, str.end());
    cout << str << endl;
    return 0;
}
