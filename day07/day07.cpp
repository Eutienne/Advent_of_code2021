
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

int main()
{
    std::ifstream       myfile ("file.txt");
    std::vector<int>    vec;
    std::string         line;
    int                 fule;
    int                 tmp;

    getline(myfile, line);
    for (int pos=0;line.find(',') != std::string::npos;)
    {
        pos = line.find(',');
        vec.push_back(stoi(line.substr(0, pos)));
        line.erase(0, pos + 1);
    }
    vec.push_back(stoi(line));
    fule = -1;
    for (int x = 0; x < vec.size(); x++)
    {
        tmp = 0;
        for (int y =0; y < vec.size(); y++)
        {
            if (vec[x] != vec[y])
                tmp += abs(vec[x] - vec[y]);
        }
        if (tmp < fule || fule == -1)
            fule = tmp;
    }
    std::cout << fule << std::endl;
}