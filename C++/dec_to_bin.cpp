#include <iostream>
#include <string>
#include <bitset>
#include <cstdlib>

std::string decimalToBinary(int n)
{
    std::string binary = std::bitset<32>(n).to_string(); // Convert to binary using bitset
    // Remove leading zeros
    size_t pos = binary.find('1');
    if (pos != std::string::npos)
        return binary.substr(pos);
    return "0"; // If the number is 0, return "0"
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

        std::string binaryRepresentation = decimalToBinary(decimalNumber);
        std::cout << "Binary representation: " << binaryRepresentation << std::endl;
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