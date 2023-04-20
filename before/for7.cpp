#include <iostream>
#include <math.h>
using namespace std;
int main(){
setlocale (LC_ALL,"Russian");
int n;
cout << "n="; cin >> n;
float x;
cout << "x="; cin >> x;
float a = -x*x*x / 6, S = a; //начальные значения
cout << "i\ta\tS\n"; //заголовок таблицы
cout << 1 << "\t| " << a << "\t| " << S << endl; //вывод 1-ого шага
for (int i = 2; i <= n; i++){
a *= -x*x / ( 2*i * (2*i + 1)); //i - ый член ряда
S += a; // сумма
cout << i << "\t| " << a << "\t| " << S << endl;
}
return 0;
}