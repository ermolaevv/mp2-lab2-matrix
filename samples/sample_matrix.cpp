// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "tmatrix.h"
//---------------------------------------------------------------------------

void main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Тестирование класс работы с матрицами" << endl;
	
	size_t size;
	int op;
	cout << "Введите размер матрицы A: ";
	cin >> size;

	TDynamicMatrix<double> a(size);
	cout << "Введите элементы матрицы А:" << endl;
	for (size_t i = 0; i < size; i++)
		for (size_t j = 0; j < size; j++)
		{
			cin >> a[i][j];
		}

	cout << "Введите размер матрицы B: ";
	cin >> size;
	TDynamicMatrix<double> b(size);
	cout << "Введите элементы матрицы B:" << endl;
	for (size_t i = 0; i < size; i++)
		for (size_t j = 0; j < size; j++)
		{
			cin >> b[i][j];
		}

	cout << endl << "1. Сложить\n2. Вычесть\n3. Умножить\n4. Разделить\n";
	cout << "Введите номер операции: ";
	cin >> op;
	switch (op)
	{
	case 1:
		cout << "A + B:" << endl << a + b << endl;	
		break;
	case 2:
		cout << "A - B:" << endl << a - b << endl;
		break;
	case 3:
		cout << "A * B:" << endl << a * b << endl;
		break;
	case 4:
		cout << "A / B:" << endl << a / b << endl;
		break;
	default:
		break;
	}
}
//---------------------------------------------------------------------------
