#include <fstream>
#include <sstream>
#include <iostream>

int main()
{
    std::ifstream       myfile ("file.txt");
    std::string         line;
    std::stringstream   S;
    int                 x = 0, y = 0, aim = 0,z;

    S << myfile.rdbuf();
    while (S >> line >> z)
    {
        if (line == "forward")
        {
            x += z;
            y +=  z * aim;
        }
        else
            line == "up" ? aim -= z : aim += z;
    }
    std::cout << y * x<< std::endl;
    return (0);
}