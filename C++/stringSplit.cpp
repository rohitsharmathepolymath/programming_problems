#include <string>
#include <vector>
#include <iostream>
#include <sstream>

int main()
{
    std::string s;
    std::getline(std::cin, s);
    std::stringstream ss(s);
    std::vector<std::string> k;

    std::string word;

    while (ss >> word)
    {
        k.push_back(word);
    }
    for (int i = 0; i < k.size(); i++)
    {
        std::cout << k[i] << std::endl;
    }

    return 0;
}