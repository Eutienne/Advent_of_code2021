
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

int send_value(std::string &line, int x)
{
    if (line[x] == ')')
        return (-3);
    else if (line[x] == ']')
        return (-57);
    else if (line[x] == '}')
        return (-1197);
    else
        return (-25137);
}

int open_closed(std::string &line, int x)
{
    char c;
    int i = x + 1;

    c = line[x];
    for (;i < line.size() && i > 0; i++)
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
            return(send_value(line, i));
        else
            i = open_closed(line, i);
        if (i < 0)
            return (i);
    }
    return (i);
}

int main(int argc, char** argv)
{
    std::ifstream       myfile (argv[1]);
    std::vector<int>    vec;
    std::string         line;
    int                 counter = 0;
    
    for (int x; getline(myfile, line);)
    {
        x = 0;
        x = open_closed(line, 0);
        while (x > 0 && x < line.size())
            x = open_closed(line, x +1);
        if (x < 0)
            counter -= x;
    }

    std::cout << counter <<std::endl;
}