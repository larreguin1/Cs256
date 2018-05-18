#include <iostream>
#include <fstream>

using namespace std;

/*Bank Account Class*/
class bankAccount {
public:
	bankAccount(double, double);
	virtual void deposit(double&, double&, int);
	virtual void withdraw(double&, double&, int);
	virtual void calcInt(double, double);
	virtual void monthlyProc(double, double&, double, int&, int&);
protected:
	double monthlyServiceCharges;
	double monthlyInterestRate;
	double monthlyInterest;
	const double minBalance = 25.00;
};

bankAccount::bankAccount(double initialBalance, double interestRate) {

}

void bankAccount::deposit(double& balance, double& amount, int numDeposits) {
	balance += amount;
	numDeposits++;
}

void bankAccount::withdraw(double& balance, double& amount, int numWithdrawals) {
	balance -= amount;
	numWithdrawals++;
}

void bankAccount::calcInt(double interestRate, double balance) {
	monthlyInterestRate = (interestRate / 12);
	monthlyInterest = balance * monthlyInterestRate;
	balance += monthlyInterest;
}

void bankAccount::monthlyProc(double interestRate, double& balance, double monthlyServiceCharges, int& numDeposits, int& numWithdrawals) {
	balance -= monthlyServiceCharges;
	calcInt(interestRate, balance);

	ofstream outputFile;
	outputFile.open("bankOutput.txt");

	outputFile << "Withdrawals: "<< numWithdrawals << "\n";
	outputFile << "Deposits: " << numDeposits << "\n";
	outputFile << "Service Charges: " << monthlyServiceCharges << "\n";
	outputFile << "Ending balance: " << balance << "\n";

	//Close File
	outputFile.close();

	numWithdrawals = 0;
	numDeposits = 0;
	monthlyServiceCharges = 0;
}

/*Savings Account class*/
class savingsAccount : public bankAccount {
public:
	savingsAccount(double, double);
	void deposit(double);
	void withdraw(double);
	void calcInt(double);
	void monthlyProc();
protected:
	const double withdrawalCharge = 1.00;
	double interestRate;
	double savingsBalance;
	int numDeposits;
	int numWithdrawals;
	bool status = true;
	double monthlyInterest;
	double monthlyInterestRate;
private:
};

savingsAccount::savingsAccount(double initialBalance, double interestRate) : bankAccount(initialBalance, interestRate) {
	savingsBalance = initialBalance;
	interestRate = interestRate;
	numWithdrawals = 0;
	numDeposits = 0;
}

void savingsAccount::deposit(double amount) {
	bankAccount::deposit(savingsBalance, amount, numDeposits);

	if (savingsBalance < minBalance) {
		status = false;
	}
	else if (savingsBalance >= minBalance) {
		status = true;
	}
}

void savingsAccount::withdraw(double amount) {
	bankAccount::withdraw(savingsBalance, amount, numWithdrawals);

	if (savingsBalance < minBalance) {
		status = false;
	}
	else if (savingsBalance >= minBalance) {
		status = true;
	}
}

void savingsAccount::calcInt(double interestRate) {
	bankAccount::calcInt(interestRate, savingsBalance);
}

void savingsAccount::monthlyProc() {
	if (numWithdrawals > 4) {
		monthlyServiceCharges = (numWithdrawals - 4) * withdrawalCharge;
	}

	bankAccount::monthlyProc(interestRate, savingsBalance, monthlyServiceCharges, numDeposits, numWithdrawals);

	if (savingsBalance < minBalance) {
		status = false;
	}
	else if (savingsBalance >= minBalance) {
		status = true;
	}
}

/*Checkings Account Class*/
class checkingAccount : public bankAccount {
public:
	checkingAccount(double, double);
	void deposit(double);
	void withdraw(double);
	void calcInt(double);
	void monthlyProc();
protected:
	double interestRate;
	double checkingBalance;
	int numDeposits;
	int numWithdrawals;
	double monthlyInterest;
	double monthlyInterestRate;
	const double monthlyFee = 5.00;
	const double perWithdrawalFee = 0.10;
	const double serviceCharge = 15.00;
private:
};

