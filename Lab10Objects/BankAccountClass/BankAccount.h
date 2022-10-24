#ifndef BANKACCOUNTH
#define BANKACCOUNTH

#include <string>


class BankAccount {
   public:
      // Declare parts of the class
      BankAccount();
      BankAccount(std::string newName, double amt1, double amt2);
      void SetName(std::string newName);
      std::string GetName() {return customerName;}
      void SetChecking(double amt);
      double GetChecking() {return checkingBalance;}
      void SetSavings(double amt);
      double GetSavings() {return savingsBalance;};
      void DepositChecking(double amt); 
      void DepositSavings(double amt);
      void WithdrawChecking(double amt);
      void WithdrawSavings(double amt);
      void TransferToSavings(double amt);
    private:
      // Declare any private methods 
      std::string customerName;
      double savingsBalance;
      double checkingBalance;

};

#endif