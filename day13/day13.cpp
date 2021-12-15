
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

void    fold_y(std::vector<std::vector<char> > &v, int fold)
{
    int y = (v.size() -1) - (fold * 2);

    for (int i = v.size() - 1; i >= fold; i--, y++)
    {
        for (int j =0; j < v[i].size(); j++)
        {
            if (v[i][j] == '#' && y > -1)
                v[y][j] = '#';
        }
        v.pop_back();
    }
}

void    fold_x(std::vector<std::vector<char> > &v, int fold)
{
    int x = (v[0].size() -1) - (fold * 2);

    for (int i = v[0].size() - 1; i >= fold; i--, x++)
    {
        for (int j =0; j < v.size(); j++)
        {
            if (v[j][i] == '#' && x > -1)
                v[j][x] = '#';
            v[j].erase(v[j].begin() + i);
        }
    }
}

int main(int argc, char** argv)
{
    std::ifstream       myfile (argv[1]);
    std::vector<std::pair<int, int> >    vec;
    std::vector<std::vector<char> >       v;
    int                 length, width, dots = 0;
    std::string         line;
    std::string         c;
    for (int pos, x, y; getline(myfile, line);)
    {
        if (line == "")
            break ;
        pos = line.find(",");
        x = stoi(line.substr(0, pos));
        if (x > width)
            width = x;
        line.erase(0, pos + 1);
        y = stoi(line);
        if (y > length)
            length = y;
        vec.push_back(std::make_pair(y,x));
    }
    v.resize(length + 1);
    for (int i = 0; i < length + 1; i++)
        v[i].resize(width +1);
    for (int i = 0; i < vec.size(); i++)
        v[vec[i].first][vec[i].second] = '#';
    
    for (int pos, x; getline(myfile, line);)
    {
        pos = line.find("=");
        c = line.substr(pos -1, pos);
        line.erase(0, pos + 1);
        x = stoi(line);
        if (c[0] == 'x')
            fold_x(v, x);
        else
            fold_y(v,x);
        break ;
    }
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j]){
                std::cout << "#" << " ";
                dots++;}
            else
                std::cout << ". ";
        }
            std::cout << std::endl;
    }
    std::cout << dots <<std::endl;
}