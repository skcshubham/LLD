#include <bits/stdc++.h>
using namespace std;

// Strategy Interface
class PaymentStrategy {
public:
    virtual void pay(double amount) = 0;
    virtual ~PaymentStrategy() = default;
};

// Strategy Interface
class UPIStrategy : public PaymentStrategy {
public:
    virtual void pay(double amount) = 0;
};

// concrete Strategy : GooglePay
class GooglePay : public UPIStrategy {
public:
    void pay(double amount) override {
        cout << "Payment made using GooglePay of amount " << amount << endl;
    }
};

// concrete Strategy : PayTM
class PayTM : public UPIStrategy {
public:
    void pay(double amount) override {
        cout << "Payment made using PayTM of amount " << amount << endl;
    }
};

// Concrete Strategy: Cash
class Cash : public PaymentStrategy {
public:
    void pay(double amount) override {
        cout << "Payment made using Cash of amount " << amount << endl;
    }
};

class Payment {
private:
    PaymentStrategy* strategy;

public:
    Payment(PaymentStrategy* s) : strategy(s) {}

    void pay(double amount) {
        strategy->pay(amount);
    }
};

int main() {
    Payment p1(new PayTM());
    p1.pay(500);

    Payment p2(new Cash());
    p2.pay(1000);

    return 0;
}
