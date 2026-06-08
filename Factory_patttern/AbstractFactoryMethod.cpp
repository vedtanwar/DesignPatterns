#include<iostream>

class Button 
{
public:
    virtual void paint() = 0;
    virtual ~Button() {};
};


class Checkbox 
{
public:
    virtual void paint() = 0;
    virtual ~Checkbox() {};
};


// Windows product
class WindowsButton : public Button
{
public:
    void paint() override{
        std::cout << "Windows Button\n";
    }
};
class WindowsCheckbox : public Checkbox
{
public:
    void paint() override{
        std::cout << "Windows Checkbox\n";
    }
};


//Mac Product
class MacButton : public Button
{
public:
    void paint() override{
        std::cout << "Mac Button\n";
    }
};
class MacCheckboxx : public Checkbox
{
public:
    void paint() override{
        std::cout << "Mac Checkbox\n";
    }
};

// GUI Factory
class GUIfactory
{
public:
    virtual Button* CreateButton() = 0;
    virtual Checkbox* CreateCheckbox() = 0;

    virtual ~GUIfactory() {};
};

class WindowFactory : public GUIfactory
{
public:
    Button* CreateButton() override{
        return new WindowsButton();
    }

    Checkbox* CreateCheckbox() override {
        return new WindowsCheckbox();
    }
};

class MacFactory : public GUIfactory
{
public:
    Button* CreateButton() override{
        return new MacButton();
    }

    Checkbox* CreateCheckbox() override {
        return new MacCheckboxx();
    }
};

int main()
{
    GUIfactory* factory1 = new WindowFactory();
    Button* Winbutton =  factory1->CreateButton();
    Checkbox* WinCheckbox = factory1->CreateCheckbox();

    Winbutton->paint();
    WinCheckbox->paint();
}
