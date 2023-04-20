#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int i, n; // целые числа       78 = 1001110 i=5  1011110=110
	cin >> i >> n; // ввожу число и сдвиг 
	cout << (n | (1 << i));
return 0;
}