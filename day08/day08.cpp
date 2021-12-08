
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

int main()
{
    std::ifstream       myfile ("file.txt");
    std::vector<int>    vec;
    std::string         line, tmp;
    int                 counter = 0;
    
    for (int pos; getline(myfile, line);)
    {
        pos = line.find('|');
        line.erase(0, pos + 1);
        pos = line.find(' ');
        line.erase(0, pos + 1);
        for (int i = 0; i < 4; i++)
        {
            pos = line.find(' ');
            tmp = line.substr(0, pos);
            // std::cout << tmp << strlen(tmp.c_str()) << std::endl;
            if (strlen(tmp.c_str()) == 2 || strlen(tmp.c_str()) == 4 || strlen(tmp.c_str()) == 3 || strlen(tmp.c_str()) == 7)
                counter++;
            line.erase(0, pos + 1);
        }

    }
    std::cout << counter <<std::endl;
}