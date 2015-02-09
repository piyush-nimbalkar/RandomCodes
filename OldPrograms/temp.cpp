#include<iostream>
#include<cstdlib>

using namespace std;

class Parentheses {
public:
        void print(int n);
        void p(int l, int r, char s[], int index, int n);
};

void Parentheses :: p(int l, int r, char s[], int index, int n)
{
        if (l == n && r == n)
                {
                        cout << s << endl;
                        index = 0;
                }
        else
                {
                        if (l < n)
                                {
                                        s[index] = '(';
                                        index++;
                                        p(l+1, r, s, index, n);
                                }
                        if (r < l)
                                {
                                        s[index] = ')';
                                        index++;
                                        p(l, r+1, s, index, n);
                                }
                }
}

void Parentheses :: print(int n)
{
        char str[10];
        int index = 0;
        p(0, 0, str, index, 3);
}



int main(int argc, char *argv[])
{
        Parentheses p;
        p.print(3);
        return 0;
}
