#ifndef OBSERVER_HXX
#define OBSERVER_HXX

#include "Subject.hxx"
class Subject;

class Observer{                                     //Observer of the pattern Observer
public:
    Observer(){}
    virtual ~Observer(){};
    
    virtual void update(Subject* subject) = 0;      //This will be specfied in each observer
    
};

#endif