#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

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
    node *find(int licz);
    void find_value(int licz,node *el);
    void wypisz();
    void lista_plik();
    void empty();

};

#endif // LISTA_H_INCLUDED
