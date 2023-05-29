#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void wczytaj(string &tekst,string &wzorzec)
{
ifstream plik;
int liczbaLini;
plik.open("tekst.txt");
plik>>liczbaLini;
for(int i=0;i<liczbaLini;i++)
{
    plik>>tekst;
    istringstream ss(tekst);
    cout<<"tekst to "<<tekst;
}

}
void karp(string tekst,string wzorzec,int dlt, int dlw,string p,int off,int hashP)
{
    int hashT=0;
    for(int i=0;i<dlw;i++)
    {
        hashT=hashT+make_hash(pattern[i],off,p,dlw-i-1)
    }
    for(int j=0;j<dlt;j++)
    {
        if(hashP==hashT)
        {
            
        }
        if(j<dlt)
        {
            hashT=update_hash(hashT,text[j],text[i],off,p,dlw-1)
        }
    }
}
int main()
{   
    string tekst, wzorzec;
    wczytaj(tekst, wzorzec);
    int dlt=tekst.size();
    int dlw=wzorzec.size();
    int opcja;
    do{
        cout <<"Co chcesz zrobic: "<<endl<<" 5.2 (1)"<<endl<<" 5.3 (2)"<<endl<<" 5.4 (3)"<<endl<<"6.1 (4)";
        cin>>opcja;
        switch(opcja)
        {
            case 1:
            {   
                karp(tekst,wzorzec,dlt,dlw,p,off,hashP)
                break;
            }
            default: cout<<"bledne dane"<<endl;
        }
    } while (opcja!=0);
    return 0;
}


