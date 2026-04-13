#include<bits/stdc++.h>
#include <memory>
using namespace std;


/*
Creational patterns

How are objects/ class4s created

Factory , 
Abstract factory - range of objects/classes based on a given them DarkThemeFactory, LightThemeFactory , button -> LightThemeButton, DarkThemeButton, 
Builder : to avoid constructor telespoing : 
Singleton : We need only one instance of the object in the entire program throughout

Structural patterns

How the objects/classes are composed and made up and wired together

Adaptor, Decorator

Behavioural patterns

How objects/classes interact

Strategy 
Observer : a change in the sbuject and all need to take that change and update

Subject :

// vector of pointer storing Observer object 
vector<Observer> observers;

void notify(news){

    for(auto observer : observers ){
        observer.update(news);
    }
}


*/


class INotifier{

    public : 

    virtual void sendMessage(string message) = 0;

    virtual ~INotifier() = default;
};


class EmailSender : public INotifier{

    public :

    void sendMessage(string message ){
        cout << "Email to : " << message << endl;
    }
};


class SMSSender : public INotifier{

    public : 

    void sendMessage(string message ){
        cout << "SMS send to " << message << endl;
    }
};

enum class Notifier{
    SMS,
    EMAIL
};

class NotifierFactory {

    public : 
    
    static std::unique_ptr<INotifier> createNotifier(Notifier notifier){

        if(notifier == Notifier::EMAIL){
            return std::make_unique<EmailSender>();
        }   

        else if(notifier == Notifier::SMS){
            return make_unique<SMSSender>();
        }

        return nullptr;
    }

};


int main(){


    std::unique_ptr<INotifier> ptr = NotifierFactory::createNotifier(Notifier::EMAIL);
    ptr->sendMessage("Bhavya Mittal, Email sent");


    // not named hence can be moved to another unique_ptr
    // the old emailsender is now deleted
    ptr = NotifierFactory::createNotifier(Notifier::SMS);

    ptr->sendMessage("Bhavya Mittal, messagr senf via SMS");

    return 0;
}