#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

struct date
{ // дата
    int dd, mm, yy;
};

struct people
{                     // данные о человеке
    string Surname;   // фамилия
    string Position;  // должность
    int PosValue;     // эквивалент должности для сравнения
    date DateOfBirth; // дата рождения
    int XP;           // стаж работы
    int Salary;       // зарплата
};

date Str_to_Date(string str)
{ // из строки в дату
    date x;
    string temp = str.substr(0, 2); // день
    x.dd = atoi(temp.c_str());
    temp = str.substr(3, 2); // месяц
    x.mm = atoi(temp.c_str());
    temp = str.substr(6, 4); // год
    x.yy = atoi(temp.c_str());
    return x;
}

int StrPosToInt (string pos) {
    if (pos == "джуниор")
        return 1;
    if (pos == "миддл")
        return 2;
    if (pos == "сеньор")
        return 3;
    if (pos == "тимлид")
        return 4;

    return 0;
};

vector<people> inFile()
{ // ввод из файла
    vector<people> x;
    people temp;
    while (in.peek() != EOF)
    {
        in >> temp.Surname;  // фамилия
        in >> temp.Position; // позиция
        temp.PosValue = StrPosToInt(temp.Position);
        string tmp;          // дата рождения
        in >> tmp;
        temp.DateOfBirth = Str_to_Date(tmp);
        in >> temp.XP;     // стаж работы
        in >> temp.Salary; // зарплата
        x.push_back(temp);
    }
    return x;
}

void print(people x)
{                                          // вывод в файл
    out << setw(10) << left << x.Surname;  // по левому краю, 10 позиций для фамилии
    out << left << setw(10) << x.Position; // 20 позиций для должности
    if (x.DateOfBirth.dd < 10)
        out << left << '0' << x.DateOfBirth.dd << '.'; // добавляем 0
    else
        out << left << x.DateOfBirth.dd << '.';
    if (x.DateOfBirth.mm < 10)
        out << '0' << x.DateOfBirth.mm << '.';
    else
        out << x.DateOfBirth.mm << '.';
    out << left << setw(6) << x.DateOfBirth.yy;  // на год 6 позиций
    out << left << setw(4) << x.XP;              // стаж
    out << left << setw(10) << x.Salary << endl; // запрлата
}

bool operator<(people a, people b)
{ // переопределяем оператор < в соотвествии с условием
    if (a.PosValue < b.PosValue)
        return true;
    return false;
}

bool operator>(people a, people b)
{ // переопределяем оператор < в соотвествии с условием
    if (a.PosValue > b.PosValue)
        return true;
    return false;
}


void heapify(vector<people> &arr, int N, int i)
{
    int largest = i; // Инициализируем наибольший элемент как корень
    int l = 2 * i + 1; //левый = 2*i + 1
    int r = 2 * i + 2; //правый

    if (l < N && arr[l] > arr[largest]) //Если левый дочерний элемент больше корня
        largest = l;

    if (r < N && arr[r] > arr[largest]) //Если правый дочерний элемент больше корня
        largest = r;

    if (largest != i) { //Если самый большой элемент не корень
        swap(arr[i], arr[largest]); // меняем местами

        heapify(arr, N, largest);
    }
}

void heapSort(vector<people> &arr, int N)
{

    for (int i = N / 2 - 1; i >= 0; i--) // строю кучу 
        heapify(arr, N, i); 

    for (int i = N - 1; i > 0; i--) { //Один за другим извлекаю элементы из кучи
        swap(arr[0], arr[i]); //Перемещаютекущий корень в конец
        heapify(arr, i, 0);  // проделываю функцию на уменьшенной куче 
    }
}

int main()
{
    vector<people> x;
    x = inFile();
    heapSort(x, x.size());

    for (int i = 0; i < x.size(); i++)
        print(x[i]);
    return 0;
}
