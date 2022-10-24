#include <iostream>
#include "Bank.h"

Bank::Bank() {
    SetBankName("");
}

Bank::Bank(std::string Name) {
    SetBankName(Name);
}

void Bank::SetBankName(std::string newName) {
    this->bankName = newName;
}

void Bank::AddCustomer(BankAccount b) {
    customers.push_back(b);
}

void Bank::DropCustomer(std::string name) {
    for(int i = 0; i < (int) customers.size(); ++i) {
        std::string currName = customers.at(i).GetName();
        if(name.compare(currName) == 0) {
            customers.erase(customers.begin() + i);
        }
    }
}

double Bank::GetTotalSavings() {
    double res = 0;
    for(int i = 0; i < (int) customers.size(); ++i) {
        res += customers.at(i).GetSavings();
    }
    return res;
}

double Bank::GetTotalChecking() {
    double res = 0;
    for(int i = 0; i < (int) customers.size(); ++i) {
        res += customers.at(i).GetChecking();
    }
    return res;
}

BankAccount Bank::GetTheRichestCustomer() {
    double max = 0;
    BankAccount richest;
    for(int i = 0; i < (int) customers.size(); ++i) {
        int temp = customers.at(i).GetChecking() + customers.at(i).GetSavings();
        if(max < temp) {
            max = temp;
            richest = customers.at(i);
        }
    }
    return richest;
}