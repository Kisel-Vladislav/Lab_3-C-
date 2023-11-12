#pragma once
#include "ExpressionEvaluator.h"
#include "IShuffle.h"
#include <iostream>
#include <string>
using namespace std;

class CustomExpressionEvaluator : public ExpressionEvaluator, public IShuffle
{
public:
	CustomExpressionEvaluator() : ExpressionEvaluator() {};
	CustomExpressionEvaluator(int SIZE) : ExpressionEvaluator(SIZE) {};

	double calculate() override;
	void logToScreen() override;
	void logToFile(const std::string& filename) override;

	void shuffle() override;
	void shuffle(size_t i, size_t j) override;
};

