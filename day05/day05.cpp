#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <cstring>

int    count_bingo(std::vector<int> v)
{
    int c = 0;
    for (int x = 0; x < v.size(); x++)
    {
        if (v[x] > 0)
            c += v[x];
    }
    return (c);
}

int    horizontal_bingo(std::vector<int> v)
{
    for (int y = 0; y < v.size(); y = y +5)
    {
        for (int x = y; x % 5 < 5; x++)
        {
            if (v[x] > -1)
                break ;
            if (x % 5 == 4)
                return (count_bingo(v));
        }
    }
    return (0);
}

int     vertical_bingo(std::vector<int> v)
{
    for (int y = 0; y < 5; y++)
    {
        for (int x = x; x < 25 ; x = x +5)
        {
            if (v[x] > -1)
                break ;
            if (25 - x < 6)
                return (count_bingo(v));
        }
    }
    return (0);
}


int    bingo(std::vector<int> v)
{
    int     c;
    c = horizontal_bingo(v);
    if (c == 0)
        c = vertical_bingo(v);
    return (c);
}

int main()
{
    std::ifstream       myfile ("test.txt");
    std::vector<int>    vec;
    std::stringstream   S;
    std::string         line;
    std::vector<std::vector<int> > V;

    getline(myfile, line);
    for (int pos=0;line.find(',') != std::string::npos;)
    {
        pos = line.find(',');
        vec.push_back(stoi(line.substr(0, pos)));
        line.erase(0, pos + 1);
    }
    vec.push_back(stoi(line));
    S << myfile.rdbuf();
    for (int i = 0, x; S >> x; i++)
    {
        V.resize(i + 1);
        V[i].push_back(x);
        for (int j = 0;j < 24; j++)
        {
            S>>x;
            V[i].push_back(x);
        }
    }
    for (int i = 0; i < vec.size(); i++)
    {
        for (int y = 0; y < V.size(); y++)
        {
            for (int x = 0, c; x < 25; x++)
            {
                if (V[y][x] == vec[i])
                {
                    if (V[y][x] == 0)
                        V[y][x] = -1;
                    else 
                        V[y][x] *= -1;
                    c = bingo(V[y]);
                    if (c != 0){
                        std::cout << c * vec[i] << std::endl;
                        return (0);
                    }
                }
            }
        }
    }
    return 0;
}
