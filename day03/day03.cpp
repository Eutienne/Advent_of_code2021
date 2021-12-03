#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

int main()
{
    std::ifstream       myfile ("file.txt");
    std::vector<int>    vec;
    std::stringstream   S;
    std::string         line;
    int                 gamma = 0, epsilon = 0;

    S << myfile.rdbuf();
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

    return 0;
}
