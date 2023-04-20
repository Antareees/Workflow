
#include <iostream>
#include <cmath>
using namespace std;

int main() {setlocale(LC_ALL, "rus");
	int n, x; // 2 числа
	cin >> n; //ввожу6
	x = n & 1;  //последняя цифра числа в 2-ой сиситеме 
	if (x == 1) {
		cout << "нечетное" << endl;
	}
	else {
		cout << "четное" << endl;
		return 0;
	}
}