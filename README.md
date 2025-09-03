# Banking System

## Overview

This is a simple console-based Banking System written in C++ (C++14). It allows users to create and manage bank accounts, perform deposits and withdrawals, and update account information. The system uses object-oriented principles and stores account details in memory.

## Features

- Create new bank accounts (with age and PIN validation)
- Login with account number and PIN
- View account balance
- Deposit and withdraw funds
- Change account name and mobile number
- View full account details
- Input validation for all user entries

## Structure

- **Main.cpp**: Entry point, handles user interaction and menu navigation.
- **Account.h / Account.cpp**: Defines the `Account` class for managing multiple accounts and operations.
- **AccountDetails.h**: Defines the `AccountDetails` class for storing individual account information.

## How to Build

1. Open the solution in Visual Studio 2022.
2. Ensure all source files are included in the project.
3. Build the project using the __Build Solution__ command.

## How to Run

1. Run the compiled executable.
2. Follow the on-screen prompts to log in or create a new account.
3. Use the menu to perform banking operations.

## Requirements

- C++14 compatible compiler (tested with Visual Studio 2022)
- No external dependencies

## Notes

- All data is stored in memory; closing the application will erase all accounts.
- PIN must be exactly 4 digits.
- Minimum age to open an account is 18.

## Example Usage