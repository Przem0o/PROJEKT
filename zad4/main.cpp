#include <iostream>
#include <conio.h>
#include <cstdlib>
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
    void empty();

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
    p->prew=NULL;
    p->next=begin;
    begin=p;
    count++;
    if (p->next) {p->next->prew = p;}
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
void lista::size()
{
    cout<<"Liczba elementow w liscie to: "<<count<<endl;
}
void lista::find(int licz)
{
   int i;
   node *p;
   if(licz<=(count/2))
   {
       p=begin;
       for(i=1;i!=licz;i++)
        p=p->next;
   }
   else
   {
       p=end;
       for(i=count;i!=licz;i--)
        p=p->prew;
   }
   cout<<"element nr "<<licz<<" zawiera wartosc "<<p->liczba<<endl;
}
void lista::empty()
{
    if(count==0) cout<<"lista jest pusta"<<endl;
    else cout<<"lista nie jest pusta"<<endl;
}
int main()
{
    int opcja=0;
    lista lit;
    do{
            system("CLS");
            lit.wypisz();
    cout<<endl<<endl;
    cout<<"Obsluga listy"<<endl;
    cout<<"1 - push_front"<<endl;
    cout<<"2 - push_back"<<endl;
    cout<<"3 - insert_on_position"<<endl;
    cout<<"4 - pop_front"<<endl;
    cout<<"5 - pop_back"<<endl;
    cout<<"6 - remove_on_position"<<endl;
    cout<<"7 - is_empty"<<endl;
    cout<<"8 - size"<<endl;
    cout<<"9 - find_position"<<endl;
    cout<<"10 - exit_program"<<endl;
    cout<<endl;
    cout<<"wybierz opcje: ";
    cin>>opcja;

    switch(opcja)
    {
        case 1:{
            int liczba;
            cout<<"podaj liczbe do wpisania do listy: ";
            liczba = podaj_liczbe();
            lit.push_front(liczba);
            break;
        }
        case 2:{
            int liczba;
            cout<<"podaj liczbe do wpisania do listy: ";
            liczba = podaj_liczbe();
            lit.push_back(liczba);
            break;
        }
        case 3:{
            cout<<"to implement"<<endl;
            getch();
            break;

        }
        case 4:{
            lit.pop_front();
            break;
        }
        case 5:{
            lit.pop_back();
            break;
        }
        case 6:{
            cout<<"to implement"<<endl;
            getch();
            break;
        }
        case 7:{
            lit.empty();
            getch();
            break;
        }
        case 8:{
            lit.size();
            getch();
            break;
        }
        case 9:{
            cout<<"to implement"<<endl;
            getch();
            break;
        }
        case 10:{
            cout<<"wyjscie z programu";
            getch();
            break;
        }
        default:{
            cout<<"BRAK OPCJI";
            break;
        }
    }
    }while(opcja!=10);
    return 0;
}
