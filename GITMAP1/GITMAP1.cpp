#include "pch.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	//русификация:
	setlocale(LC_ALL, "ru");

	//шаблонный класс пары из пространства имен std
	//в контейнере mep первое значение из пары будет ключем
	pair<int, string> p(1, "Телефон");

	//
	map<int, string> mymap;

	//метод insert принимает пару
	mymap.insert(p);

	//метод emplace позволит просто добавить элементы
	mymap.emplace(3, "Монитор");
	mymap.emplace(22, "Процессор");

	//повторно добавить не получиться, только через предв. стирание
	//методы возвращают значение
	auto res = mymap.emplace(22, "ххххх");

	//перегружен [] по ключу
	cout << mymap[3] << endl;

	//можно добавить и так:
	mymap[4] = "Мышь";

	//поиск осуществляется по ключу
	auto it = mymap.find(4);

	//если не находит, возвращает end и при выводе будет ошибка
	//если не сделать проверку
	if (it != mymap.end())
	{
		//здесь без -> не работает
		cout << it->second << endl;
	}
	else
	{
		cout << "элемент не найден" << endl;
	}

	//метод at проверит наличие ключа и даст исключение если его нет
	//
	try
	{
		mymap.at(7) = "Камера";
	}
	catch (const std::exception&exc)
	{
		cout << exc.what() << endl;
		cout << "такого ключа еще нет";
	}

	//git контроль1
}

