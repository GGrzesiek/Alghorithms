#include <cstdlib>
#include <algorithm>

void BubbleSort(int x[],int n)
{
    n = 10;
    for(int i=n-1;i>0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(x[j]>x[j+1])
            {
                std::swap(x[j],x[j+1]);
            }
        }
    }
}