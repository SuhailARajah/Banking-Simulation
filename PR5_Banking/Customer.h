#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <string>
#include <vector>

/**
The Bank has Customers.  Each Customer has a name, address, age, and telephone number.
Additionally, there are specialized types of Customers: Adult, Senior, and Student.
Each type of Customer has its own checking and savings interest rates,
as well as its own checking and overdraft fees.

@author: Ed Walker
*/


class Customer // FIXME: Complete the implementation!
{
private:
	std::string name;
	int age;
	std::string phone_number;
	std::string address;
	int customer_number;
	const double savings_interest = 2.3;
	const double check_interest = 1.4;
	const double check_charge = 35;
	const double overdraft_penalty = 50;
	std::vector <int> accounts;

public:
	Customer() {
		name = "";
		address = "";
		phone_number = "";
		customer_number = 1000;
	}

	Customer(std::string Name, std::string Address, int Age, std::string PhoneNumber, int CustomerNumber) {
		name = Name;
		address = Address;
		age = Age;
		phone_number = PhoneNumber;
		customer_number = CustomerNumber;
	}

	void setName(std::string newName) { name = newName; }

	void setAddress(std::string newAddress) { address = newAddress; }

	void setAge(int newAge) { age = newAge; }

	void setPhone(std::string newPhone) { phone_number = newPhone; }

	void setCustomerNumber(int newNumber) { customer_number = newNumber; }

	void addAccountNumber(int newAccount) { accounts.push_back(newAccount); }

	std::string getName() { return name; }

	std::string getAddress() { return address; }

	double getAge() { return age; }

	std::string getPhoneNumber() { return phone_number; }

	int getCustomerNumber() { return customer_number; }

	std::vector<int> getAccounts() { return accounts; }

	virtual double getSavingsInterest() { return savings_interest; }

	virtual double getCheckingInterest() { return check_interest; }

	virtual double getCheckCharge() { return check_charge; }

	virtual double getOverDraftPenalty() { return overdraft_penalty; }
};

class Senior : public Customer {
private:
	const double savings_interest = 0.7;
	const double check_interest = 0.5;
	const double check_charge = 5;
	const double overdraft_penalty = 25;
public:
	Senior() : Customer() {}
	Senior(std::string Name, std::string Address, int Age, std::string PhoneNumber, int CustomerNumber) :
		Customer(Name, Address, Age, PhoneNumber, CustomerNumber) {}

	double getSavingsInterest() { return savings_interest; }

	double getCheckingInterest() { return check_interest; }

	double getCheckCharge() { return check_charge; }

	double getOverDraftPenalty() { return overdraft_penalty; }
};

class Adult : public Customer {
private:
	const double savings_interest = 0.5;
	const double check_interest = 0.3;
	const double check_charge = 25;
	const double overdraft_penalty = 75;
public:
	Adult() : Customer() {}
	Adult(std::string Name, std::string Address, int Age, std::string PhoneNumber, int CustomerNumber) :
		Customer(Name, Address, Age, PhoneNumber, CustomerNumber) {}

	double getSavingsInterest() { return savings_interest; }

	double getCheckingInterest() { return check_interest; }

	double getCheckCharge() { return check_charge; }

	double getOverDraftPenalty() { return overdraft_penalty; }
};

class Student : public Customer {
private:
	const double savings_interest = 0.2;
	const double check_interest = 0.1;
	const double check_charge = 10;
	const double overdraft_penalty = 50;
public:
	Student() : Customer() {}

	Student(std::string Name, std::string Address, int Age, std::string PhoneNumber, int CustomerNumber) :
		Customer(Name, Address, Age, PhoneNumber, CustomerNumber) {}

	double getSavingsInterest() { return savings_interest; }

	double getCheckingInterest() { return check_interest; }

	double getCheckCharge() { return check_charge; }

	double getOverDraftPenalty() { return overdraft_penalty; }
};

#endif