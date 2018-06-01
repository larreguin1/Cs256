// Final.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;
class BigNumbers
{
public:
	vector<long,long> vec;

	void operator+(int num1, int num2)
	{
		vec.push_back(num1);
		vec.push_back(num2);
		int add = num1 + num2;
		cout << "\nAddition is: " << add << endl;
	}
	void operator-(int num1, int num2)
	{
		int sub = num1 - num2;
		vec.push_back(num1);
		vec.push_back(num2);
		cout << "\nSubstraction is: " << sub << endl;
	}
	void operator*(int num1, int num2)
	{
		int MULTIPLY = num1*num2;
		vec.push_back(num1);
		vec.push_back(num2);
		cout << "\nMultiplication is: " << MULTIPLY << endl;
	}
	void operator /(int num1, int num2)
	{
		int DIVIDE = num1 / num2;
		vec.push_back(num1);
		vec.push_back(num2);
		cout << "\nDivision is: " << DIVIDE << endl;
	}
	void operator %(int num1, int num2)
	{
		int MOD = num1%num2;
		vec.push_back(num1);
		vec.push_back(num2);
		cout << "\nMod :" << MOD << endl;
	}
};
int main()
{
	BigNumbers obj;
	+obj(10, 20);
	-obj(45, 30);
	*obj(10, 10);
	/ obj(64, 4);
	%obj(100, 10);
	return 0;
}

