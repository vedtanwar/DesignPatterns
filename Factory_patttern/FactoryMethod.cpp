#include <iostream>
#include <memory>

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

// Factory Method Base Class
class NotificationFactory
{
public:
    virtual Notification *CreateNotification() = 0;

    virtual ~NotificationFactory() {};

    void sendNotification()
    {
        Notification *n = CreateNotification();
        n->Notify();
        delete n;
    }
};

// Concrete Factory Class
class EmailFactory : public NotificationFactory
{
public:
    Notification *CreateNotification() override
    {
        return new EmailNotification();
    }
};

class SMSFactory : public NotificationFactory
{
public:
    Notification *CreateNotification() override
    {
        return new SMSNotification();
    }
};

int main()
{

    NotificationFactory *factory1 = new EmailFactory();
    factory1->sendNotification();

    NotificationFactory* factory2 = new SMSFactory();
    factory2->sendNotification();
}