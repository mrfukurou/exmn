// ConsoleApplication.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale.h>
#include <windows.h>

using namespace std;

struct Subject {
	string name;
	string lastname;
	int semester;
};

void sort(Subject* mas, int size)
{

	int i = 0;
	int j = size - 1;
	Subject mid;
	mid.semester = mas[size / 2].semester;
	do {
		while (mas[i].semester < mid.semester) {
			i++;
		}
		while (mas[j].semester > mid.semester) {
			j--;
		}
		if (i <= j) {
			Subject tmp = mas[i];
			if (mas[i].semester == mas[j].semester) {
				if (mas[i].name > mas[j].name)
				{
					tmp = mas[i];
					mas[i] = mas[j];
					mas[j] = tmp;
				}
			}
			else {
				Subject tmp = mas[i];
				mas[i] = mas[j];
				mas[j] = tmp;
			}
			i++;
			j--;
		}
	} 
	while (i <= j);
	if (j > 0) {
		sort(mas, j + 1);
	}
	if (i < size) {
		sort(&mas[i], size - i);
	}
}


void output(Subject* mas, int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << "Название: " << mas[i].name << "\nФамилия преподавателя: " << mas[i].lastname << "\nСеместр: " << mas[i].semester<<endl;
	}
}

int main()
{
	try {
		setlocale(LC_ALL, "Russian");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		int num;
		cout << "Введите количество элементов в массиве: ";
		cin >> num;
		throw 1;
		if (num < 0) {
			Subject* Plan = new Subject[num];

			for (int i = 0; i < num; i++)
			{
				cout << "Введите название: ";
				cin >> Plan[i].name;
				cout << "Введите фамилию: ";
				cin >> Plan[i].lastname;
				cout << "Введите семестр: ";
				cin >> Plan[i].semester;
				cout << endl;
			}
			sort(Plan, num);
			output(Plan, num);
		}
	}
	catch(int a)
	{ if (a == 1) cout << "Введено некoрректное количество элементов" << endl; }
}