checkingAccount::checkingAccount(double initialBalance, double interestRate) : bankAccount(initialBalance, interestRate) {
	checkingBalance = initialBalance;
	interestRate = interestRate;
	numWithdrawals = 0;
	numDeposits = 0;
}

void checkingAccount::deposit(double amount) {
	bankAccount::deposit(checkingBalance, amount, numDeposits);
}

void checkingAccount::withdraw(double amount) {
	if ((checkingBalance - amount) < 0) {
		checkingBalance -= serviceCharge;

		return;
	}
	bankAccount::withdraw(checkingBalance, amount, numWithdrawals);
}

void checkingAccount::calcInt(double interestRate) {
	bankAccount::calcInt(interestRate, checkingBalance);
}

void checkingAccount::monthlyProc() {
	monthlyServiceCharges = monthlyFee + (numWithdrawals * perWithdrawalFee);
	bankAccount::monthlyProc(interestRate, checkingBalance, monthlyServiceCharges, numDeposits, numWithdrawals);
}

/*Main*/
void menu(checkingAccount, savingsAccount);

int main() {
	double initialCBalance;
	double initialSBalance;
	double interestRate = 0;

	//Output 
	ofstream outputFile;
	outputFile.open("bankOutput.txt");

	//Input
	ifstream inputFile;
	inputFile.open("demofile.txt");

	outputFile << "What is the initial balance in the savings account? $";
	inputFile >> initialSBalance;

	outputFile << "What is the initial balance in the checking account? $";
	inputFile >> initialCBalance;

	outputFile << "What is the annual interest rate? ";
	outputFile << interestRate;
	inputFile >> interestRate;
	outputFile << interestRate;

	outputFile << "\n\n";

	outputFile.close();
	inputFile.close();

	checkingAccount checking(initialCBalance, interestRate);
	savingsAccount savings(initialSBalance, interestRate);
	menu(checking, savings);

	system("PAUSE");
	return 0;
}

void menu(checkingAccount checking, savingsAccount savings) {
	int menu_choice;
	double amount;

	//Output 
	ofstream outputFile;
	outputFile.open("bankOutput.txt");

	//Input
	ifstream inputFile;
	inputFile.open("demofile.txt");

	outputFile << "******** BANK ACCOUNT MENU ********" << "\n\n";
	outputFile << "1. Savings Account Deposit\n";
	outputFile << "2. Checking Account Deposit\n";
	outputFile << "3. Savings Account Withdrawal\n";
	outputFile << "4. Checking Account Withdrawal\n";
	outputFile << "5. Update and Display Account Statistics\n";
	outputFile << "6. Exit\n";

	do {
		outputFile << "Your choice, please: (1-6) ";
		outputFile << menu_choice;
		inputFile >> menu_choice;
		outputFile << menu_choice;

		if (menu_choice <= 0 || menu_choice >= 7) {
			outputFile << "Invalid option selected!\n";
		}
	} while (menu_choice <= 0 || menu_choice >= 7);

	switch (menu_choice) {
	case 1:
		outputFile << "Enter amount to deposit: $";
		inputFile >> amount;

		savings.deposit(amount);

		outputFile << "\n\n";

		menu(checking, savings);
		break;
	case 2:
		outputFile << "Enter amount to deposit: $";
		inputFile >> amount;

		checking.deposit(amount);

		outputFile << "\n\n";

		menu(checking, savings);
		break;
	case 3:
		outputFile << "Enter amount to withdraw: $";
		inputFile >> amount;

		savings.withdraw(amount);

		outputFile << "\n\n";

		menu(checking, savings);
		break;
	case 4:
		outputFile << "Enter amount to withdraw: $";
		inputFile >> amount;

		checking.withdraw(amount);

		outputFile << "\n\n";

		menu(checking, savings);
		break;
	case 5:
		outputFile << "\n";

		outputFile << "SAVINGS ACCOUNT MONTHLY STATISTICS:\n";
		savings.monthlyProc();

		outputFile << "\n";

		outputFile << "CHECKING ACCOUNT MONTHLY STATISTICS:\n";
		checking.monthlyProc();

		outputFile << "\n\n";

		menu(checking, savings);
		break;
	case 6:
		outputFile << "\n\n";
		break;
	default:
		break;
	}
	inputFile.close();
	outputFile.close();
}