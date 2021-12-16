#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <memory>

std::vector<std::string>        v;
struct node
{
    int x, y, cost;
    struct node *p;
    node() : x(0), y(0), cost(0), p(NULL){}
    node(const node &n){
        *this = n;
    }
    node &   operator=(const node &n)
    {
        this->p = const_cast<node*>(&n);
        this->x = n.x;
        this->y = n.y;
        this->cost = n.cost;

        return *this;
    }
};
std::deque<std::unique_ptr<node> >         Viseted;
struct  F
{
    bool    operator()(node * a, node * b) const
    {
        return (!(a->cost + ((v.size() *5) - a->x) + ((v.size() *5) - a->y) < b->cost + ((v.size() *5) - b->x) + ((v.size() *5) - b->y)));
    }
};

std::priority_queue<node*, std::vector<node*>, F> open;
std::unordered_map<uint64_t, int>               Closed;

std::unique_ptr<node> make_node()
{
    std::unique_ptr<node> n = std::make_unique<node>();
    n->p = nullptr;
    return (std::move(n));
}


std::unique_ptr<node>  copyNode(const node & n){
    std::unique_ptr<node> copy(make_node());

    *copy = n;
    copy->p = const_cast<node*>(&n);
    return std::move(copy);
}

void movements(const node & n, std::string m)
{
    std::unique_ptr<node>    tmp = copyNode(n);
    uint64_t s;

    if (m == "R")
        tmp->x++;
    else if (m == "L")
        tmp->x--;
    else if (m == "U")
        tmp->y--;
    else
        tmp->y++;

    s = (1000*tmp->y) + tmp->x;
    if ((v[tmp->y % v.size()][tmp->x %v.size()] -48) + (tmp->x / v.size()) + (tmp->y/v.size()) > 9){
        tmp->cost += (v[tmp->y % v.size()][tmp->x %v.size()] -48) + (tmp->x / v.size()) + (tmp->y/v.size()) - 9;}
    else 
        tmp->cost += (v[tmp->y % v.size()][tmp->x %v.size()] -48) + (tmp->x / v.size()) + (tmp->y/v.size()); 

    
    auto it = Closed.find(s);
    if (it == Closed.end() || it->second > tmp->cost) {
        open.push(&(*tmp));
        if (it == Closed.end())
            Closed.insert(std::make_pair(s, tmp->cost));
        else
            it->second = tmp->cost;
        Viseted.push_back(std::move(tmp));
    }
}

void    A_star(){
    node    *n;
    std::unique_ptr<node> u = make_node();
    
    n = &(*u);
    open.push(n);
    Closed.insert(std::make_pair(0, 0));
    for (;n->x != (v.size() *5) -1 || n->y != (v.size() *5)-1; n = &(*open.top()))
    {
        open.pop();
        if (((!n->p) || n->p->x != n->x +1) && n->x < (v.size() *5) - 1)
            movements(*n, "R");
        if (((!n->p) || n->p->y != n->y -1) && n->y > 0)
            movements(*n, "U");
        if (((!n->p) ||n->p->y != n->y +1) && n->y < (v.size() *5) -1)
            movements(*n, "D");
        if (((!n->p) || n->p->x != n->x -1) && n->x > 0)
            movements(*n, "L");
    }
    std::cout << n->cost <<std::endl;
}


int main(int argc, char** argv)
{
    std::ifstream                   myfile (argv[1]);
    std::string                     line, s;
    
    for (; getline(myfile, line);)
        v.push_back(line);
    A_star();
}