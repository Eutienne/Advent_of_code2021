#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

int main()
{
    std::ifstream       myfile ("file.txt");
    std::vector<int>    vec, vec2, tmp1, tmp2;
    std::stringstream   S;
    std::string         line;

    S << myfile.rdbuf();
    while (S >> line)
        vec.push_back(stoi(line,0,2));

    vec2 = vec;

    for (int i =11; vec.size() > 1; i--)
    {
        for (int j = 0; j < vec.size(); j++)
        {
            if (vec[j] & (1 << i))
                tmp1.push_back(vec[j]);
            else
                tmp2.push_back(vec[j]);
        }
        if (tmp1.size() >= tmp2.size())
            vec = tmp1;
        else
            vec = tmp2;
        tmp1.clear(); tmp2.clear();
    }

    for (int i =11; vec2.size() > 1; i--)
    {
        for (int j = 0; j < vec2.size(); j++)
        {
            if (vec2[j] & (1 << i))
                tmp1.push_back(vec2[j]);
            else
                tmp2.push_back(vec2[j]);
        }
        if (tmp2.size() <= tmp1.size())
            vec2 = tmp2;
        else
            vec2 = tmp1;
        tmp1.clear(); tmp2.clear();
    }
    std::cout << vec2[0] << std::endl;
    std::cout << vec[0] << std::endl;
    std::cout << vec[0] * vec2[0] << std::endl;

    return 0;
}
