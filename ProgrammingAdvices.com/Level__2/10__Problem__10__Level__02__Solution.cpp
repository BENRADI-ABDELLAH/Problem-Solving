/*
Problem 10 level 2 

Write a program to read a number and print it in order from left to right.

Input:
1234

Output:
1
2
3
4

*/
#include<iostream>
#include<string>
using namespace std;

int ReadPositiveNumber(string Message) {

	int Number = 0;

	do {

		cout << Message << endl;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}
int ReverseNumber(int Number) {

	int Remainder = 0, Number2 = 0;

	while (Number > 0) {

		Remainder = Number % 10;
		Number = Number / 10;
		Number2 = Number2 * 10 + Remainder;

	}
	return Number2;
}
void PrintDigits(int Number) {

	int  Remainder = 0;

	while (Number > 0) {

		Remainder = Number % 10;
		Number = Number / 10;
		cout << Remainder << endl;

	}
}
int main() {

	PrintDigits(ReverseNumber(ReadPositiveNumber("Please enter a positive number?")));
	return 0;

}


