/*

Problem 47:

Write a program to read a LoanAmount and Monthly Payment and calculate how many months you need to
settle the loan.

Input
5000
500

Outputs
10 Months

*/

#include <iostream>
#include <string>
using namespace std;
float ReadPositiveNumber(string Message)
{
	float Number = 0;
	do
	{

		cout << Message << endl;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}
float TotalMonths(float LoanAmiount, float MonthlyInstallment)
{
	return (float)LoanAmiount / MonthlyInstallment;
}
int main()
{

	float LoanAmiount = ReadPositiveNumber("Pleas Enter Loan Amiount ?");
	float MonthlyInstallment = ReadPositiveNumber("Pleas Enter Monthly Installmentt ?");

	cout << "\n Total Months to pay = " << TotalMonths(LoanAmiount, MonthlyInstallment) << endl;

	return 0;
}
