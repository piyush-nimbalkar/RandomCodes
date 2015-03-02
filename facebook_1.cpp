// Given a string
// "xyzabcxyaaxyd"
// remove duplicate chars
// return "xyzabcd"


string remove_duplicate(string str)
{
    int i;
    string result;

    unorder_map<char, bool> hash;

    for (i = 0; i < str.length(); i++)
        hash[str[i]] = true;

    for (unorder_map::iterator it = hash.begin(); it != hash.end(); it++)
        result += string(1, it->first);

    return result;
}

// Given a string "5+3*4"
// return 17
// assume:
// * only +, *
// * no ()
// * numbers > 0
// * is valid

// 5+3*4+6

int calculate(string str)
{
    int i = 0;
    int num, num2;
    stack<int> s;

    bool product = false;

    while (str[i] != 0) {
        num = 0;
        while(str[i] != 0 && str[i] >= '0' && str[i] <= '9')
            num = num * 10 + (str[i++] - '0');

        if (product) {
           num2 = s.top();
           s.pop();
           num *= num2;
           product = false;
        }

        s.push(num);

        if (str[i] == 0)
            break;

        if (str[i++] == '*')
            product = true;
    }

    int result = 0;
    while(!s.empty()) {
        result += s.top();
        s.pop();
    }

    return result;
}
