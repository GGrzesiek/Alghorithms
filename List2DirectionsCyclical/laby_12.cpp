#include <iostream>

using namespace std;

struct element {
    int number;
    element* prev;
    element* next;
};

void dodajPo(element*& l, int value) {
    element* el = new element;
    el->number = value;

    if (l == nullptr) {
        el->prev = el;
        el->next = el;
        l = el;
    } else {
        el->prev = l;
        el->next = l->next;
        l->next->prev = el;
        l->next = el;
        
    }
}

void dodajPrzed(element*& l, int value) {
    element* el = new element;
    el->number = value;

    if (l == nullptr) {
        el->prev = el;
        el->next = el;
        l = el;
    } else {
        el->prev = l->prev;
        el->next = l;
        l->prev->next = el;
        l->prev = el;
        
    }
}

void usunPo(element*& l) {
    if (l != nullptr) {
        element* temp = l->next;

        if (temp != l) {
            l->next = temp->next;
            temp->next->prev = l;

            if (temp == l->next)
                l->next = l;

            delete temp;
        }
    }
    else
    {
        cout<< "lista jest pusta"<<endl;
    }
}

void usunPrzed(element*& l) {
    if (l != nullptr) {
        element* temp = l->prev;

        if (temp != l) {
            l->prev = temp->prev;
            temp->prev->next = l;

            if (temp == l->prev)
                l->prev = l;

            delete temp;
        }
    }
    else
    {
        cout<< "lista jest pusta"<<endl;
    }
}

int iloscElementow(element* l) {
    if (l == nullptr)
        return 0;

    int licz = 0;
    element* temp = l->next;

    while (temp != l) {
        licz++;
        temp = temp->next;
    }

    return licz + 1;
}

void show(const element* l) {
    if (l != nullptr) {
        const element* temp = l;

        cout<< "Lista: ";

        do {
            cout << temp->number << " ";
            temp = temp->next;
        } while (temp != l);
        cout<< endl;
    }
    else
    {
        cout<< "lista jest pusta"<<endl;
    }
}




int main()
{
    element *l = nullptr;
    int wybor;
    int liczba;
    while(wybor!=7)
    {
        cout<<endl;
        cout<< "1. Dodaj za"<<endl;
        cout<<"2. Dodaj przed"<<endl;
        cout<< "3. Usun za"<<endl;
        cout<< "4. Usun przed"<<endl;
        cout<< "5. Ilosc elementow"<<endl;
        cout<< "6. Wyswietl"<< endl;
        cout<< "7. Wyjscie"<<endl;
        cin>>wybor;
        cout<<endl;
        switch(wybor)
        {
        case 1:
            cout<< "podaj liczbe: ";
            cin>>liczba;
            dodajPo(l,liczba);
            break;
        case 2:
            cout<< "podaj liczbe: ";
            cin>>liczba;
            dodajPrzed(l,liczba);
            break;
        case 3:
            usunPo(l);
            break;
        case 4:
            usunPrzed(l);
            break;
        case 5:
            cout<<"ilosc: "<<iloscElementow(l)<<endl;
            break;
        case 6:
            show(l);
            break;

        }
        cout<<endl;
    }


    return 0;
}