#include <cstdlib>
#include <iostream>
using namespace std;

void BubbleSort()
{
    int n = 10;
    int tab[n];
    for(int i=0;i++;i<n)
    {
        for(int j=0;j++;j<n-1)
        {
            if(tab[j]>tab[j+1])
            {
                swap(tab[j],tab[j+1]);
            }
        }
    }
}