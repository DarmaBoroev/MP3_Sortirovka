#include <iostream>
#include <string>
#include <time.h>
#include "Sortirovki.h"
#include <fstream>
#include <conio.h>

using namespace std;
using Prog::Sort;
using Prog::Bublle;
using Prog::Insertion;
using Prog::Cycle;

int main()
{
	setlocale(LC_ALL, "Rus");
	try{
		cout << ":::::::::::::::::::::::::::::" << endl;
		cout << "::                         ::" << endl;
		cout << "::   Тема: Сортировки      ::" << endl;
		cout << "::   Выполнили: Бороев Д.  ::" << endl;
		cout << "::              Зайцев М.  ::" << endl;
		cout << "::                         ::" << endl;
		cout << ":::::::::::::::::::::::::::::" << endl;
		cout << endl;
		// создание элементов для обычной сортировки:
		Bublle el1;
		Insertion el2;
		Cycle el3;

		Sort *pr1 = &el1;
		Sort *pr2 = &el2;
		Sort *pr3 = &el3;

		//создание эддементов для генерации вариантов
		Bublle bestBub;
		Insertion bestIns;
		Cycle bestCyc;

		Bublle worstBub;
		Insertion worstIns;
		Cycle worstCyc;

		Sort* bBub = &bestBub;
		Sort* bIns = &bestIns;
		Sort* bCyc = &bestCyc;

		Sort* wBub = &worstBub;
		Sort* wIns = &worstIns;
		Sort* wCyc = &worstCyc;

		srand((unsigned)time(NULL));
		int size, n;
		cout << "Введите размер массива: ";
		if (!(cin >> size) || size == 0)
		{
			throw string("Некорректные данные!");
		}
		cout << "Введите диапазон значений: ";
		if (!(cin>>n) || n==0 )
		{
			throw string("Некорректные значения!");
		}

		int *arr1 = new int[size]; //для пузырьковой сортировки
		int *arr2 = new int[size]; //для сортировки вставками
		int *arr3 = new int[size]; //для циклической сортировки

		int* best1 = new int[size];
		int* best2 = new int[size];
		int* best3 = new int[size];

		int* worst1 = new int[size];
		int* worst2 = new int[size]; 
		int* worst3 = new int[size];

		cout << "Исходный массив: ";
		for (int i = 0; i < size; ++i)
		{
			arr1[i] = 1 + rand() % n;
			arr2[i] = arr1[i]; // копирование массива для сортировки вставками
			arr3[i] = arr1[i]; // копирование массива для циклической сортировки
			cout << arr1[i] << " ";
		}

		cout << endl;
		cout << endl;

		cout << "ПУЗЫРЬКОВАЯ СОРТИРОВКА:" << endl;
		pr1->sort(arr1, size);
		cout << endl;

		cout << "СОРТИРОВКА ВСТАВКАМИ:" << endl;
		pr2->sort(arr2, size);
		
		cout << "ЦИКЛИЧЕСКАЯ СОРТИРОВКА: " << endl;
		pr3->sort(arr3, size);

		//Генерация лучших и худших вариантов
		cout << ":::::ГЕНЕРАЦИЯ ВАРИАНТОВ:::: " << endl;
		cout << endl;
		cout << "Исходный массив ЛУЧШЕГО варианта: ";
		for (int i = 0; i < size; i++)
		{
			best1[i] = i;
			best2[i] = best1[i];
			best3[i] = best1[i];
			cout << best1[i] << " ";
		}
		cout << endl;

		cout << "Исходный массив ХУДШЕГО варианта: ";
		for (int i = 0; i < size; i++)
		{
			worst1[i] = (size - 1) - i;
			worst2[i] = worst1[i];
			worst3[i] = worst1[i];
			cout << worst1[i] << " ";
		}

		cout << endl;
		cout << endl;

		cout << "ПУЗЫРЬКОВАЯ СОРТИРОВКА: " << endl;
		cout << "(Лучший вариант) " << endl;
		bBub->sort(best1, size);

		cout << "(Худший вариант) " << endl;
		wBub->sort(worst1, size);

		cout << "СОРТИРОВКА ВСТАВКАМИ: " << endl;
		cout << "(Лучший вариант) " << endl;
		bIns->sort(best2, size);

		cout << "(Худший вариант) " << endl;
		wIns->sort(worst2, size);

		cout << "ЦИКЛИЧЕСКАЯ СОРТИРОВКА: " << endl;
		cout << "(Лучший вариант) " << endl;
		bCyc->sort(best3, size);

		cout << "(Худший вариант) " << endl;
		wCyc->sort(worst3, size);

	}

	catch (const string e)
	{
		cout << e << endl;
	}

	system("pause");
	return 0;
}