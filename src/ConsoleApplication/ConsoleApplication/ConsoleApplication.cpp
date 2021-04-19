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


void output(Subject* mas, int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << "Название: " << mas[i].name << "\nФамилия преподавателя: " << mas[i].lastname << "\nСеместр: " << mas[i].semester<<endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int num;
	cout << "Введите количество элементов в массиве: ";
	cin >> num;

	Subject *Plan = new Subject[num];

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
		output(Plan, num);
}