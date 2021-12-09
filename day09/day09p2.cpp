
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <set>
#include <map>


int find_basin(std::vector<std::string> &v, int x, int y, std::multimap<int, int> & check)
{
    int                         counter = 1;
    

    for (auto it = check.find(x); it != check.end(); it++)
    {  
        if (it->first == x && it->second == y)
            return 0;
    }
    check.insert(std::pair<int, int>(x, y));

    if (v[y][x+1] && v[y][x] < v[y][x+1] && (v[y][x +1] - 48) != 9)
        counter += find_basin(v, x +1, y, check);
    if (v[y][x-1] && v[y][x] < v[y][x-1] && (v[y][x -1] - 48) != 9)
        counter += find_basin(v, x -1, y, check);
    if (v[y+1][x] && v[y][x] < v[y+1][x] && (v[y +1][x] - 48) != 9)
        counter += find_basin(v, x , y+1, check);
    if (v[y-1][x] && v[y][x] < v[y-1][x] && (v[y -1][x] - 48) != 9)
        counter += find_basin(v, x, y-1, check);
    return (counter);
}

int main()
{
    std::ifstream                       myfile ("file.txt");
    std::vector<std::string>            vec;
    std::string                         line;
    std::multiset<int, std::greater<int> >   basin;
    std::multimap<int, int >            check;
    int                                 counter;
    
 
    while (getline(myfile, line)){
        vec.push_back(line);
    }   
    myfile.close();
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
                basin.insert(find_basin(vec, x, y, check));
            check.clear();
        }
    }
    auto it = basin.begin();
    counter = *it;
    basin.erase(it);
    for (int i = 0; i < 2; i++){
        it = basin.begin();
        counter *= *it;
        basin.erase(it);
    }
    std::cout << counter << std::endl;
    return (0);
}