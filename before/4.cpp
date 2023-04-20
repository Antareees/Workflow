#include <iostream>
#include <cmath>
using namespace std;

int main() {int i, n; // 2 числа
	cin >> i >> n; // ввожу 2 значения
	cout << (n ^ (1 << i));
return 0;
}