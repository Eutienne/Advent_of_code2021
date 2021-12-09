
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

int main()
{
    std::ifstream       myfile ("file.txt");
    std::vector<std::string>    vec;
    std::string         line;
    int                 counter = 0;
    
    while (getline(myfile, line))
        vec.push_back(line);
    
    for (int y = 0;  y < vec.size(); y++)
    {
        for (int x = 0, z; vec[y][x]; x++)
        {
            z = 0;
            if (vec[y][x + 1])
            {
                if (vec[y][x + 1] > vec[y][x])
                    z++;
            }
            else
                z++;
            if (vec[y][x - 1])
            {
                if (vec[y][x - 1] > vec[y][x])
                    z++;
            }
            else
                z++;
            if (vec[y + 1][x])
            {
                if (vec[y + 1][x] > vec[y][x])
                    z++;
            }
            else
                z++;
            if (vec[y - 1][x])
            {
                if (vec[y -1 ][x] > vec[y][x])
                    z++;
            }
            else
                z++;
            if (z == 4)
                counter += ((vec[y][x] - 48) + 1);
        }
    }
    std::cout << counter <<std::endl;
}