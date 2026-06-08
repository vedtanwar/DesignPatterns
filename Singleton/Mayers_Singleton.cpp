#include <iostream>

/*

    Thread-Safe Singleton (C++11+ BEST VERSION)

    ✔ Lazy initialization
    ✔ Thread-safe (C++11 guarantees static init safety)
    ✔ No heap allocation (no new)
    ✔ No memory leak risk
    ✔ Simple and clean
*/

class Singleton
{
private:
    Singleton() {
        std::cout << "SingleTon Created!!!\n";
    }

    Singleton(const Singleton& ) = delete; // delete Copy Constructor
    Singleton& operator=(const Singleton&) = delete; // delete copy assignment operator

public:

    static Singleton& getInstance()
    {
        static Singleton instance; // thread safe in C++ 11
        return instance;
    }

};

int main()
{

    Singleton& instance1 = Singleton::getInstance();
    Singleton& instacne2 = Singleton::getInstance();


    std::cout << "Instance1 : " << &instance1 << "\n";
    std::cout << "Instance2 : " << &instacne2 << "\n";
}