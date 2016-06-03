#ifndef SUBJECT_HXX
#define SUBJECT_HXX

#include<vector>
#include "Observer.hxx"
#include<utility>
#include<string>

class Observer;

class Subject{
    public:
    Subject();
    virtual ~Subject(){};
    
    void attach(Observer *o);
    
    void notify();
    
    virtual std::pair<std::string,std::string> getState()= 0;

    private:
    std::vector<Observer*> _observers;
};

#endif