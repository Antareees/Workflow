#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<set>
#include<string>
using namespace std;


void vstavka(char symbol, vector<char>& pustoeSlovo, vector<char> slovo) {
	for (int i = 0; i < slovo.size(); i++) {
		if (slovo[i] == symbol) {
			pustoeSlovo[i] = symbol;
		}
	}
}

bool inVector(char symbol, vector<char> slovo) {
	for (int i = 0; i < slovo.size(); i++) {
		if (slovo[i] == symbol) return true;
	}
	return false;
}

bool ravn(vector<char> str, vector <char> slovo) {
	int k = 0;
	for (int i = 0; i < str.size(); i++) {
		if (slovo[i] == str[i]) {
			k++;
		}
	}
	return k == str.size();
}


bool ravn(string str, vector <char> slovo) {
	int k = 0;
	for (int i = 0; i < str.size(); i++) {
		if (slovo[i] == str[i]) {
			k++;
		}
	}
	return k == str.size();
}


int proverka(string str, vector<char> slovo) { //0-если нет такой буквы; 1-если есть такая буква; 2-если это все слово
	if (str.size() == slovo.size()) {
		if (ravn(str, slovo)) {
			return 2;
		}
		else {
			return 0;
		}
	}
	else if (str.size() == 1) {
		if (inVector(str[0], slovo)) {
			return 1;
		}
		else {
			return 0;
		}
	}
}

void clearScreen() {
	for (int i = 0; i < 50; i++) cout << endl;
}


template<typename T>
void print(T set) {
	for (auto it = set.begin(); it != set.end(); ++it) {
		cout << *it << " ";
	}
}

int main() {
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	bool inGame = true;
	int attempts = 0;

	vector<string> slova{ "paper", "book", "cucumber", "student", "Uncopyrightable" };
	int t = rand() % slova.size();
	set<char> alfabet{ 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p',
		'q','r','s','t','u','v','w','x','y','z' };

	vector<char> slovo;
	string slv = slova[t];
	vector<char> pustoeSlovo;

	for (int i = 0; i < slv.size(); i++) {
		slovo.push_back(slv[i]);
		pustoeSlovo.push_back('_');
	}

	int maxAttempts = slovo.size() / 2;


	cout << "Вам нужно угадать слово из " << slovo.size() << " букв" << endl;

	while (inGame) {
		string input;
		cout << "Оставшиеся буквы: " << endl;
		print(alfabet);
		cout << endl << "У вас осталось " << maxAttempts - attempts << " попыток" << endl;
		cout << "Ваше слово: ";
		print(pustoeSlovo);
		cout << endl << "Введите слово целиком или одну букву: ";
		cin >> input;
		cout << endl;
		auto it = pustoeSlovo.begin();
		switch (proverka(input, slovo)) {

		case (2):
			inGame = false;
			cout << "Поздравляем! Вы угадали слово: " << slv << " за " << maxAttempts - attempts << " попыток" << endl;
			break;

		case (1):
			cout << "Вы угадали букву " << input[0] << endl;
			alfabet.erase(input[0]);
			vstavka(input[0], pustoeSlovo, slovo);
			if (ravn(pustoeSlovo, slovo)) {
				inGame = false;
				cout << "Поздравляем! Вы угадали слово: " << slv << " за " << maxAttempts - attempts << " попыток" << endl;
			}
			break;

		case (0):
			attempts++;
			cout << "Неверная буква" << endl;
			if (maxAttempts - attempts == 0) {
				inGame = false;
				cout << "Увы, но вы исчерпали " << attempts << " попыток" << endl << "Верное слово ";
				print(slovo);
			}
			else {
				cout << "Такой буквы нет в слове, повторите попытку" << endl;
			}
			break;
		}
	}
}
