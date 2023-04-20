#include <iostream>
#include <cmath>
#define n 8
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");

    int s=0;
    int mas[n];
    for (int i = 1; i < n; i++) { // создаю массив 
        cin >> mas[i];
    }
    
    for (int i = 1; i < n; i=i+2) // иду по нечетным индексам 
    {
        if (mas[i] % 2==0) {
        s=s+mas[i];
        
        } 
        else {
            s=s+0;
        }
    }
    if (s==0){
        cout << "Таких элементов нет";
    }
    else {
        cout << s;
    }
    return 0;
}