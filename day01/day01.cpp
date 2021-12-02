#include <fstream>
#include <sstream>
#include <iostream>

int main()
{
    std::ifstream myfile ("file.txt");
    int           x, y, i = 0;
    std::string   line;

    if (myfile.is_open())
    {
        y = 2147483647;
        while (getline(myfile, line))
        {
            std::stringstream S(line);
            S >> x;
            if (x > y)
                i++;
            y = x;
        }
    }
    myfile.close();
    std::cout << i << std::endl;
    return (i);
}