#pragma once
#include <string>
#include "ITaxPayment.h"
using namespace std;
class Shop : ITaxPayment
{
public:
	Shop(string& name, string& address, int yearFoundation, string& number, double totalProfit,
		double income, string& workingHours, int numberDiscountedCustomers, bool IsRoundClock);
	Shop();

	void SetName(string &name);
	void SetAddress(string &address);
	void SetYearFoundation(int yearFoundation);
	void SetNumber(string &number);
	void SetTotalProfit(double totalProfit);

	void  SetIncome(double income);
	void  SetWorkingHours(string &workingHours);
	void  SetNumberDiscountedCustomers(int numberDiscountedCustomers);
	void  SetIsRoundClock(bool IsRoundClock);
	
	string GetName();
	string GetAddress();
	int GetYearFoundation();
	string GetNumber();
	double GetTotalProfit();

	void AddToTotalProfit(int value);
	bool Serialize();
	bool Deserialize();
	bool Serialize(string& filiname);
	bool Deserialize(string& filiname);
	virtual void print();

	void payTax() override;

protected:
	string name;
	string address;
	int yearFoundation;
	string number;
	double totalProfit;
	double income;
	string workingHours;
	int numberDiscountedCustomers;
	bool IsRoundClock;
	double taxRate;
};

