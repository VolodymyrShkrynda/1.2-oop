#pragma once

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Account
{
private:
	int no;
	string name;
	double summa;
	double percent;
public:
	int GetNo() const { return no; }
	string GetName() const { return name; }
	double GetSumma() const { return summa; }
	double GetPercent() const { return percent; }

	void SetName(string value) { name = value; }
	bool SetNo(int value);
	bool SetSumma(double value);
	bool SetPercent(double value);

	bool Init(int no, string name, double summa,double percent);
	void Read();
	void Display();


	double Withdraw();
	double Put();
	void Perc()     {cout<<"Summa + Percent = "<< Put() + (((summa / 100) * percent)) <<endl;}
	void toDollar() {cout<<"Summa in dollar = "<< summa * 0.036   << endl;}
	void toEuro()   {cout<<"Summa in euro = "  << summa * 0.03    << endl; }
	const char* SumToNumeral();



};

