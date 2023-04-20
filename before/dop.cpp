#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    /*
    int n;
    cin >> n;
    int s=0;
    vector<int> f(n);
    for (int i=0; i<n; i++) {
        cin >> f[i];
    }

    int index = 0;
    while (index < n) {
        if (index == 0)
            index++;
        if (abs(f[index]) < abs(f[index - 1]))
            index++;
        else {
            swap(f[index], f[index - 1]);
            index--;
        }
    }
    for (int i=0; i<n; i++) {
        cout << f[i] << " ";
    }
    */
    int n;
    cin >> n;
    int s=0;
    vector<vector<int>> f(n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (j%2==0) {
                f[i][j]=0;
            }
            else {
                f[i][j]=1;
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++){
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
}