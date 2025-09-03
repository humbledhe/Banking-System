#include "AccountDetails.h"

//AccountDetails::AccountDetails(std::string accountName, long accountNo, int age, std::string mobileNo, double balance, int pin)
//	:m_accountName(""), m_accountNo(0), m_age(0), m_mobileNo(""), m_balance(0), m_pin(0) {
//}

AccountDetails::AccountDetails(std::string accountName, long accountNo, int age, std::string mobileNo, double balance, int pin)
	:m_accountName(accountName), m_accountNo(accountNo), m_age(age), m_mobileNo(mobileNo), m_balance(balance), m_pin(pin) {
}

long AccountDetails::getAccountNo() const
{
	return m_accountNo;
}

std::string AccountDetails::getAccountName() const
{
	return m_accountName;
}

int AccountDetails::getAge() const
{
	return m_age;
}

std::string AccountDetails::getMobileNumber() const
{
	return m_mobileNo;
}

void AccountDetails::setBalance(double balance)
{
	m_balance = balance;
}

double AccountDetails::getBalance() const
{
	return m_balance;
}

int AccountDetails::getPin() const
{
	return m_pin;
}

void AccountDetails::setName(std::string name)
{
	m_accountName = name;
}

void AccountDetails::setMobileNo(std::string mobileNo)
{
	m_mobileNo = mobileNo;
}
