#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;
vector<pair<char, vector<size_t>>> occurrences(string str)
{
    set<char> s;
    for (char c : str)
    {
        s.insert(c);
    }
    vector<pair<char, vector<size_t>>> result;
    for (char c : s)
    {
        vector<size_t> positions;
        for (size_t i = 0; i < str.length(); i++)
        {
            if (str[i] == c)
                positions.push_back(i);
        }
        result.push_back(make_pair(c, positions));
    }
    return result;
}

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    vector<pair<char, vector<size_t>>> result = occurrences(str);
    for (const auto &p : result)
    {
        cout << p.first << ": ";
        for (size_t pos : p.second)
        {
            cout << pos << " ";
        }
        cout << endl;
    }
    return 0;
}