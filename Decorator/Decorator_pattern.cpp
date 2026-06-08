#include <iostream>

class Coffee
{
public:
    virtual std::string descrption() = 0;
    virtual int cost() = 0;
    virtual ~Coffee() {}
};


class SimpleCoffee : public Coffee
{
public:
    std::string descrption() override
    {
        return std::string("Simple Coffee");
    }

    int cost() override
    {
        return 100;
    }
};


class CoffeeDecorator : public Coffee
{
    
    public:
    Coffee* coffee;

    CoffeeDecorator(Coffee* c) : coffee(c) {}

    std::string descrption() override
    {
        return coffee->descrption();
    }

    int cost() override 
    {
        return coffee->cost();
    }

};  


class MilkDecorator : public CoffeeDecorator
{
public:
    MilkDecorator(Coffee* c) :CoffeeDecorator(c) {}

    std::string descrption() override
    {
        return coffee->descrption() + " Milk";
    }

    int cost() override
    {
        return coffee->cost() + 10;
    }

};

class SugarDecorator : public CoffeeDecorator
{
public:
    SugarDecorator(Coffee* c) :CoffeeDecorator(c) {}

    std::string descrption() override
    {
        return coffee->descrption() + " Sugar";
    }

    int cost() override
    {
        return coffee->cost() + 30;
    }

};


int main()
{
    Coffee* coffee = new SimpleCoffee();

    coffee = new MilkDecorator(coffee);
    coffee = new SugarDecorator(coffee);

    std::cout << coffee->descrption() << "\n";
    std::cout << coffee->cost() << "\n";

    delete coffee;

}