#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int main(){
    setlocale(LC_ALL, "rus");
    int count=0;
    string str, word, srav;
    getline(cin,str);
    getline(cin,word);
    for (int i=0; i<=str.length(); i++) {
        if (isalpha(str[i])) {
            srav+=str[i];
        }
        else if (!isalpha(str[i])){
            if (srav.compare(word)==0){
                count++;
                srav.erase();
            }
            else {
                srav.erase();
            }
            }
        }
    cout << "количество одинаковых строк" << " - " << count << endl;
}
// abc abcd abc abcda
