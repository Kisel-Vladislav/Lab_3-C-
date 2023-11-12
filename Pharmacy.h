#pragma once
#include "Shop.h"
#include <iostream>
class Pharmacy : public Shop
{
public:
	Pharmacy() : Shop()
	{
		taxRate = 0.07;
	}
	Pharmacy(string name, string address, int yearFoundation, string number,
		double totalProfit, double income, string workingHours,
		int numberDiscountedCustomers, bool IsRoundClock) : Shop(name, address, yearFoundation, number, totalProfit, income, workingHours, numberDiscountedCustomers, IsRoundClock)
	{
		taxRate = 0.07;
	}

	void print() override
	{
		cout << "Info Pharmacy" << endl;
		::Shop::print();
	}
};

