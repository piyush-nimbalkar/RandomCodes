#include <iostream>

using namespace std;


int my_atoi(const string &str)
{
    int i = 0;
    int result = 0;

    if (str[0] == '-' || str[0] == '+')
        i++;
    while(str[i] != 0) {
        if (str[i] < '0' || str[i] > '9')
            break;
        result = (result * 10) + (str[i++] - '0');
    }
    return (str[0] == '-' ? -1 * result : result);
}

float my_atof(const string &str)
{
    int i = 0, count = 0;
    float result = 0.0, decimal_result = 0.0;
    float factor = 0.1;
    bool decimal = false;

    if (str[0] == '-' || str[0] == '+')
        i++;
    while(str[i] != 0) {
        if (str[i] == '.') {
            if (decimal)
                break;
            i++;
            decimal = true;
            continue;
        }

        if (str[i] < '0' || str[i] > '9')
            break;

        if (!decimal)
            result = (result * 10.0) + (str[i] - '0');
        else {
            decimal_result += factor * (str[i] - '0');
            factor /= 10;
            count++;
        }
        i++;
    }
    cout.precision(i-1);
    return (str[0] == '-' ? -1 * result : result) + decimal_result;
}


int main(int argc, char *argv[])
{
    string str;

    cout << "Enter string: ";
    cin >> str;

    cout.precision(str.size()-1);
    cout << "Converted int: " << my_atoi(str) << endl;
    cout  << "Converted float: " << my_atof(str) << endl;

    return 0;
}
