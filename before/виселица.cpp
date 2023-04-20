#include <bits/stdc++.h>

using namespace std;
vector<string> spisok({"MUSIC", "BOY", "GIRL", "EGG", "PEN", "PAPER", "ROOM", "SCHOOL", "COUNTRY", "COLOR", "CAR", "BROTHER", "BOOK"}); // список слов 
int main() {
    srand(time(0));
    setlocale(LC_ALL, "Russian");
    string alf="ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
    int count = 7; // количество шагов
    bool lastcor=true; // флаг, который отвечает за использованные буквы
    string word = spisok[rand() % spisok.size()]; // рандомное слово из списка
    string guessed(word.size(), '_'); // отгаданное 
    while (count > 0) {
        system("cls"); // очистка консоли
        cout << alf << endl; 
        cout << "Осталось ходов: " <<  count << endl;
        cout << guessed << endl;
        if (lastcor) {
            cout << "Введите букву: ";
        }
        else 
            cout << "Ошибка! Введите корректную букву: ";   
        string bukva;
        cin >> bukva;
        for (int i=0; i<bukva.size();i++){
            bukva[i] = toupper(bukva[i]); // изменение регистра
        }
        if (bukva.size() == 1){ 
            int poz = find (alf.begin(), alf.end(), bukva[0]) - alf.begin(); //номер позиции буквы в алфавите 
            if (poz == 26) {
                lastcor = false;
                continue;
            }
            alf[poz] = '_'; //замена этой буквы в алфавите на прочерк
            lastcor = true;
            if (find (word.begin(), word.end(), bukva[0]) == word.end()){
                --count; // если буквы нет в слове то - ход 
                continue;
            }
            for (int i=0; i<word.size(); i++){ // открываю нужную букву 
                if (bukva[0] == word[i]) {
                    guessed[i] = bukva[0];
                } 
            }
            if (find (guessed.begin(), guessed.end(), '_') == guessed.end()){ //если в занаданном слове не осталось _ то слово угадано 
                system("cls");
                cout << "Загаданное слово: " << guessed << endl;
                cout << "Вы выиграли!"; 
                break; 
            }
        }
        if (bukva.size() != 1) { // если вводится слово целиком  
            if (bukva == word) {
            }
                guessed = bukva;
            else {
                --count;
            }
        }
        if (find (guessed.begin(), guessed.end(), '_') == guessed.end()){
            system("cls");
            cout << "Загаданное слово: " << guessed << endl;
            cout << "Вы выиграли!";
            break;
        }
        } 
    if (count == 0) {
            system("cls");
            cout << "Вы проиграли( ";
            cout << "Загаданное слово: "<< word << endl;
    }
}
