#ifndef OBSERVER_HXX
#define OBSERVER_HXX

#include "Subject.hxx"
class Subject;

class Observer{
public:
    Observer(){}
    virtual ~Observer(){};
    
    virtual void update(Subject* subject) = 0;
    
};

#endif