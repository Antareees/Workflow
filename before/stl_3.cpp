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
bool Odd(int i) { return i % 2 != 0; }
bool Even(int i) { return i % 2 == 0; }


int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "введите кол-во эл 1 вектора ";
    int n1;
    cin >> n1;
	vector <int> a(n1);
	cout << "введите элементы 1 вектора  ";
    for (int i = 0; i < n1; i++)
    cin >> a[i];
	cout << "введите кол-во эл 2 вектора ";
    int n2;
    cin >> n2;
	vector <int> b(n2);
	cout << "введите  элементы 2 вектора ";
    for (int i = 0; i < n2; i++)
    cin >> b[i];
	a.erase(remove_if(a.begin(), a.end(), Even),a.end());
	b.erase(remove_if(b.begin(), b.end(), Odd),b.end());
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	cout << "новый первый вектор ";
	for (int i = 0; i < (int)a.size(); i++) 
    cout << a[i] << ' ';
	cout << endl;
	cout << "новый второй вектор ";
	for (int i = 0; i < (int)b.size(); i++) cout << b[i] << ' ';
	cout << endl;
	vector <int> new1;
	merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(new1));
	cout << "ответ ";
	for (int i = 0; i < (int)new1.size(); i++)
    cout << new1[i] << ' ';
	cout << endl;
}
