#include<iostream>

// Base Class
class Notification
{
public:
    virtual void Notify() = 0;
    virtual ~Notification() {}
};

// Derived Class
class EmailNotification : public Notification
{
public:
    void Notify() override
    {
        std::cout << "Email Sent!! ✅\n";
    }
};

// Derived Class
class SMSNotification : public Notification
{
public:
    void Notify() override
    {
        std::cout << "SMS Sent!! ✅\n";
    }
};


template<typename T>
class Factory
{
public:
    static Notification* create()
    {
        return new T();
    }
};

int main()
{
    Notification* emailNoti = Factory<EmailNotification>::create();
    emailNoti->Notify();
    Notification* smsNoti = Factory<SMSNotification>::create();
    smsNoti->Notify();
}