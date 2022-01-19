#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <fstream>
using namespace std;
struct node // struktura elementu listy
{
    int liczba;
    node *prew;
    node *next;
};

class lista // klasa lista
{
private:
    // atrybuty klasy lista
    node *begin;
    node *end;
    unsigned int count;
public:


    lista(); //konstruktor klasy lista
    ~lista(); //destruktor klasy lista

    // metody klasy lista
    int return_size();
    void push_front( int licz);
    void push_back( int licz);
    void pop_front();
    void pop_back();
    void insert(node *el,int licz);
    void removal (node *el);
    void size();
    node *find(int licz);
    void find_value(int licz,node *el);
    void wypisz();
    void lista_plik();
    void empty();

};

lista::lista() //konstruktor klasy lista
{
    begin = end = NULL;
    count=0;
}
lista::~lista(){ //destruktor klasy lista
while(count) pop_front();
}

int podaj_liczbe() // funkcja do podania liczby z klawiatury przez u¿ytkownika
{
    int liczba;
    while(true){
       cin>>liczba;
        if(!cin)
    {
       cin.clear();
       cin.sync();
    }
    else break;
    }
    return liczba;
}
int lista::return_size()
{
    return count; // zwraca wartoœæ atrybutu count
}
void lista::wypisz() //funkcja wypisuj¹ca listê
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
void lista::lista_plik() //funkcja do zapisu listy w pliku tekstowym
{
    node *p;
    ofstream plik("lista.txt");
    int i=1;

    p= begin;
    while(p)
    {
        plik<<"el["<<i<<"]="<<p->liczba<<"  ";
        p=p->next;
        i++;
    }
    plik.close();
}
void lista::push_front(int licz) //funkja dodaj¹ca element do listy na pocz¹tek listy
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
void lista::push_back(int licz) //funkja dodaj¹ca element do listy na pocz¹tek listy
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
void lista::insert(node *el,int licz) //funkja dodaj¹ca element do listy na podane miejsce w liscie
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
void  lista::removal (node *el) //funkcja usuwa podany element listy
{
    count--;
    if (el->prew) el->prew->next = el->next;
    else begin = el->next;
    if (el->next) el->next->prew = el->prew;
    else end= el->prew;
    delete el;
}

void lista::pop_front() //funkcja usuwa pierwszy element listy
{
    if(count!=0) removal(begin);
    else{ cout<<"Brak elementow w liscie"<<endl;
    getch();}
}
void lista::pop_back() //funkcja usuwa ostatni element listy
{
    if(count!=0) removal(end);
    else{ cout<<"Brak elementow w liscie"<<endl;
    getch();}
}

node *lista::find(int licz) //funkcja znajduje podany element w liœcie
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
   return p;
}

void lista::find_value(int licz, node *el) //funkcja wyœwietla wartoœc podanego elementu
{
    cout<<"element nr "<<licz<<" zawiera wartosc "<<el->liczba<<endl;
}

void lista::empty() //funkcja sprawdzaj¹ca czy lista jest pusta
{
    if(count==0) cout<<"lista jest pusta"<<endl;
    else cout<<"lista nie jest pusta"<<endl;
}
int main()
{
    int opcja=0;
    char plik;
    lista lit;
    do{
            system("CLS");
            lit.wypisz(); // wyœwietlenie listy
    cout<<endl<<endl;
    cout<<"Obsluga listy"<<endl; // wyswietlenie menu obs³ugi listy
    cout<<"1 - push_front"<<endl;
    cout<<"2 - push_back"<<endl;
    cout<<"3 - insert_on_position"<<endl;
    cout<<"4 - pop_front"<<endl;
    cout<<"5 - pop_back"<<endl;
    cout<<"6 - remove_from_position"<<endl;
    cout<<"7 - is_empty"<<endl;
    cout<<"8 - size"<<endl;
    cout<<"9 - find_position"<<endl;
    cout<<"10 - exit_program"<<endl;
    cout<<endl;
    cout<<"wybierz opcje: ";
    cin>>opcja; // podanie opcji

    switch(opcja) // obs³uga listy po wyborze opcji
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
            int element;
            cout<<"podaj numer pozycji gdzie umiescic element : ";
            do{
            element = podaj_liczbe();}while(element<1||element>(lit.return_size()+1));
            int liczba;
            cout<<"podaj liczbe do wpisania do listy: ";
            liczba = podaj_liczbe();
            if(element==lit.return_size()+1)
                lit.push_back(liczba);
            else
                lit.insert(lit.find(element),liczba);
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
            int element;
            cout<<"podaj numer elementu jaki chcesz usunac: ";
            do{
            element = podaj_liczbe();}while(element<1||element>lit.return_size());
            lit.removal(lit.find(element));
            break;
        }
        case 7:{
            lit.empty();
            getch();
            break;
        }
        case 8:{
            cout<<"Liczba elementow w liscie to: "<<lit.return_size();
            getch();
            break;
        }
        case 9:{
            int element;
            cout<<"podaj numer elementu jaki chcesz znalesc: ";
            do{
            element = podaj_liczbe();}while(element<1||element>lit.return_size());
            lit.find_value(element,lit.find(element));
            getch();
            break;
        }
        case 10:{
            cout<<"Czy chesz zapisac liste w pliku(y/n)";
            cin>>plik;
            if(plik=='y')
                lit.lista_plik();
            break;
        }
        default:{
            cout<<"BRAK OPCJI";
            getch();
            break;
        }
    }
    }while(opcja!=10);

    return 0;
}
