#pragma once
#include "ILoggable.h"
#include "IShuffle.h"
#include <string>
using namespace std;
class ExpressionEvaluator : public ILoggable
{
public:

	ExpressionEvaluator();
	ExpressionEvaluator(const int SIZE);
	virtual ~ExpressionEvaluator();
	
	virtual double calculate() = 0;
	void setOperand(size_t pos, double value);
	void setOperands(double ops[], size_t n);
	int getSize();
	void virtual logToScreen() = 0;
	void virtual logToFile(const std::string& filename) = 0;
	

protected:
	double* arguments;
	int size;

	void logToScreen(char arithmeticOperators);
	void logToFile(const string& filename, char arithmeticOperators);
};

