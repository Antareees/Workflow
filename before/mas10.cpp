#include <iostream>
#include <cmath>
#define n 8
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");

    int s=0;
    int mas[n];
    for (int i = 0; i < n; i++) { //создаю массив 
        cin >> mas[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (mas[i] % 3!=0 && mas[i]%2!=0) { // нечетное/некратное 3
        cout << i << " ";
        s=s+1; // флаг 
        } 
        else {
            s=s+0;
        }
    }
    if (s==0){
        cout << "Таких элементов нет";
    
    }
    return 0;
}
