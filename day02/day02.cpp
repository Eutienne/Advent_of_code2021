#include <fstream>
#include <sstream>
#include <iostream>

int main()
{
    std::ifstream       myfile ("file.txt");
    std::string         line;
    std::stringstream   S;
    int                 x = 0, y = 0,z;

    S << myfile.rdbuf();
    while (S >> line >> z)
    {
        if (line == "forward")
            x += z;
        else
            line == "up"? y -= z : y +=z;
    }
    std::cout << y * x<< std::endl;
    return (0);
}