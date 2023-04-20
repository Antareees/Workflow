#include<iostream>
using namespace std;
int f(int x,int n) //функциця
{
    if (n==0) return 1; 
    if (n==1) return 2*x;
    else {
        return 2*x*f(x,n-1)-2*(n-1)*f(x,n-2); //рассчет функци
    }
}
 
int f1(int x, int n){
  if (n==0) return 1;
  if (n==1) return 2*x;
  else {
    int n0=1,n1=2*x, n2;
    for (int i=2; i<=n; i++){
      n2=2*x*n1-2*(i-1)*n0;
      n0=n1;
      n1=n2;
    }
    return n2;
  }
}
int main()
{
  int n,x;
  cout << "n=";
  cin >> n;
  cout << "x=";
  cin >> x;
  cout << f(x,n) << ' ' << f1(x,n);
  return 0;
}