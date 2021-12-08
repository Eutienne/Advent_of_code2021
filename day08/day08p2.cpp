
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>


// 0 2 3 5 6 9
//  5 2 3       5
//  9 6 0       6
// 1                0 3  9
// 4

// check of 1 er in zit --> ja
//blijven er 3 nummers over 0, 3, 9
// heeft de string 5 karakters, dan is het een 3, anders moet je kijken of de cijfers van 4 hier allemaal in voorkomen.
// ja dan is het een 9, anders een 0.

// check of 1 er in zit --> nee
// zijn er 3 nummer over, 2,5,6
// heeft de string 6 karakters, dan is het een 6
// de karakters die in 4 meer zitten dan 1, moet je checken of die in het getal zitten. ja -> dan is het een 5 anders een 2

struct nbrs
{
    std::string a,b;

    void    set_num(std::string s){
        std::vector<std::string> tmp;
        a = "";
        b = "";

        for (int i = 0, pos = 0; i < 10; i++)
        {
            pos = s.find(' ');
            b = s.substr(0, pos);
            if (strlen(b.c_str()) == 4)
                tmp.push_back(s.substr(0, pos));
            else if (strlen(b.c_str()) == 2)
                a = s.substr(0, pos);
            b ="";
            if (a != "" && tmp.size() == 1 )
                break ;
            s.erase(0, pos + 1);
        }
        for (int x = 0; x < 4; x++)
        {
            if (tmp[0][x] != a[0] && tmp[0][x] != a[1])
                b += tmp[0][x];
            if (x == 3)
                return ;
        }
    }
};

nbrs                n;


int check2(std::string s)
{
    if (strlen(s.c_str()) == 6)
        return (6);
    else if (s.find(n.b[0]) != std::string::npos && s.find(n.b[1]) != std::string::npos)
        return (5);
    return 2;
}

int check1(std::string s)
{
    if (strlen(s.c_str()) == 5)
        return (3);
    else if (s.find(n.b[0]) != std::string::npos && s.find(n.b[1]) != std::string::npos)
        return (9);
    return 0;
}

int decode_nbr(std::string s)
{
    if (strlen(s.c_str()) == 2)
        return (1);
    else if (strlen(s.c_str()) == 3)
        return (7);
    else if (strlen(s.c_str()) == 4)
        return (4);
    else if (strlen(s.c_str()) == 7)
        return (8);
    else if (s.find(n.a[0]) != std::string::npos && s.find(n.a[1]) != std::string::npos)
        return (check1(s));
    else
        return (check2(s));
    
    return 0;
    
}

int main()
{
    std::ifstream       myfile ("ronald.txt");
    std::vector<int>    vec;
    std::string         line, tmp;
    int                 counter = 0;
    
    
    for (int pos; getline(myfile, line);)
    {
        pos = line.find('|');
        n.set_num(line.substr(0, pos -1));
        line.erase(0, pos + 1);
        pos = line.find(' ');
        line.erase(0, pos + 1);
        for (int i = 0, x = 0; i < 4; i++)
        {
            x *= 10;
            pos = line.find(' ');
            tmp = line.substr(0, pos);
            x += decode_nbr(tmp);
            line.erase(0, pos + 1);
            if (i == 3)
            {
                std::cout << x << std::endl;
                counter += x;
            }
        }

    }
    std::cout << counter <<std::endl;
}