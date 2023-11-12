#include "Summator.h"
#include <iostream>
#include <string>


//Summator::~Summator()
//{
//	delete[] arguments;
//}

double Summator::calculate()
{
	double result = 0;
	for (int i = 0; i < size; i++)
		result += arguments[i];

	return result;
}
//void Summator::logToScreen()
//{
//	cout << "Expression [" << size << "] : ";
//
//	for (size_t i = 0; i < size; i++)
//		cout << arguments[i] << " / ";
//
//	cout << "\n= " << calculate() << endl;
//}
