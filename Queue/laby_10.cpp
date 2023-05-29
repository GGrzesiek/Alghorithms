#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>
#include <cctype>

using namespace std;

struct element
{
    char character;
    element* next;
};

struct queue
{
    element* head;
    element* tail;
};
void push(queue &q,char value)
{
    element* el=new element;
    el->character=value;
    el->next=nullptr;
    if(q.tail!=nullptr)
    {
        q.tail->next=el;
        q.tail=el;
    }
    else
    {
        q.head=el;
        q.tail=el;
    }
    
}

void pop(queue &q)
{   element* temp=q.head;
    q.head=q.head->next;
    delete temp;
    if(q.head==nullptr)
    {
        q.tail=nullptr;
    }
}

bool isEmpty(queue q)
{
    if(q.head==nullptr)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char first(queue q)
{ 
    return q.head->character; 
}
 
void wczytaj_z_pliku(string nplik, queue& kolejka) {
    ifstream plik(nplik);
    if (plik.good()) {
        string linia;
        while (getline(plik, linia))
        {
            for (char znak : linia) 
            {
                if (isupper(znak)) {
                    push(kolejka, znak);
                }
            }
        }
        plik.close();
    }
}
int main()
{
    queue q;
    q.head=nullptr;
    q.tail=nullptr;
    
    ifstream plik;
    plik.open("znaki2.txt");
    
    
    bool flaga=1; 
    int wybor;
    int wielkoscK=0;
    char znak;
    int liczba;
    while(flaga)
    {
        if(plik.good())
        {
            cout<<"Co chcesz zrobić"<<endl<<" 1.Dodanie elementu do kolejki"<<endl<<" 2.Usuniecie elementu z kolejki"<<endl<<" 3.Sprawdzenie czy kolejka jest pusta"<<endl<<" 4.Pobranie wartości pierwszego elementu"<<endl<<" 5.Usuniecie wszystkich elementow kolejki"<<endl<<" 6.pobranie znakow z pliku"<<endl<<" 7.Koniec programu"<<endl;
            cin>>wybor;
            switch(wybor)
            {
                case 1:
                { 
                    liczba=rand()%128;
                    char value =char(liczba);
                    push(q,liczba);
                    wielkoscK++;
                    break;
                }
                case 2:
                {
                    if(isEmpty(q))
                    {
                       cout<<"Kolejka jest pusta"<<endl; 
                    }
                    else
                    {   
                        pop(q);
                        wielkoscK--;
                    }
                    break;
                }
                case 3:
                {
                    if(isEmpty(q))
                    {
                        cout<<"Kolejka jest pusta"<<endl;
                    }
                    else
                    {
                        cout<<"Kolejka nie jest pusta"<<endl;
                    }
                    break;
                }
                case 4:
                {   if(isEmpty(q))
                    {
                        cout<<"Kolejka jest pusta"<<endl;
                    }
                    else
                    {
                        cout<<first(q)<<endl;
                    }
                break;                     
                }
                case 5:
                {
                    for(int i=0;i<wielkoscK;i++)
                    {
                        pop(q);
                    }
                    wielkoscK=0;
                    break;
                }
                case 6:
                {
                    wczytaj_z_pliku("znaki2.txt", q);
                    break;
                }
                case 7:
                {
                    flaga=0;
                    break;
                }
            }
        }
    }
}