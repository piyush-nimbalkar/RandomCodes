#include <iostream>
#include <string>

using namespace std;

class Bracket
{
    int pairs;

public:
    Bracket() { }
    Bracket(int);
    void print_pairs();
    void rec_pairs(int, int, char *, int);
};

Bracket :: Bracket(int pair_count)
{
    pairs = pair_count;
}

void Bracket :: print_pairs()
{
    char str[pairs * 2 + 1];
    str[pairs * 2] = 0;
    rec_pairs(pairs, pairs, str, 0);
}

void Bracket :: rec_pairs(int lcount, int rcount, char *str, int index)
{
    if (lcount < 0 || rcount < lcount)
        return;
    if (lcount == 0 && rcount == 0)
        cout << str << endl;
    else {
        if (lcount > 0) {
            str[index] = '(';
            rec_pairs(lcount - 1, rcount, str, index + 1);
        }
        if (rcount > lcount) {
            str[index] = ')';
            rec_pairs(lcount, rcount - 1, str, index + 1);
        }
    }
}


int main(int argc, char *argv[])
{
    Bracket b(4);
    b.print_pairs();
    return 0;
}
