#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string s("Somewhere down the road");
    istringstream iss(s);
    string str = "";
    while(iss)
    {
        string sub;
        iss >> sub;
        str = sub + " " + str;
        cout << "Substring: " << sub << endl;
    }
    cout << str << endl;
}
