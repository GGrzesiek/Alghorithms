#include <iostream>
#include <ctime>
using namespace std;

struct element
{
    int number;
    element *next;
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
    l.tail=el;
}
else
{
    l.head=el;
    l.tail=el;
}
}
void add_head(single_list &l,int value)
{element* el= new element;
el-> number = value;
el-> next = nullptr;
l.head=el;
if(l.tail!=nullptr)
{
l.tail=el;
}
}
void add_position(single_list &l,int value,int position)
{
    element* el= new element;
    el-> number = value;
    el-> next = nullptr;
    element* temp=l.head;
    for(int i=1;i<position-1;i++)
    {
        temp=temp->next;
    }
    el->next=temp->next;
    temp->next=el;
}
void delete_tail(single_list &l)
{   element* temp=l.tail;
    if(l.counter==1)
    {
        l.tail=nullptr;
        l.head==nullptr;
    }
    else
    {
        element* bef_temp=l.head;
        for(int i=1;i<l.counter;i++)
        {
            bef_temp=bef_temp->next;
        }
        l.tail=bef_temp;
        l.tail->next=nullptr;
    }
    delete temp;
}
void delete_head(single_list &l)
{
    element* temp=l.head;
    l.head=l.head->next;
    if(l.counter==1)
    {
        l.tail=nullptr;
    }
    delete temp;
}
void delete_position(single_list &l,int position)
{
    element* temp=l.head;
    for(int i=1;i<position-1;i++)
    {
        temp=temp->next;
    }
    element* temp2=temp->next;
    temp->next=temp2->next;
    delete temp2;
}
void print(single_list l)
{
    element* temp=l.head;
    for(int i=1;i<l.counter;i++)
    {
        cout<<temp->number<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

bool isEmpty(single_list l)
{
    if(l.head==nullptr)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    single_list l;
    bool flaga=1; 
    int wybor;
    srand(time(0));

    while(flaga)
    {   cout<<"Co chcesz zrobić"<<endl;
        cout<<" 1.Sprawdzenie czy lista jest pusta"<<endl;
        cout<<" 2.Dodanie elementu na koniec listy"<<endl;
        cout<<" 3.Dodanie elementu na początek listy"<<endl;
        cout<<" 4.Dodanie elementu na okreslona pozycje"<<endl;
        cout<<" 5.Usuniecie elementu z konca listy"<<endl;
        cout<<" 6.Usuniecie elementu z poczatku listy"<<endl;
        cout<<" 7.Usuniecie elementu z wybranej pozycji"<<endl;
        cout<<" 8.Pobranie pierwszego elementu"<<endl;
        cout<<" 9.Pobranie ostatniego elementu"<<endl;
        cout<<" 10.Policzenie sredniej"<<endl;
        cout<<" 11.Element maksymalny"<<endl;
        cout<<" 12.Koniec programu"<<endl;
        cin>>wybor;
        switch(wybor)
        {
            case 1:
            {   
                if(isEmpty(l))
                {
                    cout<<"Lista nie jest pusta"<<endl;
                }
                else
                {
                    cout<<"Lista jest pusta"<<endl;
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
            {   if(isEmpty)
                {
                    cout<<"Lista jest pusta"<<endl;
                }
                else
                {
                    delete_tail(l);
                }
                break;
            }
            case 6:
            {   if(isEmpty)
                {
                    cout<<"Lista jest pusta"<<endl;
                }
                else
                {
                    delete_head(l);
                }
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
            {
                cout<<l.head->number<<endl;
                break;
            }
            case 9:
            {
                cout<<l.tail->number<<endl;
                break;
            }
            case 10:
            {
                element* temp=l.head;
                int suma=0;
                for(int i=1;i<l.counter;i++)
                {
                    suma+=temp->number;
                    temp=temp->next;
                }
                cout<<suma/l.counter<<endl;
                break;
            }
            case 11:
            {
                element* temp=l.head;
                int max=0;
                for(int i=1;i<l.counter;i++)
                {
                    if(temp->number>max)
                    {
                        max=temp->number;
                    }
                    temp=temp->next;
                }
                cout<<max<<endl;
                break;
            }
            case 12:
            {
                flaga=0;
                break;
            }
        }
    }   
}