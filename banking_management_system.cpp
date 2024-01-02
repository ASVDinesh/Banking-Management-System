#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;

int i = 0;

class BMS; // Forward Declaration

void deposit(BMS &obj);
void requestLoan(BMS &obj);
void updateAccount(BMS &obj);
void transferMoney(BMS obj[]);

class BMS {
private:
    long long int accno;

public:
    string name;
    long long int mbno;
    char type;
    long int amount;
    long int loanAmount = 0;

    // Constructor to generate a random account number
    BMS() {
        accno = rand(); // Use a more sophisticated method for better randomness
    }

    bool check_acc(long long int x) {
        return x == accno;
    }

    void setLoanAmount(long int loanAmt) {
        loanAmount = loanAmt;
    }

    long int getLoanAmount() const {
        return loanAmount;
    }

    // Getter function for account number
    long long int getAccNumber() const {
        return accno;
    }
};

void addaccount(BMS &obj) {
    int i = 0;
    // Account number is generated randomly in the constructor
    cout << "Enter Your Name: ";
    getchar();
    getline(cin, obj.name);
    cout << "Enter Your Mobile Number: ";
    cin >> obj.mbno;
    cout << "Enter the Type of account you want to create (S/C): ";
    while (i < 3) {
        cin >> obj.type;
        if (obj.type == 'S' || obj.type == 's' || obj.type == 'C' || obj.type == 'c') {
            break;
        } else {
            cout << "Please Enter a valid expression " << endl;
            cout << "You have " << 2 - i << " attempts left : ";
            i++;
        }
    }
    if (i == 3) {
        exit(0);
    }
    deposit(obj);
}

void display(BMS &obj) {
    cout << "ACCOUNT NUMBER: " << obj.getAccNumber() << endl;
    cout << "NAME: " << obj.name << endl;
    cout << "ACCOUNT BALANCE: " << obj.amount << endl;
    cout << "LOAN AMOUNT: " << obj.getLoanAmount() << endl;
    cout << "ACCOUNT TYPE: " << (obj.type == 's' || obj.type == 'S' ? "SAVINGS" : "CURRENT") << endl;
}

void deposit(BMS &obj) {
    cout << "Enter the Amount You want to Deposit,";
    if (obj.type == 's' || obj.type == 'S') {
        do {
            cout << " Your Deposit amount should be at least(1000): ";
            cin >> obj.amount;
        } while (obj.amount < 1000);
        cout << "Deposited Successfully in Your Account." << endl;
    } else {
        do {
            cout << " Your Deposit amount should be at least(5000): ";
            cin >> obj.amount;
        } while (obj.amount < 5000);
        cout << "Deposited Successfully in Your Account." << endl;
    }
}

void requestLoan(BMS &obj) {
    char ans;
    cout << "Do you want to apply for a loan? (Y/N): ";
    cin >> ans;
    if (ans == 'Y' || ans == 'y') {
        cout << "Enter the loan amount you want: ";
        cin >> obj.loanAmount;
        double interestRate = 0.05; // Assuming a 5% interest rate, you can adjust this accordingly
        double interestAmount = obj.loanAmount * interestRate;
        cout << "Loan Requested Successfully." << endl;
        cout << "Interest Amount: " << interestAmount << endl;
        obj.loanAmount += static_cast<long>(round(interestAmount));
    } else {
        obj.setLoanAmount(0);
        cout << "Loan request declined." << endl;
    }
}

void repay_loan(BMS &obj) {
    if (obj.loanAmount == 0) {
        cout << "YOU HAVE NO LOAN CURRENTLY ON YOUR ACCOUNT.\n";
        return;
    } else {
        long repay;
        cout << "YOUR LOAN AMOUNT IS: " << obj.loanAmount << endl;
        cout << "ENTER AMOUNT YOU WANT TO REPAY: (EXCESS AMOUNT WILL ADDED TO YOUR IF REPAYED AMOUNT)";
        cin >> repay;
        if (repay > obj.loanAmount) {
            repay = repay - obj.loanAmount;
            obj.loanAmount = 0;
            obj.amount += repay;
            cout << "Excess amount added to your account successfully" << endl;
        } else {
            obj.loanAmount -= repay;
            cout << "Amount of " << repay << " rupees is repaid into your loan amount\n";
        }
    }
}

void updateAccount(BMS &obj) {
    cout << "Enter updated name: ";
    getchar();
    getline(cin, obj.name);
    cout << "Enter updated mobile number: ";
    cin >> obj.mbno;
    cout << "Account details updated successfully.\n";
}

