#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    /*string s;
    cin >> s;
    bool f=true;
    for (int i = 1; i < s.length(); i++) {
        if (islower(s[i])) {
            f=false; 
        }
    }
    if (f) {
        for (int i = 0; i < s.length(); i++) {      
            if (islower(s[i])) {
                s[i]=toupper(s[i]);
            }
            else{
                s[i]=tolower(s[i]);
            }
        }
    }
    cout << s << endl;*
    string s;
    string slovo = "oops";
    cin >> s;
    for (int i=0; i+3<s.size(); i++){
        if (s[i] == 'o' && s[i+1] == 'o' && s[i+2] == 'p' && s[i+3] == 's'){
            int pos = i;
            string s1 = s.substr(0,pos);
            string s2 = s.substr(pos+4);
            s=s1+s2;
            i=-1;
        }
    }
    cout << s << endl; 

    string s;
    cin >> s;
    int i=0;
    vector<int> f(6);
    while (i != int(s.size())) {
        if (s.substr(i,1) == "0") {
            f[2]++;
            i++;
        }
        else if (s.substr(i,3) == "100") {
            f[3]++;
            i+=3;
        }
        else if (s.substr(i,3) == "101") {
            f[4]++;
            i+=3;
        }
        else if (s.substr(i,2) == "11") {
            f[5]++;
            i+=2;
        }

    }
    cout << max_element(f.begin(), f.end()) - f.begin() << endl;
    int a, b;
    cin >> a >> b;
    while (a != b) {
        if (a > b) {
            a = a / 2;
        }
        else {
            b = b / 2;
        }
    }
    cout << a << endl; 
    int n;
    cin >> n;
    map<string, int> m;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        m[s]++;
    }   
    cout << (*m.begin()).first << (*m.begin()).second << endl;
    if ((*m.begin()).second > (*--m.end()).second) {
        cout << (*m.begin()).first << endl;
    }
    else {
        cout << (*--m.end()).first << endl;
    } */
    int n; cin >> n;
    int l=0;
    int r=n-1;
    int a = 1, b = 1;
    int counta = 0, countb = 0;
    vector<int> time(n);
    for (int i = 0; i < n; i++) {
        cin >> time[i];
    }
    counta = time[l];
    countb = time[r];
    while (l!=r){
        if (counta > countb) {
            if (r-1 == l+1) {
                
            }
            else {
            r--;
            countb += time[r];
            b += 1;
            cout << "b= " << b << " " << "countb= "<< countb << endl;
            }
        } 
        else {
            l++;
            counta += time[l];
            a += 1;
            cout << "a= "<< a << " " << "counta= " <<  counta << endl;
        }
    }
    cout << a << " " << b << endl;
}

