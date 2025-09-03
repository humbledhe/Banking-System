#pragma once

#include <iostream>
#include <string>

class AccountDetails
{
private:
	std::string m_accountName;
	long m_accountNo;
	int m_age;
	std::string m_mobileNo;
	double m_balance;
	int m_pin;

public:
	//AccountDetails(std::string accountName, long accountNo, int age, std::string mobileNo, double balance, int pin);

	AccountDetails(std::string accountName, long accountNo, int age, std::string mobileNo, double balance, int pin);

	long getAccountNo() const;

	std::string getAccountName() const;

	int getAge() const;

	std::string getMobileNumber() const;

	void setBalance(double balance);

	double getBalance() const;

	int getPin() const;

	void setName(std::string name);

	void setMobileNo(std::string mobileNo);
};

