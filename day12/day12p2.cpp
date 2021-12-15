
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

std::set<std::vector<std::string> > paths;

void    dfs( std::multimap<std::string, std::pair<std::string, int> > &c, std::string key, std::vector<std::string> v, int t)
{
    if (std::find(v.begin(), v.end(), key) != v.end() && key[0] > 96 && key[0] < 123)
        t = 1;
    v.push_back(key);
    if (key == "end")
    {
        for (int i =0; i < v.size(); i++)
            std::cout << v[i] << " ";
        std::cout << std::endl;
        paths.insert(v);
        return ;
    }
    auto it1 = c.lower_bound(key);
    auto it2 = c.upper_bound(key);
    for (;it1 != it2; it1++)
    {
        if (it1->second.first != "start")
        {
            if (it1->second.first[0] > 96 && it1->second.first[0] < 123 && (t == 0 || std::find(v.begin(), v.end(), it1->second.first) == v.end()) && it1->second.first != "end")
                dfs(c, it1->second.first, v, t);
            else if ((it1->second.first[0] > 64 && it1->second.first[0] < 91) || it1->second.first == "end")
                dfs(c, it1->second.first, v, t);
        }
    }

}

int main(int argc, char** argv)
{
    std::ifstream       myfile (argv[1]);
    std::string         line;
    std::multimap<std::string, std::pair<std::string, int> >              chamber;
    std::vector<std::string>    v;

    
    for (int pos; getline(myfile, line);)
    {
        std::string     s1, s2;

        pos = line.find('-');
        s1 = line.substr(0, pos);
        line.erase(0, pos + 1);
        s2 = line;
        chamber.insert(std::make_pair(s1, std::make_pair(s2, 0)));
        chamber.insert(std::make_pair(s2, std::make_pair(s1, 0)));
    }
    
    dfs(chamber, "start", v, 0);

    std::cout << paths.size() <<std::endl;
//     for (auto it = chamber.begin(); it != chamber.end(); it++){
//         std::cout << it->first << " " << it->second.first << " " << it->second.second << std::endl;
//    }
}