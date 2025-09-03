#include "Account.h"

#include <iostream>
#include <limits>
#include <random>

int main()
{
	Account account;
	account.createAccount(AccountDetails("Prosper", 1020108074, 20, "08023553170", 0, 1590));

	while (true)
	{
		long accountNo{};
		int pin{};

		while (true) // Handling wrong input
		{
			std::cout << "Enter account number: ";
			std::cin >> accountNo;

			std::cout << "Pin: ";
			std::cin >> pin;

			if (std::cin.fail())
			{
				std::cin.clear(); // Clears the input error buffer
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignores wrong input
				system("cls");
				std::cout << "Please provide valid inputs\n\n";
			}
			else
			{
				system("cls");
				break;
			}
		}

		if (accountNo != account.printAccountNo(accountNo) && pin != account.printPin(accountNo))
		{
			std::cout << "Incorrect details\n";
			std::cout << "Your account details does not exist\n\n";

			char option{};

			while (true) 
			{
				std::cout << "Do you wish to create an account(y/n)";
				std::cin >> option;

				if (std::cin.fail()) // Handling wrong input
				{
					std::cin.clear(); // Clears the input buffer
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignores wrong input
					system("cls");
					std::cout << "Please provide valid input\n\n";
				}
				else
				{
					system("cls");
					break;
				}
			}

			int age{}, count = 0;;
			long random{};
			std::string mobileNo{}, accountName{};

			switch (option)
			{
			case 'n': // quit case
				system("cls");
				break;
			case 'y':
				system("cls");

				std::cout << "Enter account name: ";
				std::cin.ignore();
				std::getline(std::cin, accountName);

				while (true)
				{
					std::cout << "Enter age: ";
					std::cin >> age;

					std::cout << "Enter pin: ";
					std::cin >> pin;

					if (std::cin.fail()) // Handling wrong input
					{
						std::cin.clear(); // Clears the input buffer
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignores wrong input
						system("cls");
						std::cout << "Please provide valid inputs\n\n";
					}
					else break;
					
				}

				std::cout << "Enter your mobile number: ";
				std::cin >> mobileNo;

				while (pin > 0) // Checking validity of pin -> Should not be less or more than 4 digits
				{
					pin /= 10;
					count++; // Keeping track of the digits
				}

				if (age < 18)
					std::cout << "You are not eligible to open an account\n";
				else if (count < 4 || count > 4)
				{
					std::cout << "Invalid pin....\n";
					std::cout << "Pin must be 4 digits\n";
				}
				else
				{
					random = 122;

					account.createAccount(AccountDetails(accountName, random, age, mobileNo, 0, pin));

					system("cls");
					std::cout << "Your account number is " << random << std::endl;
				}
				break;
			}
				
		}
		else
		{
			system("cls");

			int option{};

			std::cout << "Welcome " << account.printName(accountNo) << std::endl;

			do
			{
				while (true)
				{
					account.accountMenu(); 

					std::cout << "> ";
					std::cin >> option;

					if (std::cin.fail()) // Handling invalid input
					{
						std::cin.clear(); // Clears the input error buffer
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
						system("cls");
						std::cout << "Please provide valid input\n\n";
					}
					else 
					{
						system("cls");
						break;
					}
				}

				double amount{};
				double userBalance = account.printAccountBalance(accountNo);
				std::string currName{}, newName{}, currNo{}, newNo{};

				switch (option)
				{
				case 1: // Show balance
					std::cout << "Balance: " << userBalance << std::endl << std::endl;
					break;
				case 2: // deposit
					while (true)
					{
						std::cout << "Enter amount: ";
						std::cin >> amount;

						if (std::cin.fail())
						{
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							system("cls");
							std::cout << "Please provide valid input\n\n";
						}
						else
						{
							system("cls");
							break;
						}
					}

					if (amount < 0)
						std::cout << "Invalid amount\n\n";
					else if (amount > INT_MAX)
						std::cout << "Amount can't be greater than " << INT_MAX << std::endl << std::endl;
					else
					{
						std::cout << "Deposit successful\n\n";
						account.deposit(accountNo, amount);
					}
					break;
				case 3:// withdrawal
					while (true)
					{
						std::cout << "Enter amount: ";
						std::cin >> amount;

						if (std::cin.fail())
						{
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							system("cls");
							std::cout << "Please provide valid input\n\n";
						}
						else
						{
							system("cls");
							break;
						}
					}

					if (amount > userBalance)
						std::cout << "Insufficient funds\n\n";
					else if (amount < 0)
						std::cout << "Invalid amount\n\n";
					else if (amount > INT_MAX)
						std::cout << "Amount can't be greater than " << INT_MAX << std::endl << std::endl;
					else
					{
						std::cout << "Deposit successful\n\n";
						account.withdrawal(accountNo, amount);
					}
					break;
				case 4: // Change name
					std::cout << "Enter current name: ";
					std::cin >> currName;

					std::cout << "Enter new name: ";
					std::cin >> newName;

					account.changeName(currName, newName); 
					break;
				case 5: // Change mobile number
					std::cout << "Enter current mobile number: ";
					std::cin >> currNo;

					std::cout << "Enter new mobile number: ";
					std::cin >> newNo;

					account.changeMobileNo(currNo, newNo);
					break;
				case 6: // Show account details
					account.showAccountDetails(accountNo);
					break;
				}
			} while (option != 7);
		}
	}


	return 0;
}