#include <iostream>
#include <list>
#include <map>

using namespace std;


bool is_separable(const string &str, int index, const map<string, bool> &dict, list<string> &found_words)
{
    if (index == str.length())
        return true;

    string current = "";
    for (int i = index; i < str.length(); i++) {
        current += str[i];
        if (dict.count(current) > 0) {
            found_words.push_back(current);
            if (is_separable(str, i+1, dict, found_words))
                return true;
            found_words.pop_back();
        }
    }
    return false;
}

void separate_words(string input, string *dictionary, int size)
{
    map<string, bool> dict;
    for (int i = 0; i < size; i++)
        dict[dictionary[i]] = true;

    list<string> words;
    is_separable(input, 0, dict, words);

    for (list<string>::iterator it = words.begin(); it != words.end(); it++)
        cout << *it << " ";
    cout << endl;
}

int main(int argc, char *argv[])
{
    string dict[] = {"the", "a", "i", "here", "so", "hid", "there", "are",
                     "some", "word", "words", "hid", "hi", "hidden", "he",
                     "here", "her", "rear", "me", "den"};

    string input("therearesomewordshiddenhere");
    cout << input << endl;

    separate_words(input, dict, 20);

    return 0;
}
