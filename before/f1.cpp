#include <iostream>
using namespace std;
int factorial(int i)
{
  if (i == 0)
    return 1;
  else
    return i * factorial(i - 1);
}

int main()
{
  int n,k,s=1;
  cout << "n=";
  cin >> n;
  cout << "k=";
  cin >> k;
  for (int j=1; j<=k; j++){
    s=s*j;
  }
  cout << factorial(n) << endl;
  cout << s;
  return 0;
}