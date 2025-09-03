#pragma once

#include "AccountDetails.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Account
{
private:
	std::vector<AccountDetails> m_accountDetails;
public:
	Account();

	void accountMenu();

	void createAccount(const AccountDetails& accountDetails);

	const std::vector<AccountDetails>& getAccountDetails() const;

	long printAccountNo(long accountNo);

	int printPin(long accountNo);

	std::string printName(long accountNo);

	double printAccountBalance(long accountNo);

	void deposit(long accountNo, double amount);

	void withdrawal(long accountNo, double amount);

	void changeName(std::string currName, std::string newName);

	void changeMobileNo(std::string currNo, std::string newNo);

	void showAccountDetails(long accountNo);
};

