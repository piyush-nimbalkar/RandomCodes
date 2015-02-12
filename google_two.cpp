#include <iostream>
#include <vector>
#include <map>

using namespace std;
// s3k -> [stack, speak]
// i18n -> internationalization
// [stack, speak] => []
// [stack, speak, internationalization] => [i18n -> internationalization]


string itoa(int number)
{
    if (number < 10)
        return string(1, number + '0');
    return itoa(number / 10) + string(1, (number % 10) + '0');
}

string i18n(string word)
{
    string key;
    if (word.size() == 0)
        key = itoa(0);
    else if (word.size() == 1)
        key += word[0] + itoa(0);
    else
        key  += word[0] + itoa(word.size() - 2) + word[word.size()-1];
    return key;
}

map<string, string> map_dict(vector<string> dict)
{
    map<string, vector<string> > master_map;
    vector<string>::iterator it;
    for (it = dict.begin(); it != dict.end(); it++) {
        string key = i18n(*it);
        if (master_map.count(key) > 0) {
            master_map[key].push_back(*it);
        } else {
            vector<string> temp;
            temp.push_back(*it);
            master_map[key] = temp;
        }
    }

    map<string, string> result;

    for (map<string, vector<string> >::iterator i = master_map.begin(); i != master_map.end(); i++) {
        if (i->second.size() == 1)
            result[i->first] = i->second[0];
    }

    return result;
}


int main(int argc, char *argv[])
{
    string dict_array[] = {"shashank", "stick", "stack"};
    vector<string> dict(dict_array, dict_array+2);

    map<string, string> result = map_dict(dict);
    for (map<string, string>::iterator i = result.begin(); i != result.end(); i++)
        cout << i->first << " => " << i->second << endl;

    return 0;
}
