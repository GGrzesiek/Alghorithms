#include <iostream>
#include <ctime>
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

int top(element* stack)
{
    return stack->number;
}

void countEvenElements(element* stack,int wielkoscS)
{
    int count = 0;
    element* tempStack = nullptr;  

    for(int i = 0; i<wielkoscS;i++)
    {
        if ((top(stack) % 2 == 0)&&(top(stack)!=0))
        {
            cout << top(stack) << " na pozycji " << i << endl;
            count++; 
        }
        push(tempStack,top(stack));
        pop(stack);
    }
    for(int i = 0; i<wielkoscS;i++)
    { 
        push(stack,top(tempStack));
        pop(tempStack);  
    }
    cout << "Ilosc parzystych elementow: " << count << endl;
}

int main()
{
    int liczba;
    int wybor;
    bool flaga = 1;
    srand(time(0));
    element* stack=nullptr;
    int wielkoscS = 0;

    while(flaga)
    {   cout << "Co chcesz zrobić" << endl << " 1.Dodanie elementu do stacku" << endl << " 2.Usuniecie elementu ze stacku" << endl << " 3.Sprawdzenie czy stack jest pusty" << endl << " 4.Pobranie wartości ostatniego elementu" << endl << " 5.Usuniecie wszystkich elementow stacku" << endl << " 6.Policzenie parzystych elementow" << endl << " 7.Koniec programu" << endl;
        cin >> wybor;
        switch(wybor)
        {
            case 1:
            {   
                liczba = rand()%10;
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
                    cout << "Zbior nie jest pusty" << endl;
                }
                else
                {
                    cout << "Zbior jest pusty" << endl;
                }
                break;
            }
            case 4: 
            {
                cout << top(stack) << endl;
                break;
            }
            case 5:
            {
                for(int i = 0;i<wielkoscS;i++)
                {
                    pop(stack);
                }
                wielkoscS=0;
                break;
            }
            case 6:
            {
                countEvenElements(stack,wielkoscS);
            }
            case 7:
            {
                flaga = 0;
                break;
            }
        }  
    }   
    return 0;
}
