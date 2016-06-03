#ifndef SUBJECT_HXX
#define SUBJECT_HXX

#include<vector>
#include "Observer.hxx"
#include<utility>
#include<string>

class Observer;

class Subject{                                                  //Subject class of the Observer pattern
    public:
    Subject();
    virtual ~Subject(){};
    
    void attach(Observer *o);                                   //subscrive a observer to that subject
    
    void notify();                                              //notify all observers
    
    virtual std::pair<std::string,std::string> getState()= 0;   //this will be specified in each specific subject

    private:
    std::vector<Observer*> _observers;
};

#endif