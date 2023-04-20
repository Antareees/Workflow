#include <iostream>
#include <cmath>
#define n 8
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");

    int max=-100,x,min=10000,p;
    float s=0,k=0;
    int mas[n];
    for (int i = 0; i < n; i++) {
        cin >> mas[i]; // задаю массив
    }
    for (int i = 0; i < n; i++) // поик первого минимума
    {
        if (mas[i]<min) {
        min=mas[i];
        p=i;
    } 
    }
    for (int i = 0; i<n; i++) // поиск последенего максимума 
    {
        if (mas[i]>=max) {
        max=mas[i];
        x=i;
    } 
    }
    if (x>p) {
        for (int i=p+1; i<x;i++) { // среднее арифметическое 
            s=s+mas[i];
            k=k+1;
        }
        cout << s/k;
    }
    else if (x<p) {
        cout << "max меньше min";
    }
    return 0;
}
