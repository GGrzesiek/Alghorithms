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
        cout << "Incorrect index" << endl;
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
        cout << "List is empty" << endl;
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
        cout << "List is empty" << endl;
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
        cout << "List is empty" << endl;
        return;
    }
    else if(position < 1 || position > l.counter)
    {
        cout << "Incorrect position" << endl;
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
        cout << temp->number<<", ";
        temp=temp->next;
    }
    cout << endl;
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

float avg(single_list l)
{
    element* temp=l.head;
    float sum=0;
    for(int i=1;i<l.counter;i++)
    {
        sum+=temp->number;
        temp=temp->next;
    }
    return sum/(l.counter-1);
}

int max(single_list l)
{
    element* temp=l.head;
    int max=temp->number;
    int i=1;
    int position=i;
    for(i;i<l.counter;i++)
    {
        if(temp->number>max)
        {
            max=temp->number;
            position=i;
        }
        temp=temp->next;
    }
    cout << "position : "<< position << endl;
      
    return max;
}

int main()
{
    single_list l;
    bool flag=1;
    l.head = nullptr;
    l.tail = nullptr;
    l.counter = 0; 
    int choice;
    srand(time(0));

    while(flag)
    {
        cout << " 1. Check is that list is empty" << endl;
        cout << " 2. Add element the end of the list" << endl;
        cout << " 3. Add element at beggining of the list" << endl;
        cout << " 4. Add element on specified index" << endl;
        cout << " 5. Remove an element from the end" << endl;
        cout << " 6. Remove an element from the beggining" << endl;
        cout << " 7. Remove an element from specified index " << endl;
        cout << " 8. Display first element" << endl;
        cout << " 9. Display last element" << endl;
        cout << " 10. Average" << endl;
        cout << " 11. Max" << endl;
        cout << " 12. Display whole list" << endl;
        cout << " 13. Exit" << endl;

        cin >> choice;
        switch(choice)
        {
            case 1:
            {   
                if(isEmpty(l))
                {
                    cout << "List is empty" << endl;
                }
                else
                {
                    cout << "List is not empty" << endl;
                }
                break;
            }
            case 2:
            {   
                int num=rand()%10;
                add_tail(l,num);
                break;
            }
            case 3:
            {
                int num=rand()%10;
                add_head(l,num);
                break;
            }
            case 4:
            {
                int num=rand()%10;
                int position;
                cout << "Enter index" << endl;
                cin >> position;
                add_position(l,num,position);
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
                int position;
                cout << "Enter index" << endl;
                cin >> position;
                delete_position(l,position);
                break;
            }
            case 8:
            {   
                if(isEmpty(l))
                {
                    cout << "List is empty" << endl;
                }
                else
                {
                    cout << l.head->number << endl;
                }
                break;
            }
            case 9:
            {   
                if(isEmpty(l))
                {
                    cout << "List is empty" << endl;
                }
                else
                {
                    cout << l.tail->number << endl;
                }
                break;
            }
            case 10:
            {   
                if(isEmpty(l))
                {
                    cout << "List is empty" << endl;   
                }
                else
                {
                    cout <<  "Average: " << avg(l)  << endl;
                }
                break;
            }
            case 11:
            {   
                if(isEmpty(l))
                {
                    cout << "List is empty" << endl;

                }
                else
                {
                    cout << max(l) << ", max= " << endl;
                }
                break;
            }
            case 12:
            {   
                print(l);
                cout << "Size of list: " << l.counter << endl;
                break;
            }
            case 13:
            {
                flag=0;
                break;
            }
        }
    }   
}