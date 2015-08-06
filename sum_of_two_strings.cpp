#include <iostream>
#include <algorithm>

using namespace std;


string string_sum(string one, string two)
{
    int i, j, length;
    int sum = 0, carry = 0;
    string result;

    for (i = one.size()-1, j = two.size()-1; i >= 0 && j >= 0; i--, j--) {
        sum = one[i] + two[j] + carry - 0x30;
        carry = 0;
        if (sum > 0x39) {
            carry = 1;
            sum -= 10;
        }
        result += sum;
    }

    for ( ; i >= 0; i--) {
        sum = one[i] + carry;
        carry = 0;
        if (sum > 0x39) {
            carry = 1;
            sum -= 10;
        }
        result += sum;
    }

    for ( ; j >= 0; j--) {
        sum = two[j] + carry;
        carry = 0;
        if (sum > 0x39) {
            carry = 1;
            sum -= 10;
        }
        result += sum;
    }

    if (carry)
        result += 0x31;
    reverse(result.begin(), result.end());
    return result;
}

string string_diff(string one, string two)
{
    int i, j, length;
    int diff, borrow = 0;
    string result;

    for (i = one.size()-1, j = two.size()-1; i >= 0 && j >= 0; i--, j--) {
        diff = one[i];
        if (borrow)
            diff--;

        if (diff < two[j]) {
            diff += 10;
            borrow = 1;
        } else
            borrow = 0;
        diff = diff - two[j] + 0x30;
        result += diff;
    }

    for ( ; i >= 0; i--) {
        diff = one[i];
        if (borrow)
            diff--;

        if (diff < 0x30) {
            diff += 10;
            borrow = 1;
        } else
            borrow = 0;

        if (diff != 0x30 || i != 0)
            result += diff;
    }

    reverse(result.begin(), result.end());
    return result;
}


int main(int argc, char *argv[])
{
    string first("100000"), second("500");
    cout << first << endl << second << endl;
    // cout << string_sum(first, second) << endl;
    cout << string_diff(first, second) << endl;
    return 0;
}
