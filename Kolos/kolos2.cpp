#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct student
{   string index;
    float grades[5];
    float average;
};

void wczytaj(student &s)
{   
    float grade;
    cout << "Podaj index studenta: ";
    cin >> s.index;
    cout << "Podaj oceny studenta: ";

    for (int i = 0; i < 5; i++)
    {   cin >> grade;
        if(grade>=2 && grade<=5)
        {
            s.grades[i] = grade;
        }
        else
        {
            cout << "Oceny maja byc z przedzialu 2-5: ";
            i--;
        }
    }
}

int flagaP(float* x[],int n, int granica)
{   int j = n-1;
    int i = 0;
    for(i; i<j;)
    {
        for(;x[i]<=granica && i<j;)
        {
            i++;
        }
        for(;x[j]>granica && i<j;)
        {
            j--;
        }
        if(i<j)
        {
            swap(x[i],x[j]);
            i++;
            j--;
        }
    }
    if(x[i]<=granica)
    {
        return i+1;
    }
    else
    {
        return i;
    }
}

void srednia(student &s)
{
    float sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += s.grades[i];
    }
    s.average = sum / 5;
}

void wyswietl(student s[], int liczba, int przedzial)
{   cout << "Studenci z ocenami powyzej 4.0: " << endl;

    for(int i = 0; i<przedzial; i++)
    {     
        cout << "Srednia studenta " << s[i].index << " wynosi " << s[i].average << endl;
    }
    cout << "Studenci z ocenami ponizej 4.0: " << endl;
    for(int i = przedzial; i<liczba; i++)
    {     
        cout << "Srednia studenta " << s[i].index << " wynosi " << s[i].average << endl;
    }
}

int main()
{   
    int n;
    int przedzial;
    cout << "Podaj liczbe studentow: ";
    cin >> n;

    student* studenci = new student[n];
    for(int i=0; i<n; i++)
    {
        wczytaj(studenci[i]);
        srednia(studenci[i]);

        przedzial = flagaP(studenci->average, n, 4);
    }
    cout << studenci->average << endl;
    wyswietl(studenci, n, przedzial);

    delete [] studenci;

    return 0;
}