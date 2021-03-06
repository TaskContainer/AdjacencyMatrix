#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <iterator>

template<typename T> std::ostream &operator<<(std::ostream &stream, const std::vector<T> &vec)
{
    std::copy(vec.cbegin(), vec.cend(), std::ostream_iterator<T>(stream, " "));
    return stream;
}

int main()
{
    std::ifstream input("input.txt");
    std::string buffer;
    std::getline(input, buffer);
    const int length = std::stoi(buffer);
    // Конструируем матрицу
    std::vector<std::vector<bool>> matrix(length, std::vector<bool>(length));
    for (int i = 0; i < length; ++i)
    {
        std::getline(input, buffer);
        std::stringstream converter(buffer);
        for (int j; converter >> j && j;)
        {
            matrix[i][j - 1] = true;
        }
    }
    // Выводим
    for (const auto &row : matrix)
    {
        std::cout << row << std::endl;
    }
}

