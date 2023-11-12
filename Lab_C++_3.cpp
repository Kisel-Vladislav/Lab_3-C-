#include <iostream>
#include <fstream>
#include <string>
#include "ExpressionEvaluator.h"
#include "Divisor.h"
#include "Summator.h"
#include "CustomExpressionEvaluator.h"
#include "Pharmacy.h"
#include "Boutique.h"

using namespace std;

void Task1();
void Task2();

int main()
{
	cout << "TASK 1:" << endl;
	Task1();
	cout << "\nTASK 2:" << endl;
	Task2();
}

void Task1()
{
	const int SIZE = 3;
	ExpressionEvaluator* evaluators[3];
	evaluators[0] = new Summator(7);
	evaluators[1] = new Divisor(4);
	evaluators[2] = new CustomExpressionEvaluator(5);

	double elementsSummator[] = { 5, 12.5, 9,-1.5, -9.5, 0, 11 };
	evaluators[0]->setOperands(elementsSummator, 7);

	evaluators[1]->setOperand(0, 100);
	evaluators[1]->setOperand(1, -4);
	evaluators[1]->setOperand(2, 2.5);
	evaluators[1]->setOperand(3, -4);

	double elementscustomExpression[] = { 5, 4, -2, 9, 3 };
	evaluators[2]->setOperands(elementscustomExpression, 5);


	for (int i = 0; i < SIZE; i++)
	{
		evaluators[i]->logToScreen();
		evaluators[i]->logToFile("Lab3.txt");
		cout << "\t\t\t\t\t\t\t\t\tevaluators[" << i << "] = " << evaluators[i]->calculate() << endl;
	}
	for (int j = 0; j < SIZE; j++)
	{
		IShuffle* i = dynamic_cast<IShuffle*>(evaluators[j]);
		if (i != nullptr)
		{
			i->shuffle();
			evaluators[j]->logToScreen();

			i->shuffle(0, 1);
			evaluators[j]->logToScreen();
		}
	}
	
	for (int i = 0; i < SIZE; i++)
		delete evaluators[i];
}
void Task2()
{
	// "HealthPoint", "123 Health St", 1999, "001", 50000, 10000, "9am-5pm", 1200
	Pharmacy a("HealthPoint", "123 Health St",2010, "001", 50000, 10000, "9am-5pm",1200,true);
	Boutique b("FashionHub", "456 Style Blvd", 2010, "002", 200000, 40000, "10am-9pm",1000, false);

	a.print();
	b.print();

	a.payTax();
	b.payTax();

	a.print();
	b.print();
}