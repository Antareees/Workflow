#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int main()
{
    setlocale(LC_ALL, "RUS");
    float a,b,h;
    cin >> a >> b >> h;
    for (float i=a; i<=b;i=i+h){
        cout << i << " "; 
        if (i==1) {
            cout << "логарифм из неположительного числа\n";
        }
        else if (abs(i-4)< 0.0001) {
            cout << "деление на ноль\n";
        }
        else if (i<3) {
            cout << "корень из отрцательного числа\n";
        }
        else {
            cout << (log(i*i-2*i+1)/(1-sqrt(i-3))) << "\n";
        }
    }
return 0;
}