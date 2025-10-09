#include <iostream>
#include <string>
using namespace std;
pair<int, int> countvc(string str)
{
    int vcount = 0, ccount = 0;
    for (char ch : str)
    {
        if (isalpha(ch))
        {
            ch = tolower(ch);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vcount++;
            else
                ccount++;
        }
    }
    return {vcount, ccount};
}
int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    pair<int, int> result = countvc(str);
    cout << "Vowels: " << result.first << ", Consonants: " << result.second;
    return 0;
}