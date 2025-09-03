#include "Account.h"

Account::Account() {}

void Account::createAccount(const AccountDetails& accountDetails)
{
	m_accountDetails.push_back(accountDetails);
}

void Account::accountMenu()
{
	std::cout << "1. Show balance\n";
	std::cout << "2. Deposit\n";
	std::cout << "3. withdraw\n";
	std::cout << "4. Change name\n";
	std::cout << "5. Change mobile number\n";
	std::cout << "6. show account details\n";
}

const std::vector<AccountDetails>& Account::getAccountDetails() const
{
	return m_accountDetails;
}

long Account::printAccountNo(long accountNo)
{
	long userAccountNo{};

	for (auto& a : m_accountDetails)
	{
		if (accountNo == a.getAccountNo())
			userAccountNo = a.getAccountNo();
	}

	return userAccountNo;
}

int Account::printPin(long accountNo)
{
	int userPin{};

	for (auto& a : m_accountDetails)
	{
		if (accountNo == a.getAccountNo())
			userPin = a.getPin();
	}

	return userPin;
}

std::string Account::printName(long accountNo)
{
	std::string userAccountName{};

	for (auto& a : m_accountDetails)
	{
		if (accountNo == a.getAccountNo())
			userAccountName = a.getAccountName();
	}

	return userAccountName;
}

double Account::printAccountBalance(long accountNo)
{
	double userAccountBalance{};

	for (auto& a : m_accountDetails)
	{
		if (accountNo == a.getAccountNo())
			userAccountBalance = a.getBalance();
	}

	return userAccountBalance;
}

void Account::deposit(long accountNo, double amount)
{
	
	for (auto& a : m_accountDetails)
	{
		if (accountNo == a.getAccountNo())
			a.setBalance(a.getBalance() + amount);
	}
}

void Account::withdrawal(long accountNo, double amount)
{
	for (auto& a : m_accountDetails)
	{
		if (accountNo == a.getAccountNo())
			a.setBalance(a.getBalance() - amount);
	}
}

void Account::changeName(std::string currName, std::string newName)
{
	for (auto& details : m_accountDetails)
	{
		if (currName == details.getAccountName())
			details.setName(newName);
		else
			std::cout << "Incorrect name\n";
	}
}

void Account::changeMobileNo(std::string currNo, std::string newNo)
{
	for (auto& details : m_accountDetails)
	{
		if (currNo == details.getMobileNumber())
			details.setMobileNo(newNo);
		else
			std::cout << "Incorrect mobile number\n";
	}
}

void Account::showAccountDetails(long accountNo)
{
	for (auto& details : m_accountDetails)
	{
		if (accountNo == details.getAccountNo())
		{
			std::cout << "Account name: " << details.getAccountName() << std::endl;
			std::cout << "Account number: " << details.getAccountNo() << std::endl;
			std::cout << "Mobile number: " << details.getMobileNumber() << std::endl;
			std::cout << "Account balance: " << details.getBalance() << std::endl;
			std::cout << "Age: " << details.getAge() << std::endl << std::endl;
		}
	}
}


