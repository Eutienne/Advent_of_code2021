#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

int main()
{
    std::ifstream myfile ("file.txt");
    std::string   line;
    int           x = 0;
    std::vector<int> V;

    while (getline(myfile, line))
        V.push_back(stoi(line));
    
    for (int i = 0; V[i + 3]; i++)
    {
        if (V[i] + V[i + 1] + V[i+2] < V[i+1] + V[i+2] + V[i+3])
            x++;
    }
    std::cout << x << std::endl;

    return (0);
}