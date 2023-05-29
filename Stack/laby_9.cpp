#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
using namespace std;
struct element
{
    int number;
    element* next;
};

void push(element* &stack,int value)
{
    element* el=new element;
    el->number=value;
    el->next=stack;
    stack=el;
}
void push2(element* &stack,char value)
{
    element* el=new element;
    el->number=value;
    el->next=stack;
    stack=el;
}
void pop(element* &stack)
{
    stack=stack->next;
}

bool isEmpty(element* &stack)
{
    if(stack==nullptr)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int top(element* &stack)
{
   return stack->number;
}

char top2(element* &stack)
{
    return stack->number;
}

void rev()
{
    element* stack = nullptr;
    ifstream plik;
    plik.open("znaki1.txt");
    if(plik.good())
    {
        string linia;
        int dlugosc=0;
        int wielkoscS=0;
        while(getline(plik,linia))
        {
            dlugosc=linia.length();
            for(int i=0;i<dlugosc;i++)
            {   
                push2(stack,linia[i]);
                wielkoscS++;
            }
            
            

            for(int j=0;j<wielkoscS;j++)
            {
                cout << top2(stack);
                pop(stack);  
            }
            cout << "\n";
            wielkoscS=0;
        }
        plik.close();
    }
    else
    {
        cout<<"Nie udalo sie otworzyc pliku"<<endl;
    }
}

int main()
{   int liczba;
    int wybor;
    bool flaga=1;
    srand(time(0));
    element* stack=nullptr;
    int wielkoscS=0;
    while(flaga)
    {   cout<<"Co chcesz zrobić"<<endl<<" 1.Dodanie elementu do stosu"<<endl<<" 2.Usuniecie elementu ze stosu"<<endl<<" 3.Sprawdzenie czy stos jest pusty"<<endl<<" 4.Pobranie wartości ostatniego elementu"<<endl<<" 5.Usuniecie wszystkich elementow stosu"<<endl<<" 6.Odwrocenie znakow z pliku"<<endl<<" 7.Koniec programu"<<endl;
        cin>>wybor;
        switch(wybor)
        {
            case 1:
            {   
                liczba=rand()%10;
                push(stack,liczba);
                wielkoscS++;
                break;
            }
            case 2:
            {
                pop(stack);
                wielkoscS--;
                break;
            }
            case 3:
            {
                if(isEmpty(stack))
                {
                    cout<<"Zbior nie jest pusty"<<endl;
                }
                else
                {
                    cout<<"Zbior jest pusty"<<endl;
                }
                break;
            }
            case 4:
            {
                cout<<top(stack)<<endl;
                break;
            }
            case 5:
            {
                for(int i=0;i<wielkoscS;i++)
                {
                    pop(stack);
                }
                wielkoscS=0;
                break;
            }
            case 6:
            {
                rev();
                break;
            }
            case 7:
            {
                flaga=0;
                break;
            }
        }  
    }   
    return 0;
}