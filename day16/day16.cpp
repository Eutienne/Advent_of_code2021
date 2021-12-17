
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

int version;

struct packet
{
    int id,version, bit;
};

packet    bit_version(std::string &s)
{
    packet  a;
    short   bit, i, x;

    for (i = 0, x = 2; i < 3; x--, i++)
    {
        if (s[i] == '1')
            bit |= 1 << x;
    }
    a.version = bit;
    bit = 0;
    // std::cout << bit << std::endl;
    for (i = 3, x = 2; i < 7; x--, i++)
    {
        if (s[i] == ' ')
            i++;
        std::cout << bit << std::endl;
        if (s[i] == '1')
        {
            std::cout << x << " " << i << std:: endl;
            bit |= 1 << x;
        }
    }
    a.id = bit;
    std::cout << a.id << " 1 " << std::endl;
    version += a.version;
    return std::move(a);    
}


int id_4(std::string s)
{
    int i, stop;
    for (i = 0, stop = 0; stop == 0; i = i + 6)
    {
        if (s[i] == ' ')
            i++;

        if (s[i] == '0')
            stop = 1;
    }
    for (; s[i] != ' '; i++);


    return (i +1);
}

int getoperator(std::string s)
{
    int i, x, bit;
    s[0] == '1' ? x = 10 : x = 14;

    for (i = 1, bit = 0; x >=0; x--, i++)
    {
        if (s[i] == ' ')
            i++;
        if (s[i] == '1')
            bit |= 1 << x; 
    }
    for (;bit >0; bit--, i++)
    {
        if (s[i] == ' ')
            i++;
    }


    return i;
}


int main(int argc, char** argv)
{
    std::ifstream       myfile (argv[1]);
    packet              a;
    std::string         line,s;
   
    getline(myfile, line);
    for (int i =0, tmp; i < line.size(); i++)
    {
        tmp = line[i] -48 < 10? line[i] - 48 : line[i] - 55;
        for (int j =3; j >=0; j--)
            s += tmp & 1 << j ? "1" : "0";
        s += " ";
    }
    for (; s.size() > 0;){
        a = bit_version(s);
        std::cout << s <<std::endl;
        s.erase(0, 7);
        if (a.id == 4)
            s.erase(0, id_4(s));
        else
            s.erase(0, getoperator(s));
        std::cout << s <<std::endl;
        return 0;
    }

        
        // else if (a.id == 0)
    // }
//    std::cout << line << std::endl;
   
}