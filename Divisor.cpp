#include "Divisor.h"
#include <iostream>
#include <string>
#include <algorithm>

//Divisor::~Divisor()
//{
//	delete[] arguments;
//}

double Divisor::calculate()
{
	if (arguments[0] == 0)
		return 0;

	double result = arguments[0];
	for (int i = 1; i < size; i++)
	{
		if (arguments[i] == 0)
			return 0;
		result = result / arguments[i];
	}
	return result;
}
//void Divisor::logToScreen() 
//{
//	cout << "Expression [" << size << "] : ";
//
//	for (size_t i = 0; i < size; i++)
//		cout << arguments[i] << " / ";
//
//	cout << "\n= " << calculate() << endl;
//}

void Divisor::shuffle()
{
	srand(time(0));
	random_shuffle(arguments, arguments + size);
}
void Divisor::shuffle(size_t i, size_t j)
{
	if (i || j > size)
		return;

	swap(arguments[i], arguments[j]);
}