#include <iostream>
#include <string>

int main()
{
    std::string name;
    int sum = 0;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    std::cout << "ASCII values of characters in your name:" << std::endl;
    for (char c : name)
    {
        std::cout << c << ": " << static_cast<int>(c) << std::endl;
        sum += static_cast<int>(c);
    }

    std::cout << "Sum of ASCII values: " << sum << std::endl;
    char *hexChars = "0123456789ABCDEF";
    std::string hex;
    int n = sum;
    if (n == 0)
    {
        hex = "00";
    }
    else
    {
        while (n > 0)
        {
            hex = hexChars[n % 16] + hex;
            n /= 16;
        }
        if (hex.length() % 2 != 0)
        {
            hex = "0" + hex; // Ensure even length for byte representation
        }
    }
    std::cout << "Hexadecimal representation: " << hex << std::endl;

    return 0;
}