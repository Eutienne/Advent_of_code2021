
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <unordered_map>

// for (auto i: map)
//     std::cout << "key   " << i->first << "  val " << i->second << std::endl;

std::unordered_map<char, int >                  count;
std::unordered_map<std::string, std::string >   m;

void    counts()
{
    int high = 0;
    int low = 2147483647;

    for (auto i : count)
    {
        if (i.second < low)
            low = i.second;
        if (i.second > high)
            high = i.second;
    }
    std::cout << high - low << " h" << high << " l" << low << std::endl;

}

void    insert_letters(std::vector<std::string> &v)
{
    std::vector<std::string>                        tmp;
    std::string                                     s, t;

    
    for (int i = 0; i < v.size(); i++)
    {
        s = v[i];
        count[m[s][0]]++;
        t = s;
        t[1] = m[s][0];
        tmp.push_back(t);
        s[0] = m[s][0];
        tmp.push_back(s);
        // std::cout << count[m[s][0]] << " ";
        // std::cout << count[m[s][0]] << std::endl;
    }
    v = tmp;
}


int main(int argc, char** argv)
{
    std::ifstream                                   myfile (argv[1]);
    std::vector<std::string>                        vec;
    std::string                                     line, s;

    
    for (; getline(myfile, line);)
    {
        if (line == "")
            break ;
       s = line;
    }
    for (int i =0; i < s.size(); i++)
    {
        if (count.find(s[i]) == count.end())
        {
            count.insert(std::make_pair(s[i],0));
            count[s[i]]++;  
        }
        else
            count[s[i]]++;
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
        vec.push_back(line);
        s.erase(0,1);
    }
    for (int i = 0; i < 10; i++)
        insert_letters(vec);

    counts();
}