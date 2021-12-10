
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <set>

std::multiset<long>  incomplete;
long                 z;

long                 char_count(char c)
{
    if (c == '(')
        return 1;
    else if (c == '[')
        return 2;
    else if (c == '{')
        return 3;
    return 4;
}

int open_closed(std::string &line, int x)
{
    char c;
    int i = x + 1;

    c = line[x];
    for (;i < line.size(); i++)
    {
        if (c == '(' && line[i] == ')')
            return (i);
        else if (c == '[' && line[i] == ']')
            return (i);
        else if (c == '{' && line[i] == '}')
            return (i);
        else if (c == '<' && line[i] == '>')
            return (i);
        else if (line[i] == ')' || line[i] == ']' || line[i] == '}' || line[i] == '>')
            return(line.size() +1);
        else
            i = open_closed(line, i);
        if (i > line.size())
            return (i);
    }
    if (i == line.size())
    {
        z *= 5;
        z += char_count(c);
        return (i -1);
    }
    return (i);
}

int main(int argc, char** argv)
{
    std::ifstream       myfile (argv[1]);
    std::string         line;
    int                 counter = 0;
    
    for (int x; getline(myfile, line);)
    {
        z = 0;
        x = 0;
        x = open_closed(line, 0);
        while (x > 0 && x < line.size())
            x = open_closed(line, x +1);
        if (z > 0)
            incomplete.insert(z);
    }
    auto it = incomplete.begin();
    std::advance(it, incomplete.size() / 2);
    
    std::cout << *it <<std::endl;
}