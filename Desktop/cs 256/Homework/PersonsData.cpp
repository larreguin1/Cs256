// PersonsData.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

/*PersonsData Class*/
class PersonsData {
private:
	string lastName;
	string firstName;
	string address;
	string city;
	string state;
	string zip;
	string phone;

public:
	PersonsData(string lname, string fname, string addr, string cty, string st, string z, string pn) {
		lastName = lname;
		firstName = fname;
		address = addr;
		city = cty;
		state = st;
		zip = z;
		phone = pn;
	}

	PersonsData() {
		lastName = "";
		firstName = "";
		address = "";
		city = "";
		state = "";
		zip = "";
		phone = "";
	}

	void setLastname(string lname) {
		lastName = lname;
	}

	void setFirstName(string fname) {
		firstName = fname;
	}

	void setAddress(string addy) {
		address = addy;
	}

	void setCity(string c) {
		city = c;
	}

	void setState(string s) {
		state = s;
	}

	void setZip(string z) {
		zip = z;
	}

	void setPhone(string p) {
		phone = p;
	}

	string getLastName() const{
		return lastName;
	}

	string getFirstName() const{
		return firstName;
	}

	string getAddress() const{
		return address;
	}

	string getCity() const{
		return city;
	}

	string getState() const{
		return state;
	}

	string getZip() const{
		return zip;
	}

	string getPhone() const{
		return phone;
	}
};

/*CustomerData Class*/
class CustomerData : public PersonsData {
private:
	int customerNumber;
	bool mailingList;

public:
	CustomerData(string lname, string fname, string addy, string cty, string st, string z, string p, int cNumber, bool mList) :PersonsData(lname, fname, addy, cty, st, z, p) {
		customerNumber = cNumber;
		mailingList = mList;
	}

	//Default
	CustomerData() :PersonsData() {
		customerNumber = 0;
		mailingList = false;
	}

	void setCustomerNumber(int cNumber) {
		customerNumber = cNumber;
	}

	void setMailingList(bool mList) {
		mailingList = mList;
	}

	int getCustomerNumber() {
		return customerNumber;
	}

	int getMailingList() {
		return mailingList;
	}
};

//PreferredCustomer Class
class PreferredCustomer :public CustomerData {
private:
	double purchasesAmount;
	double discountLevel;
public:
	PreferredCustomer() {
	}
	void setdiscountLevel() {
		if (purchasesAmount > 499 && purchasesAmount < 1000) {
			discountLevel = 0.05;
		}
		else if(purchasesAmount > 999 && purchasesAmount < 1500) {
			discountLevel = 0.06;
		}
		else if(purchasesAmount > 1499 && purchasesAmount < 2000) {
			discountLevel = 0.07;
		}
		else if(purchasesAmount > 1999) {
			discountLevel = 0.1;
		}
	}

	void setPurchasesAmount(double purchasesAmt) {
		purchasesAmount = purchasesAmt;
	}

	double getDiscountLevel() {
		return discountLevel;
	}
};

int main()
{
	double purchaseAmount = 500;
	cout << "The purchase amount is: " << purchaseAmount << "\n";
	PreferredCustomer prefCus;
	prefCus.setPurchasesAmount(purchaseAmount);
	prefCus.setdiscountLevel();
	cout << "The discount amount is: " << (prefCus.getDiscountLevel()*100) << "%";
	cin >> purchaseAmount;
    return 0;
}

