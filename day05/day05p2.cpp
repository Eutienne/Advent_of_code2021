#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <array>

struct cordinate
{
    int x, y, x2, y2;
};

void    fill_grid(std::vector<std::vector<int> > &grid, cordinate C)
{
    if (C.x == C.x2 || C.y == C.y2)
    {
        if (C.x > C.x2)
        {
            for (int x = C.x2; x < C.x; x++)
                grid[C.y][x]++;
            grid[C.y][C.x]++;
        }    
        else if (C.x < C.x2)
        {
            for (int x = C.x; x < C.x2; x++)
                grid[C.y][x]++;
            grid[C.y][C.x2]++;
        }
        else if (C.y > C.y2)
        {
            for (int y = C.y2; y < C.y; y++)
                grid[y][C.x]++;
            grid[C.y][C.x]++;
        }
        else 
        {
            for (int y = C.y; y < C.y2; y++)
                grid[y][C.x]++;
            grid[C.y2][C.x]++;
        }
    }
    else
    {
        if (C.x > C.x2 && C.y > C.y2)
        {
            for (int x = C.x2, y = C.y2; x < C.x; x++, y++)
                grid[y][x]++;
            grid[C.y][C.x]++;
        }
        else if (C.x < C.x2 && C.y < C.y2)
        {
            for (int x = C.x, y = C.y; x < C.x2; x++, y++)
                grid[y][x]++;
            grid[C.y2][C.x2]++;
        }
        else if (C.x < C.x2 && C.y > C.y2)
        {
            for (int x = C.x, y = C.y; x < C.x2; x++, y--)
                grid[y][x]++;
            grid[C.y2][C.x2]++;
        }
        else
        {
            for (int x = C.x, y = C.y; y < C.y2; x--, y++)
                grid[y][x]++;
            grid[C.y2][C.x2]++;
        }
        
    }
}

int main()
{
    std::ifstream       myfile ("file.txt");
    std::vector<std::vector<int> >    grid;
    std::string         line;
    cordinate           C;
    int                 i;

    grid.resize(1000);
    for (int y = 0; y < 1000; y++)
    {
        for (int x = 0; x < 1000; x++)
            grid[y].push_back(0);
    }         

    for (int pos = 0; getline(myfile, line);)
    {
        pos = line.find(',');
        C.x = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);
        pos = line.find('-');
        C.y = stoi(line.substr(0, pos));
        line.erase(0, pos + 2);
        pos = line.find(',');
        C.x2 = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);
        C.y2 = stoi(line);
        fill_grid(grid, C);
    }
    i = 0;
    for (int y = 0; y < 1000; y++)
    {
        for (int x = 0; x < 1000; x++)
        {
            if (grid[y][x] > 1)
                i++;
        }
    }         
        std::cout << i << std::endl;
    return 0;
}
