# Introduction
This is an implementation of a simple banking management system (BMS) using classes and functions. It allows users to perform various operations such as **creating an account, displaying account details, requesting a loan,repaying a loan, updating account details,transferring money**.

The BMS uses **C++** classes including private attributes so the personal information may not be visible to the outside members or the member functions that are being used outside the class.The constructor generates a random account number using `rand()` when an object is created.`Getter` and `setter` functions are provided for accessing and modifying account-related information.
# Functions
### 1. addaccount
- Takes a BMS object as a parameter and prompts the user to enter their name, mobile number, and account type (Savings or Current).
- Generates a random account number for the new account using the constructor.
- Calls the deposit function to initialize the account balance based on the account type.
### 2. deposit
- Takes a BMS object as a parameter and prompts the user to enter the amount they want to deposit.
- The deposit amount depends on the account type, with minimum requirements for Savings and Current accounts.
### 3. display
- Takes a BMS object as a parameter and displays the account details, including account number, name, account balance, loan amount, and account type.
### 4. requestLoan
- Takes a BMS object as a parameter and asks the user if they want to apply for a loan.
- If the user agrees, it prompts for the loan amount and calculates the interest amount.
- Updates the loan amount in the object.
### 5. repay_loan
- Takes a BMS object as a parameter and allows the user to repay a portion of their loan.
- If the repayment amount is greater than the loan amount, the excess amount is added to the account balance.
### 6. updateAccount
- Takes a BMS object as a parameter and allows the user to update their account details, including name and mobile number.
### 7. transferMoney
- Takes an array of BMS objects as a parameter and allows the user to transfer money from one account to another.
### 8. check
- Takes an array of BMS objects, a serial number, and a mobile number as parameters.
- Validates the serial number and mobile number for account-related operations.
### 9. main
- Creates an array of BMS objects.
- Provides a menu-driven interface for users to choose various banking operations.
- Calls corresponding functions based on the user's choice.
# Build and Execution

- Build `.exe` binary from the source code `banking_management_system.cpp`

    ```
    g++ -o banking_management_system.exe banking_management_system.cpp
    ```
- Execute the previously created binary

    ```
    .\banking_management_system.exe
    ```
- The output looks as follows

    ```
    ********************************************************WELCOME TO SRM BANK************************************************
    PRESS 1 TO CREATE ACCOUNT
    PRESS 2 TO DISPLAY YOUR ACCOUNT DETAILS
    PRESS 3 TO REQUEST A LOAN
    PRESS 4 TO REPAY YOUR LOAN
    PRESS 5 TO UPDATE ACCOUNT DETAILS
    PRESS 6 TO TRANSFER MONEY
    PRESS 7 TO EXIT
    *************************************************************************************************************************** 
    ```
# Example run
###  Input
```
Enter Your Choice:
1
Enter Your Name: ravi  
Enter Your Mobile Number: 9876543210
Enter the Type of account you want to create (S/C): s
Enter the Amount You want to Deposit, Your Deposit amount should be at least(1000): 2000 

```
### Output
```
Deposited Successfully in Your Account.
Please Remember Your Serial Number is: 55
```

## Note
This code is a simplified example for educational purposes and might not cover all aspects of a real-world banking system, such as security measures and data persistence.And there is no file handling used in the above code to save the data.