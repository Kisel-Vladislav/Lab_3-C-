#pragma once
#include "ExpressionEvaluator.h"
#include <iostream>
#include <string>
using namespace std;

class Summator : public ExpressionEvaluator
{
public:
	Summator() : ExpressionEvaluator() {};
	Summator(int SIZE) : ExpressionEvaluator(SIZE) {};
	//~Summator() override;

	double calculate() override;
	void logToScreen() override { ::ExpressionEvaluator::logToScreen('+'); };
	void logToFile(const std::string& filename) override { ::ExpressionEvaluator::logToFile(filename, '+'); };
};

