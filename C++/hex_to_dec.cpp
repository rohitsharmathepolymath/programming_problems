#include <iostream>
#include <string>
#include <bitset>
#include <cstdlib>

std::string hexToDecimal(std::string hex)
{
    int decimal = 0;
    try
    {
        decimal = std::stoi(hex, nullptr, 16); // Convert hex string to integer
    }
    catch (const std::invalid_argument &)
    {
        std::cerr << "Invalid hexadecimal input." << std::endl;
        return "";
    }
    catch (const std::out_of_range &)
    {
        std::cerr << "The hexadecimal number is out of range." << std::endl;
        return "";
    }
    return std::to_string(decimal);
}

int main()
{
    std::string hexInput;
    std::cout << "Enter a hexadecimal number (e.g., 1A3F): ";
    std::cin >> hexInput;

    std::string decimalOutput = hexToDecimal(hexInput);
    if (!decimalOutput.empty())
    {
        std::cout << "Decimal equivalent: " << decimalOutput << std::endl;
    }

    return 0;
}