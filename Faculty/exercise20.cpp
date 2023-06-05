#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string decToBin(int number) {
    string binary;
    while (number > 0) {
        binary += to_string(number % 2);
        number /= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

bool isPalindrome(int number) {
    string numStr = to_string(number);
    int length = numStr.length();
    for (int i = 0; i < length / 2; i++) {
        if (numStr[i] != numStr[length - 1 - i]) {
            return false;
        }
    }
    return true;
}

bool isSameDigits(int number) {
    int lastDigit = number % 10;
    while (number > 0) {
        if (number % 10 != lastDigit) {
            return false;
        }
        number /= 10;
    }
    return true;
}

int sumDigits(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int maxDigit(int number)
{
    int maxDigit = 0;
    while (number > 0) {
        int digit = number % 10;
        if (digit > maxDigit) {
            maxDigit = digit;
        }
        number /= 10;
    }
    return maxDigit;
}

void evenOddDigits(int number)
{
    int evenCount = 0;
    int oddCount = 0;
    while (number > 0) 
    {
        int digit = number % 10;
        if (digit % 2 == 0) 
        {
            evenCount++;
        } 
        else 
        {
            oddCount++;
        }
        number /= 10;
    }
    if (evenCount > oddCount) 
    {
        cout << "Wiecej cyfr parzystych\n";
    } 
    else if (oddCount > evenCount) 
    {
        cout << "Wiecej cyfr nieparzystych\n";
    } 
    else 
    {
        cout << "Tyle samo cyfr parzystych i nieparzystych\n";
    }
}

int reverseNumber(int number)
{
    string reversedNumStr = to_string(number);
    reverse(reversedNumStr.begin(), reversedNumStr.end());
    int reversedNum = stoi(reversedNumStr);
    return reversedNum;
}

int main() {
    int choice;
    bool flag = true;
    int a;
    while(flag)
    {   
        cout << "Podaj liczbe dodatnia: ";
        cin >> a;
        a = abs(a);
        cout << "1) jeśli wszystkie cyfry liczby a są jednakowe, wyświetlany jest komunikat „cyfry jednakowe”, w przeciwnym przypadku wyświetlany jest komunikat „cyfry różne”" << endl;
        cout << "2) obliczana i wyświetlana jest suma cyfr liczby a" << endl;
        cout << "3) wyznaczana i wyświetlana jest największa z cyfr liczby a" << endl;
        cout << "4) sprawdzane jest, czy więcej jest cyfr parzystych czy nieparzystych we wczytanej liczbie i wyświetlany jest odpowiedni komunikat" << endl;
        cout << "5) utworzona i wyświetlana jest liczba lustro będąca odbiciem lustrzanym liczby a (cyfry w odwrotnej kolejności względem cyfr liczby a)”, w przeciwnym przypadku wyświetlany jest komunikat „cyfry różne”" << endl;
        cout << "6) sprawdzane jest, czy wczytana z klawiatury liczba jest palindromem, tzn. czytana od końca jest taka sama jak czytana od początku, np. 234432" << endl;
        cout << "7) wyznaczane i wyświetlane jest rozwinięcie binarne liczby a" << endl;
        cout << "8) wyjdz z programu" << endl;
        cout << "Wybierz polecenie (1-8): ";
        cin >> choice;
        
            switch (choice)
            {  
                case 1:
                    {
                        if(isSameDigits(a))
                        {
                            cout << "Cyfry sa jednakowe\n";
                        }
                        else
                        {
                            cout << "Cyfry sa rozne\n";
                        }
                        break;
                    }
                    case 2:
                    {   
                        cout << "Suma cyfr: " << sumDigits(a) << endl;
                        break;
                    }
                    case 3:
                    {
                        cout << "Najwieksza cyfra: " << maxDigit(a) << endl;
                        break;
                    }
                    case 4:
                    {
                        evenOddDigits(a);
                        break;
                    }
                    case 5:
                    {
                        cout << "Liczba lustrzana: " << reverseNumber(a) << endl;
                        break;
                    }
                    case 6:
                    {
                        if (isPalindrome(a)) 
                        {
                            cout << "Liczba jest palindromem\n";
                        }
                        else 
                        {
                            cout << "Liczba nie jest palindromem\n";
                        }
                        break;
                    }
                    case 7:
                    {
                        string binary = decToBin(a);
                        cout << "Rozwiniecie binarne: " << binary << endl;
                        break;
                    }
                    case 8:
                    {
                        flag = false;
                        break;
                    }
            }
    }
    return 0;
}
