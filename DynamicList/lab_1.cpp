#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

void przydzielPamiec1D(int *&tab,int n)
{
    tab=new int[n];
}

void wypelnijTablice1D(int *tab, int n,int a,int b)
{   srand(time(NULL));
    for(int i=0;i<n;i++)
    {
         tab[i]=rand()%(b-a+1)+a;
    }
}

void wyswietl1D(int *tab,int n)
{
    for(int i=0;i<n;i++)
    {
         cout << tab[i] << endl;
    }
}
 
void usunTablice1D(int *&tab)
{
    delete []tab;
}

int elementMin(int *&tab,int n)
{
    int x=tab[0];
    for(int i=0;i<n;i++)
    {
        if(tab[i]<=x)
        {
            x=tab[i];
        }
    }
    return x;
}

bool czyPierwsza(int liczba)
{
    if(liczba % 2 == 0)
    {
        return (liczba == 2);
    }
    for (int i = 3; i <= sqrt(liczba); i += 2)
    {
        if (liczba % i == 0) 
        {
            return false;
        }
    }
    return true;
}

void ileWyst(int *tab,int n)
{
    int lWyst[11]={0};
    for(int i=0;i<n;i++)
    {   
        lWyst[tab[i]]++;
    }
    for(int i=0;i<11;i++)
    {   if(lWyst[i]!=0)
        {
            cout << i << " wystepuje " << lWyst[i] << " razy" << endl;
        }
    }
}

int main()
{   int rozmiar;
    int *t;
    int wybor;
    int wynik;
    bool flag=true;
    
    while(flag)
    {
        

        cout << "Wybierz zadanie:" << endl << "1) 1.2" << endl << "2) 1.3" << endl << "3) wyjscie" << endl;
        cin >> wybor;
        switch(wybor)
        {
            case 1:
                {   
                    cout << "Podaj rozmiar tablicy: " << endl;
                    cin >> rozmiar;
                    przydzielPamiec1D(t,rozmiar);

                    int przedziala,przedzialb;
                    cout << "Podaj dolna granice przedzialu: " << endl;
                        cin >> przedziala;
                    cout << "Podaj gorna granice przedzialu: " << endl;
                        cin >> przedzialb;
                            if(przedziala<=przedzialb)
                            {
                                wypelnijTablice1D(t,rozmiar,przedziala,przedzialb);

                                wyswietl1D(t,rozmiar);

                                wynik=elementMin(t,rozmiar);

                                cout << "Najmniejszy element tablicy to: " << wynik << endl;

                                if (czyPierwsza(wynik))
                                {
                                    cout << wynik << " jest liczba pierwsza." << endl;
                                }
                                else 
                                {
                                    cout << wynik << " nie jest liczba pierwsza." << endl;
                                }
                            }
                            else
                            {
                                cout << "b<a!" << endl;
                            }
                    usunTablice1D(t);
                    break;
                }
            case 2:
                {
                    cout << "Podaj rozmiar tablicy: " << endl;
                    cin >> rozmiar;
                    przydzielPamiec1D(t,rozmiar);

                    wypelnijTablice1D(t,rozmiar,0,10);
                    wyswietl1D(t,rozmiar);
                    ileWyst(t,rozmiar);
                    usunTablice1D(t);
                    break;
                }
            case 3:
                {
                    flag=false;
                    break;
                }
        }
    }
    return 0;
}
