#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string text;
    cout << "TEXT: ";
    getline(cin, text); // ввод строки

    set<string> vopr_vosk, pov, result;
    string razd = "!?.", temp, word;
    char tmp;
    int k, k1, pos = 0, pos1 = 0;

    while (pos < text.length() - 1)
    {
        k = text.find_first_of(razd, pos); // находим предложение и знак
        tmp = text[k];
        temp = text.substr(pos, k - pos);
        temp += " ";
        pos1 = 0;
        while (pos1 < temp.length() - 1) // перебираем каждое слово предложения
        {
            k1 = temp.find_first_of(' ', pos1);
            word = temp.substr(pos1, k1 - pos1);
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            switch (tmp)
            {
            case '.':
                pov.insert(word); // добовляем слово в нужное множество
                break;
            case '!':
            case '?':
                vopr_vosk.insert(word);
                break;
            }
            pos1 += word.length() + 1;
        }
        pos += temp.length() + 1;
    }

    set_difference(pov.begin(), pov.end(), vopr_vosk.begin(), vopr_vosk.end(), inserter(result, result.begin())); // слова которые встречаются только в повест предл
    cout << result.size() << endl;
    for (auto it = result.begin(); it != result.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
    return 0;
}
/*abc hglg kjjgf asd. lufivy fiydrtce fotriryd? abc hglg asd. khgfvi uifviytf ykug! */