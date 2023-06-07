#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a;
    cout << "Podaj liczbe elementow w tablicy: ";
    cin >> n;
    
    vector<int> tab(n);
    cout << "Podaj elementy tablicy: ";
    for (int i = 0; i < n; i++) {
        cin >> tab[i];
    }
    
    cout << "Podaj liczbe a: ";
    cin >> a;
    
    int liczbaWystapien = 0;
    vector<int> tab_a;
    
    for (int i = 0; i < n; i++) {
        if (tab[i] == a) {
            liczbaWystapien++;
            tab_a.push_back(i);
        }
    }
    
    cout << "Liczba wystapien elementu a: " << liczbaWystapien << endl;
    
    cout << "Indeksy wystapien elementu a w tablicy tab: ";
    for (int i = 0; i < tab_a.size(); i++) {
        cout << tab_a[i] << " ";
    }
    cout << endl;
    
    return 0;
}
