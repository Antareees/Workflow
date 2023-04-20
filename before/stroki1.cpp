#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int main(){
    string str;
    getline(cin,str);
    cout <<"str:" << str <<endl;
    for (int i=0; i<=str.length(); i++) {
        if (isdigit(str[i])) {
            str.erase(i,1);
            i--;
        }
    }
    cout <<"newstr:" << str << endl;
}
// qwerty123456qwert1e1e1
