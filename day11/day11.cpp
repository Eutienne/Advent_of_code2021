
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

long    l = 0;

void    reset(std::vector<std::string> &v)
{
    for (int y =0; y < v.size(); y++)
    {
        for (int x = 0; x < v[y].size(); x++)
        {
            if (v[y][x] == 47)
                v[y][x]++;
        }
    }
}


void     increase_neighbors(std::vector<std::string> &v)
{
    for (int y =0; y < v.size(); y++)
    {
        for (int x = 0; x < v[y].size(); x++)
        {
            if (v[y][x] > '9'){
                if (y > 0 && x > 0 && v[y - 1][x - 1] != 47)
                    v[y - 1][x - 1]++;
                if (y > 0 && v[y -1][x] != 47)
                    v[y -1][x]++;
                if (y > 0 && x < v[y].size() -1 && v[y - 1][x + 1] != 47)
                    v[y - 1][x + 1]++;
                if (x > 0 && v[y][x - 1] != 47)
                    v[y][x - 1]++;
                if (x < v[y].size() -1 && v[y][x + 1] != 47)
                    v[y][x + 1]++;
                if (y < v.size() - 1 && x > 0 && v[y + 1][x - 1] != 47)
                    v[y + 1][x - 1]++;
                if (y < v.size() -1 && v[y + 1][x] != 47)
                    v[y + 1][x]++;
                if (y < v.size() -1 && x < v[y].size() -1 && v[y + 1][x + 1] != 47)
                    v[y + 1][x + 1]++;
                v[y][x] = 47;
                l++;
            }
        }
    }
}


void    increase(std::vector<std::string> &v)
{
    for (int y =0; y < v.size(); y++)
    {
        for (int x = 0; x < v[y].size(); x++)
            v[y][x]++;
    }
}

int    light(std::vector<std::string> v)
{
    int i = 0;
    for (int y =0; y < v.size(); y++)
    {
        for (int x = 0; x < v[y].size(); x++)
        {
            if (v[y][x] > '9')
                i++;
        }
    }
    return i;
}


int main(int argc, char** argv)
{
    std::ifstream       myfile (argv[1]);
    std::vector<std::string>    vec;
    std::string         line;
    
    while (getline(myfile, line))
        vec.push_back(line);
    for (int x = 0; x < 100; x++)
    {
        increase(vec);
        while (light(vec) > 0)
            increase_neighbors(vec);
        reset(vec);
    }
    for (int y =0; y < vec.size(); y++)
    {
        for (int x = 0; x < vec[y].size(); x++)
            std::cout << vec[y][x] << " ";
        std::cout << std::endl;
    }

    std::cout << l <<std::endl;
}