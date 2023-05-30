#include <iostream>
#include <ctime>
using namespace std;

struct element
{
    int number;
    element *next;
    element *prev;
};

struct single_list
{
    element *head;
    element *tail;
    int counter;
};

void add_tail(single_list &l,int value)
{
    element* el= new element;
    el-> number = value;
    el-> next = nullptr;
    if(l.tail!=nullptr)
    {
        l.tail->next=el;
    }
    else
    {
        l.head=el;
    }
    l.tail=el;
    l.counter++;
}
void add_head(single_list &l,int value)
{
    element* el= new element;
    el-> number = value;
    el-> next = l.head;
    l.head = el;
    if(l.tail==nullptr)
    {
        l.tail=el;
    }
    l.counter++;
}
void add_position(single_list &l,int value,int position)
{   
    if(position < 1 || position > l.counter + 1)
    {
        cout << "Nieprawidlowa pozycja" << endl;
        return;
    }
    else
    {   element* el= new element;
        el-> number = value;
        element* temp=l.head;
        for(int i=1;i<position-1;i++)
        {
            temp=temp->next;
        }
        el->next=temp->next;
        temp->next=el;
        l.counter++;
    }
}

void delete_tail(single_list &l)
{   
    if(l.counter == 0)
    {
        cout<<"Lista jest pusta"<<endl;
        return;
    }
    else
    {
        element* temp=l.tail;
        if(l.counter==1)
        {
            l.tail=nullptr;
            l.head==nullptr;
        }
        else
        {   element* bef_temp=l.head;
            for(int i=1;i<l.counter-1;i++)
            {
                bef_temp=bef_temp->next;
            }
            l.tail=bef_temp;
            l.tail->next=nullptr;
        }
        l.counter--;
        delete temp;
    }
}

void delete_head(single_list &l)
{   
    if(l.counter == 0)
    {
        cout<<"Lista jest pusta"<<endl;
        return;
    }
    else
    {
        element* temp=l.head;
        l.head=l.head->next;
        if(l.counter==1)
        {
            l.tail=nullptr;
        }
        delete temp;
        l.counter--;
    }
    
}

void delete_position(single_list &l,int position)
{   
    if(l.counter == 0)
    {
        cout<<"Lista jest pusta"<<endl;
        return;
    }
    else if(position < 1 || position > l.counter)
    {
        cout << "Nieprawidlowa pozytcja" << endl;
        return;
    }
    else
    {
        element* prev=l.head;
        for(int i=1;i<position-1;i++)
        {
            prev=prev->next;
        }
        element* temp=prev->next;
        prev->next=temp->next;
        delete temp;
        l.counter--;
    }
}
void print(single_list l)
{
    element* temp=l.head;
    for(int i=0;i<l.counter;i++)
    {
        cout<<temp->number<<", ";
        temp=temp->next;
    }
    cout<<endl;
}

bool isEmpty(single_list l)
{
    if(l.counter==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

float sred(single_list l)
{
    element* temp=l.head;
    float suma=0;
    for(int i=1;i<l.counter;i++)
    {
        suma+=temp->number;
        temp=temp->next;
        cout<<suma<<endl;
    }
    return suma/(l.counter-1);
}

int max(single_list l)
{
    element* temp=l.head;
    int max=temp->number;
    int i=1;
    int position=1;
    for(i;i<l.counter;i++)
    {
        if(temp->number>max)
        {
            max=temp->number;
            position=i;
        }
        temp=temp->next;
    }
    cout<<"pozycja elementu: "<<position<<endl;
      
    return max;
}
int main()
{
    single_list l;
    bool flaga=1;
    l.head = nullptr;
    l.tail = nullptr;
    l.counter = 0; 
    int wybor;
    srand(time(0));

    while(flaga)
    {   cout<<"Co chcesz zrobić"<<endl;
        cout<<" 1. Sprawdzenie czy lista jest pusta"<<endl;
        cout<<" 2. Dodanie elementu na koniec listy"<<endl;
        cout<<" 3. Dodanie elementu na początek listy"<<endl;
        cout<<" 4. Dodanie elementu na okreslona pozycje"<<endl;
        cout<<" 5. Usuniecie elementu z konca listy"<<endl;
        cout<<" 6. Usuniecie elementu z poczatku listy"<<endl;
        cout<<" 7. Usuniecie elementu z wybranej pozycji"<<endl;
        cout<<" 8. Pobranie pierwszego elementu"<<endl;
        cout<<" 9. Pobranie ostatniego elementu"<<endl;
        cout<<" 10. Policzenie sredniej"<<endl;
        cout<<" 11. Element maksymalny"<<endl;
        cout<<" 12. Wypisanie listy"<<endl;
        cout<<" 13. Koniec programu"<<endl;
        cin>>wybor;
        switch(wybor)
        {
            case 1:
            {   
                if(isEmpty(l))
                {
                    cout<<"Lista jest pusta"<<endl;
                }
                else
                {
                    cout<<"Lista nie jest pusta"<<endl;
                }
                break;
            }
            case 2:
            {   
                int liczba=rand()%10;
                add_tail(l,liczba);
                break;
            }
            case 3:
            {
                int liczba=rand()%10;
                add_head(l,liczba);
                break;
            }
            case 4:
            {
                int liczba=rand()%10;
                int pozycja;
                cout<<"Podaj pozycje"<<endl;
                cin>>pozycja;
                add_position(l,liczba,pozycja);
                break;
            }
            case 5:
            { 
                delete_tail(l);
                break;
            }
            case 6:
            {   
                delete_head(l);
                break;
            }
            case 7:
            {
                int pozycja;
                cout<<"Podaj pozycje"<<endl;
                cin>>pozycja;
                delete_position(l,pozycja);
                break;
            }
            case 8:
            {   if(isEmpty(l))
                {
                    cout << "Lista jest pusta" << endl;
                }
                else
                {
                    cout<<l.head->number<<endl;
                }
                break;
            }
            case 9:
            {   if(isEmpty(l))
                {
                    cout << "Lista jest pusta" << endl;
                }
                else
                {
                    cout<<l.tail->number<<endl;
                }
                break;
            }
            case 10:
            {   if(isEmpty(l))
                {
                    cout << "Lista jest pusta" << endl;   
                }
                else
                {
                    cout<< "Srednia: " << sred(l) <<endl;
                }
                break;
            }
            case 11:
            {   if(isEmpty(l))
                {
                    cout << "Lista jest pusta" << endl;

                }
                else
                {
                    cout << ", wartosc najwiekszego elementu: " << max(l) << endl;
                }
                break;
            }
            case 12:
            {   
                print(l);
                cout << "Rozmar listy: " << l.counter << endl;
                break;
            }
            case 13:
            {
                flaga=0;
                break;
            }
        }
    }   
}