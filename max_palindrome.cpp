#include <iostream>

using namespace std;

int main() {
    int i, j;
    string str("banananananananab");

    cout << "Enter String: ";
    cin >> str;

    int max_start = 0, max_end = 0, max_length = 0;
    int odd_start, odd_end, odd_length, even_start, even_end, even_length;

    for (i = 0; i < str.size(); i++) {
        for (j = 0; (i-j) >= 0 && ((i+j) < str.size()); j++)
            if (str[i-j] != str[i+j])
                break;

        if ((j*2 - 1) > max_length) {
            max_start = i-j+1;
            max_end = i+j-1;
            max_length = j*2 - 1;
        }

        for (j = 0; (i-j) >= 0 && ((i+j+1) < str.size()); j++)
            if (str[i-j] != str[i+j+1])
                break;

        if ((j*2) > max_length) {
            max_start = i-j+1;
            max_end = i+j;
            max_length = j*2;
        }
    }

    for (i = max_start; i <= max_end; i++)
        cout << str[i];
    cout << "\nLength: " << max_length << endl;

    return 0;
}
