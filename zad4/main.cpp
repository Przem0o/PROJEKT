#include <iostream>

using namespace std;
struct node
{
    int liczba;
    node *prew;
    node *next;
};

class lista
{
public:
    node *begin;
    node *end;
    unsigned int count;

    lista();
    ~lista();

    void push_front( int licz);
    void push_back( int licz);
    void pop_front();
    void pop_back();
    void

};
int main()
{
    return 0;
}