void transferMoney(BMS obj[]) {
    long long int senderAcc, receiverAcc;
    int senderIndex, receiverIndex;
    long int transferAmount;

    cout << "Enter your account number (sender): ";
    cin >> senderAcc;

    // Find the sender's account
    for (int j = 0; j < i; ++j) {
        if (obj[j].check_acc(senderAcc)) {
            senderIndex = j;
            break;
        }
    }

    if (!obj[senderIndex].check_acc(senderAcc)) {
        cout << "Sender account not found.\n";
        return;
    }

    cout << "Enter receiver's account number: ";
    cin >> receiverAcc;

    // Find the receiver's account
    for (int j = 0; j < i; ++j) {
        if (obj[j].check_acc(receiverAcc)) {
            receiverIndex = j;
            break;
        }
    }

    if (!obj[receiverIndex].check_acc(receiverAcc)) {
        cout << "Receiver account not found.\n";
        return;
    }

    cout << "Enter the amount to transfer: ";
    cin >> transferAmount;

    if (transferAmount > obj[senderIndex].amount) {
        cout << "Insufficient funds to transfer.\n";
    } else {
        obj[senderIndex].amount -= transferAmount;
        obj[receiverIndex].amount += transferAmount;
        cout << "Transfer successful.\n";
    }
}

int check(BMS obj[], int sno, long long int temp) {
    sno = sno / 50;
    if (sno >= i || sno < 0) {
        cout << "Invalid Serial Number" << endl;
        return -1;
    }
    if (obj[sno].mbno == temp) {
        return sno;
    } else {
        cout << "Invalid Mobile Number\n";
        return -1;
    }
}

int main() {
    // Seed for better randomness
    srand(static_cast<unsigned int>(time(0)));
    BMS obj[100];
    int ch;
    int k = 1;

    while (k) {
        cout << "********************************************************WELCOME TO SRM BANK*******************************************\n";
        cout << "PRESS 1 TO CREATE ACCOUNT\n";
        cout << "PRESS 2 TO DISPLAY YOUR ACCOUNT DETAILS\n";
        cout << "PRESS 3 TO REQUEST A LOAN\n";
        cout << "PRESS 4 TO REPAY YOUR LOAN\n";
        cout << "PRESS 5 TO UPDATE ACCOUNT DETAILS\n";
        cout << "PRESS 6 TO TRANSFER MONEY\n";
        cout << "PRESS 7 TO EXIT\n";
        cout << "***************************************************************************************************************************\n";
        cout << "Enter Your Choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                addaccount(obj[i]);
                cout << "Please Remember Your Serial Number is: " << i * 50 << endl
                     << "This Number is Required for any other Queries regarding Your account. " << endl;
                i++;
                break;
            case 2:
                int sno, r;
                long long int temp;
                cout << "Enter Your Serial Number: ";
                cin >> sno;
                cout << "Please Enter Your Mobile Number for Verification : ";
                cin >> temp;
                r = check(obj, sno, temp);
                if (r >= 0)
                    display(obj[r]);
                else
                    cout << "Try Again entering Valid Input" << endl;
                break;
            case 3:
                int snoLoan, rLoan;
                long long int tempLoan;
                cout << "Enter Your Serial Number for Loan Request: ";
                cin >> snoLoan;
                cout << "Please Enter Your Mobile Number for Verification : ";
                cin >> tempLoan;
                rLoan = check(obj, snoLoan, tempLoan);
                if (rLoan >= 0)
                    requestLoan(obj[rLoan]);
                else
                    cout << "Try Again entering Valid Input" << endl;
                break;
            case 4:
                int s;
                long long int mob;
                cout << "Enter Your serial number: ";
                cin >> s;
                cout << "Enter Mobile Number for verification: ";
                cin >> mob;
                r = check(obj, s, mob);
                if (r != -1)
                    repay_loan(obj[r]);
                else
                    cout << "Account does not exist or you have not entered the valid serial number or mobile number\n";
                break;
            case 5:
                int snoUpdate, rUpdate;
                long long int tempUpdate;
                cout << "Enter Your Serial Number for Account Update: ";
                cin >> snoUpdate;
                cout << "Please Enter Your Mobile Number for Verification : ";
                cin >> tempUpdate;
                rUpdate = check(obj, snoUpdate, tempUpdate);
                if (rUpdate >= 0)
                    updateAccount(obj[rUpdate]);
                else
                    cout << "Try Again entering Valid Input" << endl;
                break;
            case 6:
                transferMoney(obj);
                break;
            case 7:
                cout << "Thank You For Visiting Our Bank";
                k = 0;
                break;
            default:
                cout << "Invalid Choice. Please enter a valid choice." << endl;
        }
    }

    return 0;
}