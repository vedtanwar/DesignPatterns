#include<iostream>
#include<vector>
#include<algorithm>

class Observer
{
public:
    virtual void update(const std::string& message) = 0;
    virtual ~Observer() {};
};

class Subject
{
public:
    virtual void attach(Observer* obs) = 0;
    virtual void detach(Observer* obs) = 0;
    virtual void Notify() = 0;
    virtual ~Subject() {}
};

class YouTubeChannel : public Subject
{
    std::vector<Observer*> observers;
    std::string latestVideo;
public:
    void attach(Observer* obs) override
    {
        observers.push_back(obs);
    }

    void detach(Observer* obs) override
    {
        observers.erase(std::remove(observers.begin(), observers.end(), obs), observers.end());
    }

    void Notify() override
    {
        for(auto obs : observers)
        {
            obs->update(latestVideo);
        }
    }

    void setVideo(std::string video)
    {
        latestVideo = video;
        Notify();
    }

};


class Subscriber : public Observer
{
    std::string name;
public:
    Subscriber(const std::string& name) : name{name}
    {}

    void update(const std::string& message)
    {
        std::cout << name << " received: " << message << "\n";
    }
};

int main()
{
    YouTubeChannel channel;

    Subscriber s1("Ved");
    Subscriber s2("Aman");
    Subscriber s3("Ayush");

    channel.attach(&s1);
    channel.attach(&s2);
    channel.attach(&s3);

    channel.setVideo("Observer Pattern in C++");

}