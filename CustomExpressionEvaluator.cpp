#include "CustomExpressionEvaluator.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>

double CustomExpressionEvaluator::calculate()
{
	if (arguments[0] == 0)
		return 0;

	double result = arguments[0];
	for (int i = 1; i < size; i++)
	{
		if (i % 2 == 0)
			result += arguments[i];
		else
			result -= arguments[i];
	}
	return result;
}
void CustomExpressionEvaluator::logToScreen()
{
	cout << "Expression [" << size << "] : ";

	for (size_t i = 0; i < size; i++)
	{
		if (arguments[i] < 0)
			cout << '(' << arguments[i] << ')';
		else
			cout << arguments[i];

		if (i % 2 == 0)
			cout << " - ";
		else
			cout << " + ";
	}
	cout << "\n= " << calculate() << endl;
}
void CustomExpressionEvaluator::logToFile(const std::string& filename)
{
	fstream fs;
	fs.open(filename, fstream::in | fstream::app);

	if (!fs.is_open())
		return;

	fs << "Expression [" << size << "] : ";

	for (size_t i = 0; i < size; i++)
	{
		if (arguments[i] < 0)
			fs << '(' << arguments[i] << ')';
		else
			fs << arguments[i];

		if (i % 2 == 0)
			fs << " - ";
		else
			fs << " + ";
	}
	fs << "\n= " << calculate() << endl;
}

void CustomExpressionEvaluator::shuffle()
{
	srand(time(0));
	random_shuffle(arguments, arguments + size);
}
void CustomExpressionEvaluator::shuffle(size_t i, size_t j)
{
	if (i || j > size)
		return;

	swap(arguments[i], arguments[j]);
}