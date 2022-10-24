#include <iostream>
#include "BankAccount.h"

BankAccount::BankAccount() {
    customerName = "";
    SetChecking(0);
    SetSavings(0);
}

BankAccount::BankAccount(std::string newName, double amt1, double amt2) {
    customerName = newName;
    SetChecking(amt1);
    SetSavings(amt2);
}

void BankAccount::SetName(std::string newName) {
    customerName = newName;
}

void BankAccount::SetChecking(double amt) {
    if(amt >= 0.0) {
    checkingBalance = amt;
    }
}
    
void BankAccount::SetSavings(double amt) {
    if(amt >= 0.0) {
    savingsBalance = amt;
    }
}

void BankAccount::DepositChecking(double amt) {
    if(amt >= 0.0) {
    checkingBalance += amt;
    }
}

void BankAccount::DepositSavings(double amt) {
    if(amt >= 0.0) {
    savingsBalance += amt;
    }
}

void BankAccount::WithdrawChecking(double amt) {
    if((amt >= 0.0) && (checkingBalance - amt >= -100)) {
        checkingBalance -= amt;
    }
}

void BankAccount::WithdrawSavings(double amt) {
    if((amt >= 0.0) && (savingsBalance - amt >= -100)) {
        savingsBalance -= amt;
    }
}

void BankAccount::TransferToSavings(double amt) {
    if((amt >= 0.0) && (checkingBalance - amt >= -100)) {
        checkingBalance -= amt;
        savingsBalance += amt;
    }
}
