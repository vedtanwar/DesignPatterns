#include<iostream>

class PaymentStrategy
{
public:
    virtual void pay(int amount) = 0;
    virtual ~PaymentStrategy() {}
};


class CardPayment : public PaymentStrategy
{
public:
    void pay(int amount) override
    {
        std::cout << "PAID " << amount << " using Card.\n";
    }
};
class UpiPayment : public PaymentStrategy
{
public:
    void pay(int amount) override
    {
        std::cout << "PAID " << amount << " using UPI.\n";
    }
};
class WalletPayment : public PaymentStrategy
{
public:
    void pay(int amount) override
    {
        std::cout << "PAID " << amount << " using Wallet.\n";
    }
};

class PaymentContext
{
    PaymentStrategy *strategy;

public:
    PaymentContext(PaymentStrategy* s) : strategy(s) {}

    void setStrategy(PaymentStrategy *s)
    {
        strategy = s; 
    }

    void executePayment(int amount)
    {
        strategy->pay(amount);
    }
};


int main()
{
    CardPayment card;
    UpiPayment upi;
    WalletPayment wallet;

    PaymentContext context(&card);
    context.executePayment(1000);
}