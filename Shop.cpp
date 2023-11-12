#include "Shop.h"
#include "Shop.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Shop::Shop(string& name, string& address, int yearFoundation,
	string& number, double totalProfit, double income,
	string& workingHours, int numberDiscountedCustomers, bool IsRoundClock)
{
	this->name = name;
	this->address = address;
	this->yearFoundation = yearFoundation > 0? yearFoundation : 0;
	this->number = number;
	this->totalProfit = totalProfit > 0 ? totalProfit : 0;
	this->income = income > 0 ? income : 0;
	this->IsRoundClock = IsRoundClock;
	this->workingHours = workingHours;
	this->numberDiscountedCustomers = numberDiscountedCustomers > 0 ? numberDiscountedCustomers : 0;
	this->taxRate = 0;
}
Shop::Shop()
{
	this->name = "no name";
	this->address = "no andress";
	this->yearFoundation = 0;
	this->number = "+000 000 000 00";
	this->totalProfit = 0;
	this->income = 0;
	this->IsRoundClock = false;
	this->workingHours = "no work";
	this->numberDiscountedCustomers = 0;
	this->taxRate = 0;
};

void Shop::SetName(string &name)
{
	this->name = name;
};
void Shop::SetAddress(string &address)
{
	this->address = address;
};
void Shop::SetYearFoundation(int yearFoundation)
{
	if (yearFoundation > 0)
		this->yearFoundation = yearFoundation;
};
void Shop::SetNumber(string &number)
{
	this->number = number;
};
void Shop::SetTotalProfit(double totalProfit)
{
	if (totalProfit >= 0)
		this->totalProfit = totalProfit;

}
void Shop::SetIncome(double income)
{
	if (income >= 0)
		this->income = income;
}
void Shop::SetWorkingHours(string &workingHours)
{
	this->workingHours = workingHours;
}
void Shop::SetNumberDiscountedCustomers(int numberDiscountedCustomers)
{
	if (numberDiscountedCustomers >= 0)
		this->numberDiscountedCustomers = numberDiscountedCustomers;
}
void Shop::SetIsRoundClock(bool IsRoundClock)
{
	this->IsRoundClock = IsRoundClock;
};

string Shop::GetName()
{
	return name;
};
string Shop::GetAddress()
{
	return address;
};
int Shop::GetYearFoundation()
{
	return yearFoundation;
};
string Shop::GetNumber()
{
	return number;
};
double Shop::GetTotalProfit()
{
	return totalProfit;
};

void Shop::AddToTotalProfit(int value)
{
	totalProfit += value;
};
bool Shop::Serialize()
{
	ofstream fout;
	fout.open("DATA.bin", ofstream::app);

	if (!fout.is_open())
		return false;

	fout.write((char*)this, sizeof(Shop));

	fout.close();
	return true;
}
bool Shop::Deserialize()
{
	ifstream fin;
	fin.open("DATA.bin");

	if (!fin.is_open())
		return false;

	Shop shop;
	while (fin.read((char*)&shop, sizeof(Shop))) // Ошибка из-за стринга в классе
	{
		cout << shop.name << '\t' << shop.address << '\t' << shop.number << '\t' << shop.totalProfit << '\t' << shop.yearFoundation << endl;
	}
	fin.close();

	return true;
}
bool Shop::Serialize(string& filiname)
{
	ofstream fout;
	fout.open(filiname, ofstream::app);

	if (!fout.is_open())
		return false;

	fout.write((char*)this, sizeof(Shop));

	fout.close();
	return true;
}
bool Shop::Deserialize(string& filiname)
{
	ifstream fin;
	fin.open(filiname);

	if (!fin.is_open())
		return false;

	Shop shop;
	while (fin.read((char*)&shop, sizeof(Shop))) // Ошибка из-за стринга в классе
	{
		cout << shop.name << '\t' << shop.address << '\t' << shop.number << '\t' << shop.totalProfit << '\t' << shop.yearFoundation << endl;
	}
	fin.close();

	return true;
}

void Shop::print()
{
	cout << name << '\t' << address << '\t' << yearFoundation << '\t' << number << '\t'
		<< totalProfit << '\t' << income << '\t' << workingHours << '\t'
		<< numberDiscountedCustomers << '\t' << IsRoundClock << endl;
}

void Shop::payTax()
{
	cout << "Taxs = " << totalProfit * taxRate << endl;
	cout << "Total Profit = " << totalProfit << " - " << totalProfit * taxRate << " = " 
		<< totalProfit - totalProfit * taxRate << endl;

	totalProfit -= totalProfit * taxRate;
}
