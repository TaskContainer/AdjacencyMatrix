#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

int main()
{
    std::ifstream input("input.txt");
    std::string number;
    std::getline(input, number);
    const int length = std::stoi(number);
    for (int i = 0; i < length; ++i)
    {
        std::vector<bool> row(length);
        std::string numbers;
        std::getline(input, numbers);
        std::stringstream converter(numbers);
        for (int j; converter >> j;)
        {
            if (j == 0)
            {
                break;
            }
            row[j - 1] = true;
        }
        for (const auto &i : row)
        {
            std::cout << i << ' ';
        }
        std::cout << std::endl;
    }
}

