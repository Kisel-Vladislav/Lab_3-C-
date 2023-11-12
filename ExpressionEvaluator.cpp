#include "ExpressionEvaluator.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ExpressionEvaluator::ExpressionEvaluator(const int SIZE)
{
	arguments = new double[SIZE] {};
	size = SIZE;
}
ExpressionEvaluator::ExpressionEvaluator() : ExpressionEvaluator(20) {};
ExpressionEvaluator::~ExpressionEvaluator() 
{
	delete[] arguments;
};

void ExpressionEvaluator::setOperand(size_t pos, double value)
{
	if (pos >= size)
		return;

	arguments[pos] = value;
}
void ExpressionEvaluator::setOperands(double ops[],size_t n)
{
	if(n > size)
		return;

	for (int i = 0; i < n; i++)
		arguments[i] = ops[i];
}
int ExpressionEvaluator::getSize()
{
	return size;
}
void ExpressionEvaluator::logToScreen(char arithmeticOperators)
{
	cout << "Expression [" << size << "] : ";

	for (size_t i = 0; i < size; i++)
	{
		if (arguments[i] < 0)
			cout << '(' << arguments[i] << ')';
		else
			cout << arguments[i];

		cout << " " << arithmeticOperators << " ";
	}
	cout << "\n= " << calculate() << endl;
}
void ExpressionEvaluator::logToFile(const string& filename,char arithmeticOperators)
{
	fstream fs;
	fs.open(filename, fstream::in | fstream::app);
	
	if (!fs.is_open())
		return;

	fs << "Expression [" << size << "] : ";

	for (size_t i = 0; i < size; i++)
	{
		if(arguments[i] < 0)
			fs << '(' << arguments[i] << ')' << arithmeticOperators << " ";
		else
			fs << arguments[i] << " " << arithmeticOperators << " ";
	}

	fs << "\n= " << calculate() << endl;
}
