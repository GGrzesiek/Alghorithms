#include <iostream>

void wypiszDzielniki(int n) {
    std::cout << "Dzielniki liczby " << n << ": ";

    for (int i = 1; i <= n/2; i++) {
        if (n/2 % i == 0) {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;
}

int main() {
    int liczba;

    std::cout << "Podaj liczbe naturalna: ";
    std::cin >> liczba;

    wypiszDzielniki(liczba);

    return 0;
}
