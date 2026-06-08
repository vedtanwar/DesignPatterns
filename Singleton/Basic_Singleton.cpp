#include <iostream>

/*
    Probleum: 
        1. No Thread Safe
        2. Race Condition Possible
*/

class Singleton
{
private:

    int data;

    static Singleton* instance;
    Singleton() {} // private Constuctor

public:

    static Singleton* getInstance()
    {
        if(instance == nullptr)
    {
            instance = new Singleton();
        }
        return instance;
    }

    int getData() const { return data; }
    void setData(int data_) { data = data_; }

    

};
Singleton* Singleton::instance = nullptr;

int main()
{
    Singleton* instance1 = Singleton::getInstance();
    instance1->setData(3);


    Singleton* instance2 = Singleton::getInstance();
    std::cout << instance2->getData() << "\n"; 


    std::cout << "Instance 1 : " << instance1 << std::endl;
    std::cout << "Instance 2 : " << instance2 << std::endl; // getting same address means singleton Success.

}
