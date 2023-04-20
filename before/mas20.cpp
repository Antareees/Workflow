#include <iostream>
#include <cmath>
#define n 8
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");

    int s=0,a,b,min=10000,p;
    int mas[n];
    for (int i = 0; i < n; i++) { // задаю массив из n элементов 
        cin >> mas[i]; 
    }
    for (int i = 0; i < n; i++)
    {
        if (mas[i] % 2!=0 && mas[i]<=min) { // поиск минимаьлного нечетного 
            min=mas[i]; 
            p=i;
            s=s+1; // флаг 
        } 
    }

    if (s==0){
        cout << "Таких элементов нет";
    }
    else {
        a=mas[n-1];
        mas[p]=a;
        mas[n-1]=min; // меняю местами 
        for (int i=0; i<n;i++) {
            cout << mas[i] << " "; // вывод массива 
        }
    }
    return 0;
}
