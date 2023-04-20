#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <queue>
#include <numeric>

typedef long long ll;
#define endl '\n'

using namespace std;

int x;
bool isOdd(int i) { return i % 2 != 0; }
bool isEven(int i) { return i % 2 == 0; }
int func(int res, int i)
{
	if (i % x == 0) {
        return res + i;
    }
	else {
        return res;
    }
}
int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "введите кол-во эл вектора ";
    int n;
    cin >> n;
	vector <int> a(n);
	cout << "введите элементы вектора "; 
	for (int i = 0; i < n; i++)
    cin >> a[i];
	cout << "введите Х";
    cin >> x;
	int Min = *min_element(a.begin(), a.end());
	int s = accumulate(a.begin(), a.end(), 0, func);
	int Max = *max_element(a.begin(), a.end());
	replace_if(a.begin(), a.end(), isEven, Max);
	cout << "сумма = " << s << " минимальное = " << Min << " ответ ";
	for (int i = 0; i < n; i++)
    cout << a[i] << ' ';
	cout << endl;
}