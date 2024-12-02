#include <iostream>
#include <fstream>
#include <sstream>

int main()
{
    std::ifstream file("input.txt");

    if (!file.is_open())
    {
        std::cerr << "Could not open the file!\n";
        return 1;
    }

    std::string line;
    int unsafe = 0;
    int reports = 0;
    while (std::getline(file, line))
    {
        reports += 1;
        std::istringstream iss(line);
        int num1, num2;

        iss >> num1;
        if (!(iss >> num2))
        {
            continue;
        }

        int inc = num2 > num1 ? 1 : (num2 < num1 ? -1 : 0);
        do
        {

            int dif = (num2 - num1) * inc;
            num1 = num2;
            if (dif < 1 || dif > 3)
            {
                unsafe += 1;
                std::cout << "Unsafe line for num1: " << num1 << " and num2: " << num2 << "=>\n"
                          << line << std::endl;
                break;
            }
        } while (iss >> num2);
    }

    std::cout << "Reports: " << reports << std::endl;
    std::cout << "Safe: " << reports - unsafe << std::endl;
}