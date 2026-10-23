#include <iostream> 
#include <fstream>
#include <vector>


template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& matrix)
{
    size_t num1 = matrix.size();
    size_t num2 = matrix[0].size();

    for (std::size_t i = 0; i < num1; ++i)
    {
        for (std::size_t j = 0; j < num2; j++)
        {
            // matrix[i][j] = fin.get()
            os << matrix[i][j] << " ";

        }
        os << std::endl;
    }
    return os;
}

int main()
{
    std::ifstream fin;
    fin.open("matrix_input.txt");
    if (fin.good())
    {
        std::cout << "All is good" << std::endl;
    }

    if (fin.eof())
    {
        std::cout << "End Of File" << std::endl;
    }

    if (fin.fail())
    {
        std::cout << "Non-critical operation failure" << std::endl;
    }

    if (fin.bad())
    {
        std::cout << "Critical error" << std::endl;
    }
    size_t num1;
    size_t num2;
    fin >> num1 >> num2; // читает до пробела 
    std::vector<std::vector<int>> matrix(num1, std::vector<int>(num2));
    for (std::size_t i = 0; i < num1; ++i)
    {
        for (std::size_t j = 0; j < num2; j++)
        {
            // matrix[i][j] = fin.get()
            fin >> matrix[i][j];

        }
    }
    std::cout << matrix;
    fin.close();

    return 0;
}

