#include <iostream>
#include <ctime>

using namespace std;

struct element 
{
    int number;
    element* prev;
    element* next;
};

void AddNext(element*& l, int value)
{
    element* el = new element;
    el->number = value;

    if (l == nullptr)
    {
        el->prev = el;
        el->next = el;
        l = el;
    }
    else
    {
        el->prev = l;
        el->next = l->next;
        l->next->prev = el;
        l->next = el;
    }
}

void AddBefore(element*& l, int value)
{
    element* el = new element;
    el->number = value;

    if (l == nullptr) 
    {
        el->prev = el;
        el->next = el;
        l = el;
    } 
    else 
    {
        el->prev = l->prev;
        el->next = l;
        l->prev->next = el;
        l->prev = el;
    }
}

void DelNext(element*& l, int value) 
{
    if (value!=0) 
    {
        element* temp = l->next;

        if (temp != l)
        {
            l->next = temp->next;
            temp->next->prev = l;

            if (temp == l->next)
            {
                l->next = l;
            }
            if (value == 1)
            {
                delete l; 
            }
            delete temp;
        }
    }
    else
    {
        cout << "List is empty" << endl;
    }
}

void DelBefore(element*& l, int value)
{
    if (value!=0)
    {
        element* temp = l->prev;

        if (temp != l)
        {
            l->prev = temp->prev;
            temp->prev->next = l;

            if (temp == l->prev)
            {
                l->prev = l;
            }
            if (value == 1)
            {
                l = nullptr; 
            }
            delete temp;
        }
    }
    else
    {
        cout << "List is empty" << endl;
    }
}

int Amount(element* l)
{
    if (l == nullptr)
    {
        return 0;
    }
        
    int coun = 0;
    element* temp = l->next;

    while (temp != l) 
    {
        coun++;
        temp = temp->next;
    }

    return coun + 1;
}

void show(const element* l)
{
    if (l != nullptr)
    {
        const element* temp = l;

          "List: ";

        do 
        {
            cout << temp->number << " ";
            temp = temp->next;
        } while (temp != l);
        cout << endl;
    }
    else
    {
        cout << "List is empty" << endl;
    }
}




int main()
{   
    srand(time(0));
    element *l = nullptr;
    int choice;
    int number;
    bool flag = 1;

    while(flag)
    {
        cout << "1. Add next element" << endl;
        cout << "2. Add before element" << endl;
        cout << "3. Delete next element" << endl;
        cout << "4. Delete before element" << endl;
        cout << "5. Amount of elements" << endl;
        cout << "6. Display" << endl;
        cout << "7. Exit" << endl;
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                int number=rand()%10;
                AddNext(l,number);
                break;
            }
            case 2:
            {
                int number=rand()%10;
                AddBefore(l,number);
                break;
            }
            case 3:
            {   
                if(Amount(l)==1)
                {
                    l=nullptr;
                }
                else if(Amount(l)>1)
                {
                    DelNext(l,Amount(l));
                }  
                break;
            }
            case 4:
            {
                if(Amount(l)==1)
                {
                    l=nullptr;
                }
                else if(Amount(l)>1)
                {
                    DelBefore(l,Amount(l));
                }  
                break;
            }
            case 5:
            {
                cout << "Amount: " << Amount(l) << endl;
                break;
            }
            case 6:
            {   
                show(l);
                break;
            }
            case 7:
            {
                flag = 0;
                break;
            } 
        }
    }
    return 0;
}