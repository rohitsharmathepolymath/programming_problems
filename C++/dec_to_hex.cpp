#include <iostream>
#include <string>

std::string decimalToHex(int n)
{
    if (n == 0)
        return "0"; // Special case for 0
    std::string hex;
    const char *hexChars = "0123456789ABCDEF";
    while (n > 0)
    {
        int remainder = n % 16;
        hex = hexChars[remainder] + hex; // Prepend the corresponding hex character
        n /= 16;
    }
    return hex;
}

int main()
{
    std::string input;
    std::cout << "Enter a decimal number: ";
    std::getline(std::cin, input);

    try
    {
        int decimalNumber = std::stoi(input); // Convert string to integer
        if (decimalNumber < 0)
        {
            std::cerr << "Please enter a non-negative integer." << std::endl;
            return 1;
        }

        std::string hexRepresentation = decimalToHex(decimalNumber);
        std::cout << "Hexadecimal representation: " << hexRepresentation << std::endl;
    }
    catch (const std::invalid_argument &)
    {
        std::cerr << "Invalid input. Please enter a valid decimal number." << std::endl;
        return 1;
    }
    catch (const std::out_of_range &)
    {
        std::cerr << "The number is out of range." << std::endl;
        return 1;
    }

    return 0;
}