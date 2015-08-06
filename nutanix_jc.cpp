#include <iostream>
#include <vector>

using namespace std;


string zip(const vector<vector<char> > &input)
{
    string output;
    int row_num, col_num = 0;
    int rows_remaining = input.size();

    while (rows_remaining > 0) {
        for (row_num = 0; row_num < input.size(); row_num++) {
            if (col_num < input[row_num].size()) {
                output += input[row_num][col_num];
            } else if (col_num == input[row_num].size()) {
                rows_remaining--;
            }
        }
        col_num++;
    }
    return output;
}

int main(int argc, char *argv[])
{
    vector<vector<char> > input;
    vector<char> v1;
    v1.push_back('a');
    v1.push_back('b');
    v1.push_back('c');

    vector<char> v2;

    v2.push_back('1');
    v2.push_back('2');
    v2.push_back('3');
    v2.push_back('4');

    vector<char> v3;

    v3.push_back('x');
    v3.push_back('y');
    v3.push_back('z');
    v3.push_back('p');
    v3.push_back('q');

    input.push_back(v1);
    input.push_back(v2);
    input.push_back(v3);

    cout << zip(input) << endl;

    return 0;
}
