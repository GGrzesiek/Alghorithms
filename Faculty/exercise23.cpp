#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Podaj liczbe n: ";
    cin >> n;

    vector<int> t(n);
    cout << "Podaj " << n << " liczb calkowitych: ";

    for (int i = 0; i < n; ++i)
    {
        cin >> t[i];
    }

    int wynik = 1;
    int lcyfr = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i % 3 == 0 && t[i] != 0)
        {
            wynik *= t[i];
            lcyfr++;
        }
    } 
    if(lcyfr == 0)
    {
        wynik = 0;
    }
    cout << "Wynik: " << wynik << endl;

    return 0;
}
