#pragma once
#include "ExpressionEvaluator.h"
#include "IShuffle.h"
#include <iostream>
#include <string>
using namespace std;

class Divisor : public ExpressionEvaluator , public IShuffle
{
public:
	Divisor() : ExpressionEvaluator() {};
	Divisor(int SIZE) : ExpressionEvaluator(SIZE) {};
	//~Divisor() override;

	double calculate() override;
	void logToScreen() override { ::ExpressionEvaluator::logToScreen('/'); };
	void logToFile(const std::string& filename) override { ::ExpressionEvaluator::logToFile(filename, '/'); };

	void shuffle() override;
	void shuffle(size_t i, size_t j) override;
};

