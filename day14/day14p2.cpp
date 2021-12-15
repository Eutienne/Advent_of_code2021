
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <unordered_map>

std::unordered_map<char, long >                  count;
std::unordered_map<std::string, std::string >   m;

void    counts()
{
    long high = 0;
    long low = 2147483647999999999;

    for (auto i : count)
    {
        if (i.second < low)
            low = i.second;
        if (i.second > high)
            high = i.second;
    }
    std::cout << high - low << " h" << high << " l" << low << std::endl;

}

void    insert_letters(std::unordered_map<std::string, long> &map)
{
    std::unordered_map<std::string, long>            tmp;
    std::string                                     s, t;

    for (auto i: map)
    {
        s = i.first;
        t = s;
        count[m[s][0]] += i.second;
        t[0] = m[s][0];
        s[1] = m[s][0];
        if (tmp.find(s) == tmp.end()){
            tmp.insert(std::make_pair(s, i.second));
        }
        else
            tmp[s] += i.second;
        if (tmp.find(t) == tmp.end())
            tmp.insert(std::make_pair(t, i.second));
        else
            tmp[t] += i.second;
    }
    map = tmp;
}


int main(int argc, char** argv)
{
    std::ifstream                                   myfile (argv[1]);
    std::unordered_map<std::string, long>            map;
    std::string                                     line, s;
    
    for (; getline(myfile, line);)
    {
        if (line == "")
            break ;
       s = line;
    }
    for (std::string c; getline(myfile, line);)
    {
        m.insert(std::make_pair(line.substr(0, 2), line.substr(6,7)));
        c = line.substr(6,7);
        if (count.find(c[0]) == count.end())
            count.insert(std::make_pair(c[0],0));
    }
    for (int i = 0, x = s.size(); i +1 < x; i++)
    {
        line = s.substr(0, 2);
        count[line[0]]++;
        if (map.find(line) == map.end())
            map.insert(std::make_pair(line, 1));
        else
            map[line]++;
        s.erase(0,1);
    }
    count[line[1]]++;
    for (int i = 0; i < 40; i++)
        insert_letters(map);

    counts();
}