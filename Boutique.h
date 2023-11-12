#pragma once
#include <string>
#include <iostream>
#include "Shop.h"
class Boutique : public Shop
{
public:
	Boutique() : Shop()
	{
		taxRate = 0.11;
	}
	Boutique(string name, string address, int yearFoundation, string number,
		double totalProfit, double income, string workingHours,
		int numberDiscountedCustomers, bool IsRoundClock) : Shop(name, address, yearFoundation, number, totalProfit, income, workingHours, numberDiscountedCustomers, IsRoundClock)
	{
		taxRate = 0.11;
	}

	void print() override
	{
		cout << "Info Boutique" << endl;
		::Shop::print();
	}
};

