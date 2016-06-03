#include "Subject.hxx"
#include "Observer.hxx"
#include<utility>
#include<string>

Subject::Subject(){}

void Subject::attach(Observer *o){
    _observers.push_back(o);
}

void Subject::notify(){
    for(unsigned int i = 0; i < _observers.size() ; ++i){
        _observers[i]->update(this);
    }
}
