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


int main()
{	
	setlocale(LC_ALL, "Rus");
	cout << "введите кол-во эл вектора ";
	int n;
    cin >> n;
	vector <int> a(n);
	cout << "введите элементы вектора ";
	for (int i = 0; i < n; i++) {
    cin >> a[i];
    }
	int Min = *min_element(a.begin(), a.end());
	auto it = remove(a.begin(), a.end(), Min);
	a.erase(it, a.end());
	cout << "ответ "; 
	for (int i = 0; i < (int)a.size(); i++)
    cout << a[i] << ' ';
}