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
		cout << "::   ����: ����������      ::" << endl;
		cout << "::   ���������: ������ �.  ::" << endl;
		cout << "::              ������ �.  ::" << endl;
		cout << "::                         ::" << endl;
		cout << ":::::::::::::::::::::::::::::" << endl;
		cout << endl;
		// �������� ��������� ��� ������� ����������:
		Bublle el1;
		Insertion el2;
		Cycle el3;

		Sort *pr1 = &el1;
		Sort *pr2 = &el2;
		Sort *pr3 = &el3;

		//�������� ���������� ��� ��������� ���������
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
		cout << "������� ������ �������: ";
		if (!(cin >> size) || size == 0)
		{
			throw string("������������ ������!");
		}
		cout << "������� �������� ��������: ";
		if (!(cin>>n) || n==0 )
		{
			throw string("������������ ��������!");
		}

		int *arr1 = new int[size]; //��� ����������� ����������
		int *arr2 = new int[size]; //��� ���������� ���������
		int *arr3 = new int[size]; //��� ����������� ����������

		int* best1 = new int[size];
		int* best2 = new int[size];
		int* best3 = new int[size];

		int* worst1 = new int[size];
		int* worst2 = new int[size]; 
		int* worst3 = new int[size];

		cout << "�������� ������: ";
		for (int i = 0; i < size; ++i)
		{
			arr1[i] = 1 + rand() % n;
			arr2[i] = arr1[i]; // ����������� ������� ��� ���������� ���������
			arr3[i] = arr1[i]; // ����������� ������� ��� ����������� ����������
			cout << arr1[i] << " ";
		}

		cout << endl;
		cout << endl;

		cout << "����������� ����������:" << endl;
		pr1->sort(arr1, size);
		cout << endl;

		cout << "���������� ���������:" << endl;
		pr2->sort(arr2, size);
		
		cout << "����������� ����������: " << endl;
		pr3->sort(arr3, size);

		//��������� ������ � ������ ���������
		cout << ":::::��������� ���������:::: " << endl;
		cout << endl;
		cout << "�������� ������ ������� ��������: ";
		for (int i = 0; i < size; i++)
		{
			best1[i] = i;
			best2[i] = best1[i];
			best3[i] = best1[i];
			cout << best1[i] << " ";
		}
		cout << endl;

		cout << "�������� ������ ������� ��������: ";
		for (int i = 0; i < size; i++)
		{
			worst1[i] = (size - 1) - i;
			worst2[i] = worst1[i];
			worst3[i] = worst1[i];
			cout << worst1[i] << " ";
		}

		cout << endl;
		cout << endl;

		cout << "����������� ����������: " << endl;
		cout << "(������ �������) " << endl;
		bBub->sort(best1, size);

		cout << "(������ �������) " << endl;
		wBub->sort(worst1, size);

		cout << "���������� ���������: " << endl;
		cout << "(������ �������) " << endl;
		bIns->sort(best2, size);

		cout << "(������ �������) " << endl;
		wIns->sort(worst2, size);

		cout << "����������� ����������: " << endl;
		cout << "(������ �������) " << endl;
		bCyc->sort(best3, size);

		cout << "(������ �������) " << endl;
		wCyc->sort(worst3, size);

	}

	catch (const string e)
	{
		cout << e << endl;
	}

	system("pause");
	return 0;
}