#include<bits/stdc++.h>
using namespace std;


/*

Factory
Abstract factory

*/


class Button {

};

class Widget {

};


class DarkButton : public Button {

};

class LightButton : public Button{

};


// anstract factory : 
class UIFactory {

    virtual Button* createBtn() =  0;

    virtual Widget* createWidget() = 0;

    
};

class DarkFactory : public UIFactory{
    
};

class LightFactory : public UIFactory{

};

// use them like this : UIFactory * factory = () ? new DarkFactory () : new LightFactory();


// factory->createBtn();
// factory->createWidget()



// SIngleton pattern

/*
static variables : they don't belong to the class or an object
shared by all the objects of a given class
Logger:: var;

static variables are only initilaised once. 
They are not created again and again

they must be insitloasode once, else thehy wont be allocated memeoty L fgloabla variables these are



*/
class Logger{

    // private

    Logger() {

    }

    // delete copy 
    // logger cc= = b;
    // Logger logger(b);
    Logger(Logger &logger) = delete;

   // c = b;
   // delete this operator 
    Logger & operator = (Logger & logger) = delete; 


    public : 


    // Logger :: getInstace()
    // retunrs reference of the logger : same ibject returned : same static variable created only once : throughtout the orgram
    // can be edited for sure but not created afain and again
    static Logger & getInstance(){

    // only one single class ib the scope of the progra,
    // one object can be made for this class 
        static Logger logger; // initialosed once;
        return logger;
    }
};



/*

Observer pattern 

class Observer {
    void update(){
    }
}

class Subject{

    // send an update 

    // notify obervers : emitting chage

    void addObserver(){
    }

    void notify(){

        for(auto u : observers){
            u.update();
        }
    }
};
*/

class IObserver{

    public : 
    virtual void update(string message) = 0;  
};

class EmailSender : public IObserver{

    public :

    void update(string message ){
        cout << "EMAIL to " << message << endl;
    }
};

class SMSSender : public IObserver {
    public : 

    void update(string message) {
        cout  << 'SMS sent to' << message << endl;
    }
};

// we have a set of observers present in the meeting room service 
// these set of observers are called and given some update function 

class MeetingRoomService{

    vector<IObserver*> notifiers;
    public : 

    void addNotifiers(IObserver* observer){
        notifiers.push_back(observer);
    }

    void notify(){
        
    }
};