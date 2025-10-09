#include <iostream>
#include <string>
using namespace std;
void removeSpaces(string &str)
{
    int n = str.length();
    int j = 0; // index of the next position to fill
    for (int i = 0; i < n; i++)
    {
        if (str[i] != ' ')
        {
            str[j++] = str[i];
        }
    }
    str.resize(j); // resize the string to the new length
}
int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    removeSpaces(str);
    cout << "String after removing spaces: " << str;
    return 0;
}