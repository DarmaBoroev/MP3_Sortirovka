#pragma once
#include <time.h>

using namespace std;

namespace Prog
{
	class Sort //абстрактный класс
	{
	public:
		virtual void sort(int arr[], int size) = 0;
	};

	class Bublle : public Sort
	{
	public:
		Bublle() : arr(0), N(0), K(0), time(0)
		{
		}

		virtual void sort(int arr[], int size)
		{
			int x;
			time = clock();
			for (int k = 0; k < size - 1; ++k)
			{
				for (int j = 0; j < size - 1; ++j)
				{
					K++;
					if (arr[j + 1] < arr[j])
					{
						x = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = x;
						N++;
					}
				}
			}
			time = clock() - time;
			cout << "Отсортированный массив: ";
			for (int i = 0; i < size; ++i)
			{
				cout << arr[i] << " ";
			}
			cout << endl;
			cout << "\tКоличества сравнений: " << K << endl;
			cout <<"\tКоличество перестановок: "<< N << endl;
			cout << "\tВремя сортировки: " << (double)time / CLOCKS_PER_SEC << endl;

			cout << endl;
			delete[] arr;
		}

	private:
		clock_t time; //Время сортировки
		int N; // Количество перестановок
		int K; //Количество сравнений
		int* arr;
	};

	class Insertion : public Sort
	{
	public:
		Insertion() : arr(0), N(0), K(0), time(0)
		{
		}

		virtual void sort(int arr[], int size)
		{
			int x = 0, i, j;
			time = clock();
			for ( i = 1; i < size; i++)
			{
				x = arr[i];
				j = i;
				K++;
				while (j>0 && x < arr[j-1])
				{
					arr[j] = arr[j - 1];
					j--;
					N++; K++;
				}

				if (j != i)
				{
					arr[j] = x;
					N++;
				}
				
			}
			time = clock() - time;

			cout << "Отсортированный массив: ";
			for (int i = 0; i < size; ++i)
			{
				cout << arr[i] << " ";
			}
			cout << endl;
			cout << "\tКоличества сравнений: " << K << endl;
			cout << "\tКоличество перестановок: " << N << endl;
			cout << "\tВремя сортировки: " << (double)time / CLOCKS_PER_SEC << endl;

			cout << endl;
			delete[] arr;
		}

	private:
		clock_t time; //Время сортировки
		int N; // Количество перестановок
		int K; //Количество сравнений
		int* arr;
	};

	class Cycle : public Sort
	{
	public:
		Cycle() : arr(0), N(0), K(0), time(0)
		{
		}

		virtual void sort(int arr[], int size)
		{
			int b, c, x;
			time = clock();
			for (int i = 0; i < size - 1; i++)
			{
				b = arr[i];
				c = i;
				for (int j = i + 1; j < size; j++)
				{
					K++;
					if (arr[j] < b)
						c++;
				}

				if (i == c) continue;

				while (arr[c] == b) c++;
				x = b;
				b = arr[c];
				arr[c] = x;
				N++;

				while (i != c)
				{
					c = i;
					for (int k = i + 1; k < size; k++)
					{
						K++;
						if (arr[k] < b)
							c++;
					}

					while (arr[c] == b) c++;
					x = b;
					b = arr[c];
					arr[c] = x;
					N++;
				}
			}
			time = clock() - time;

			cout << "Отсортированный массив: ";
			for (int i = 0; i < size; i++)
			{
				cout <<arr[i] << " ";
			}

			cout << endl;
			cout << "\tКоличества сравнений: " << K << endl;
			cout << "\tКоличество перестановок: " << N << endl;
			cout << "\tВремя сортировки: " << (double)time / CLOCKS_PER_SEC << endl;
			
			

			cout << endl;
			delete[] arr;
		}

	private:
		clock_t time; //Время сортировки
		int N; // Количество перестановок
		int K; //Количество сравнений
		int* arr;
	};
}
