#include <iostream>
#include <string>

int main()
{
    for (int i = 0; i < 255; i++)
    {
        char a = i;
        std::cout << i << ": " << a << std::endl;
    }
    return 0;
}