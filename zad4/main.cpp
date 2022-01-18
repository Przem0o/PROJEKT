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
    void insert(node *el,int licz);
    void removal (node *el);
    void size();
    void find(int licz);
    void wypisz();

};

lista::lista()
{
    begin = end = NULL;
    count=0;
}
lista::~lista(){
while(count) pop_front();
}

int podaj_liczbe()
{
    int liczba;
    cout<<"podaj liczbe:";
    cin>>liczba;
    return liczba;
}

void lista::wypisz()
{
    node *p;

    cout<<"elementy w liscie to: ";
    p= begin;
    while(p)
    {
        cout<<p->liczba<<" ";
        p=p->next;
    }
}

void lista::push_front(int licz)
{
    node *p;

    p = new node;
    p->liczba=licz;
    p->next=NULL;
    p->prew=begin;
    begin=p;
    count++;
    if (p->next) p->next->prew =p;
    else end=p;
}
void lista::push_back(int licz)
{
    node *p;

    p = new node;
    p->liczba=licz;
    p->next=NULL;
    p->prew=end;
    end=p;
    count++;
    if (p->prew) p->prew->next =p;
    else begin=p;
}
void lista::insert(node *el,int licz)
{
    node *p;

    if( el==begin) push_front(licz);
    else
    {
        p = new node;
        p->liczba =licz;
        p->next=el;
        p->prew = el->prew;
        count++;
        el->prew->next = p;
        el->prew =p;
    }
}
void  lista::removal (node *el)
{
    count--;
    if (el->prew) el->prew->next = el->next;
    else begin = el->next;
    if (el->next) el->next->prew = el->prew;
    else end= el->prew;
    delete el;
}

void lista::pop_front()
{
    if(count) removal(begin);
    else cout<<"Brak elementow"<<endl;
}
void lista::pop_back()
{
    if(count) removal(end);
    else cout<<"Brak elementow"<<endl;
}
void size()
{
    cout<<"Liczba elementow w liscie to: "<<count;
}
void find(int licz)
{
   int i=1;
   if(licz<count)
}
int main()
{
    return 0;
}
