#include <cstdlib>

void quicksort(int x,int lewy,int prawy)
{
    int srodek = int [(lewy+prawy)/2];
    int piwot = lewy;
    x[srodek] = x[prawy];
    int granica = lewy;
    for(int i=lewy;i++;i<prawy)
    {
        if(x[i]<x[piwot])
        {
            std::swap(x[i],x[granica]);
            granica++;
        }
    }
    x[prawy]=x[granica];
    x[granica]=piwot;
    if(lewy<granica-1)
    {
        quicksort(x,lewy,granica-1);
    }
    if(granica+1<prawy)
    {
        quicksort(x,granica+1,prawy);
    }
}