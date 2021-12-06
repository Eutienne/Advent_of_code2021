#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

int main()
{
    std::ifstream       myfile ("file.txt");
    std::vector<long long>    vec, tmp;
    std::string         line;
    long long                x;

    getline(myfile, line);
    for (int pos=0;line.find(',') != std::string::npos;)
    {
        pos = line.find(',');
        vec.push_back(stoi(line.substr(0, pos)));
        line.erase(0, pos + 1);
    }
    vec.push_back(stoi(line));
    tmp.resize(9);
    for (int i = 0; i < vec.size(); i++)
    {
        tmp[vec[i]]++;
    }
    vec = tmp;
    tmp.clear();
    tmp.resize(9);
    for (int i = 0; i < 256; i++)
    {
        for (long j = 8; j > -1; j--)
        {
            if (j != 0)
                tmp[j - 1] = vec[j];
            else
            {
                tmp[8] = vec[0];
                tmp[6] += vec[0];
            }
        }
        vec = tmp;
        tmp.clear();
        tmp.resize(9);
    }
    x = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        x += vec[i];
        std::cout << vec[i] << std::endl;
    }
    std::cout << vec.size() << std::endl;
    std::cout << x << std::endl;
    return 0;
}