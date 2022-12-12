#include <iostream>
using namespace std;

class Account {
  public:
    Account(double b) { _balance = b; }
    ~Account() {}

    double GetBalance() { return _balance; }
    virtual void PrintBalance() { cout << "base error" << endl; }

  private:
    double _balance;
};

class Account1 : public Account {
  public:
    Account1(double b) : Account(b) {}
    void PrintBalance() { cout << "num 1: " << GetBalance() << endl; }    
};

class Account2 : public Account {
  public:
    Account2(double b) : Account(b) {}
    void PrintBalance() { cout << "num 2: " << GetBalance() << endl; }    
};

int main() {
    //Account1 account1 = Account1(100.00);
    Account1 account1(100.00);
    Account2 account2(1000.00);

    Account *pAccount = &account1;
    pAccount->PrintBalance();

    pAccount = &account2; 
    pAccount->PrintBalance();
}

