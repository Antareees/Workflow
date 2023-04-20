#include<iostream>
#include<cmath>
using namespace std;
double F(double i, double N){
if (abs(i - N) < 0.00001) return sqrt(N+1); //выход из рекурсии
else
return sqrt(1 + i*F(i+1, N));
}
int main(){
double N;
cout << "N = "; //ввод данных
cin >> N;
cout << "F = " << sqrt(F(1, N)) << endl; //вызов функции
return 0;
}
