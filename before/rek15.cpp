#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    int N = 500; 
    float c = 2.0, z = 1.0; 
    float pr1 = 1, pr2 = 2, eps = 0.01;
    cout << left << setw(3) << "n"  //вывод заголовка 
         << "\t|" << setw(10) << "pr"
         << "\t|" << setw(10) << "a" << endl;
    for (int i = 1; i <= N && abs(pr1 - pr2) > eps ; i++) { 
        pr2 = pr1;
        pr1 *= (c / z);
        if (i % 2 == 0) {
            c += 2;
        }
        else {
            z += 2;
        }
        cout << left << setw(3) << i << "\t|" << setw(10) << abs(pr1 - pr2) << "\t|" << setw(10) <<  pr1 << endl;
    }
    return 0;
}
