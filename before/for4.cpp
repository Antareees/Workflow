#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int main()
{
    setlocale(LC_ALL, "RUS");
    int n,s=1;
    cin >> n;
    if (n%2==1) {
        for (int i=1; i<=n;i=i+2)
        s*=i;
    }    
    else {
        for (int i=2; i<=n;i=i+2)
        s*=i;
    }
    cout << s;
return 0;
}
