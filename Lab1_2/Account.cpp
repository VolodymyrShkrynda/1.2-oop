#include "Account.h"

using namespace std;

bool Account::SetNo(int value)
{
	if (value > 0)
	{
		no = value;
		return true;
	}
	else
	{
		no = 0;
		return false;
	}
}
bool Account::SetSumma(double value)
{
	if (value > 0)
	{
		summa = value;
		return true;
	}
	else
	{
		summa = -value;
		return false;
	}

}
bool Account::SetPercent(double value)
{
	if (value > 0)
	{
		percent = value;
		return true;
	}
	else
	{
		percent = -value;
		return false;
	}

}
bool Account::Init(int no, string name, double summa,double percent)
{
	SetName(name);
	return SetNo(no) && SetSumma(summa) && SetPercent(percent);
}
void Account::Read()
{
	string name;
	int no;
	double summa;
	double percent;
		do
		{
			cout << " no      = ? "; cin >> no;
			cout << " name  = ? ";   cin >> name;
			cout << " summa   = ? "; cin >> summa;
			cout << " percent = ? "; cin >> percent;
		} while (!Init(no, name, summa, percent));
}
void Account::Display()
{
	cout << " no    = "   << no << endl;
	cout << " name  = "   << name << endl;
	cout << " summa = "   << summa<< endl;
	cout << " percent = " << percent << endl;
}
double Account::Withdraw()
{
	double add;
	cout << "—ума ст€гу: "; cin >> add;
	return summa -= add;
}
double Account::Put()
{
	double add;
	cout << "—ума начисленн€: "; cin >> add;
	return summa += add;
}
const char* Account::SumToNumeral()
{
	const char* _centuries[11] = { "",
	"сто",
	"дв≥ст≥",
	"триста",
	"чотириста",
	"п'€тсот",
	"ш≥стсот",
	"с≥мсот",
	"в≥с≥мсот",
	"дев'€тсот",
	"тис€ча або б≥льше" };
	const char* _decades[10] = { "",
	"",
	"двадц€ть",
	"тридц€ть",
	"сорок",
	"п'€тдес€т",
	"ш≥стдес€т",
	"с≥мдес€т",
	"в≥с≥мдес€т",
	"дев'€носто" };
	const char* _digits[20] = { "",
	"один",
	"два",
	"три",
	"чотири",
	"п'€ть",
	"ш≥сть",
	"с≥м",
	"в≥с≥м",
	"дев'€ть",
	"дес€ть",
	"одинадц€ть",
	"дванадц€ть",
	"тринадц€ть",
	"чотирнадц€ть", "п'€тнадц€ть",
	"ш≥стнаднадц€ть",
	"с≥мнадц€ть",
	"в≥с≥мнадц€ть", "дев'€тнадц€ть" };
	if (summa >= 1000)
		return _centuries[10];

	int sum = floor(summa);
	int cen = sum / 100;
	sum = sum % 100;
	int dec = sum / 10;
	int dig;
	if (dec == 0 || dec == 1)
		dig = sum % 20;
	else
		dig = sum % 10;
	char s[100] = "";
	strcat_s(s, _centuries[cen]);
	strcat_s(s, " ");
		strcat_s(s, _decades[dec]);
	strcat_s(s, " ");
		strcat_s(s, _digits[dig]);
	return s;
}