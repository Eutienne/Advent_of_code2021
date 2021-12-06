#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <list> 

int main()
{
    std::ifstream       myfile ("file.txt");
    std::vector<int>    vec;
    std::stringstream   S;
    std::string         line;
    std::list<std::vector<std::vector<int> > list;
    char                j;
    int                 gamma = 0, epsilon = 0;

    S << myfile.rdbuf();
    vec.resize(4);
    j = ',';
    for (int i = 0; j == ','; i++)
    {
        if (i > 0)
            vec.resize(i * 2);
        S >> vec[i];
        S>> j;
        vec.resize(i + 1);
    }
    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << std::endl;
    S >> line;
    std::cout << line << std::endl;
    // std::cout << line << std::endl;

    /*
    while (S >> line)
        vec.push_back(stoi(line,0,2));
    
    for (int i =0, z; i < 12; i++)
    {
        z = 0;
        for (int j = 0; j < vec.size(); j++)
        {
            if (vec[j] & 1 << i)
                z++;
        }
        if (z > vec.size() / 2)
            gamma |= 1 << i;
        else
            epsilon |= 1 << i;
    }
    std::cout << gamma * epsilon << std::endl;
*/
    return 0;
}
