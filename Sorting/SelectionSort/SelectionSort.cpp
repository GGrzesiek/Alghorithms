#include <cstdlib>
#include <algorithm>

void SelectionSort(int x[],int n)
{
    
    for(int i=n-1;i>0;i--)
    {
        int ind = 0;
        for(int j=1;j<=i;j++)
        {
            if(x[j]>x[ind])
            {
                ind = j;
            }
        }
        std::swap(x[ind],x[i]);
    }
}