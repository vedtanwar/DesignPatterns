#include<iostream>
#include<memory>

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

//Factory Class
class NotificationFactory
{
public:
    static std::unique_ptr<Notification> CreateNotification(const std::string& type)
    {   
       if("email" == type)
       {
        return std::make_unique<EmailNotification>();
       }
       else if("sms" == type)
       {
        return std::make_unique<SMSNotification>();
       }
       return nullptr;
    }

};

int main(int argc, char const *argv[])
{
    std::unique_ptr<Notification> emailNotify =  NotificationFactory::CreateNotification("email");
    std::unique_ptr<Notification> smsNotify = NotificationFactory::CreateNotification("sms");

    emailNotify->Notify();
    smsNotify->Notify();
}


/**
 *  Probleum in Simple Factory:
 *  1. if else growing probleum
 *  2. violates open close principle
 */
