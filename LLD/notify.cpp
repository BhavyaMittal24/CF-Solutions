// 03-notify-dip-ocp.cpp


#include<bits/stdc++.h>
// Low level design using SOLID principles

/*
SOLID

SRP : Single responsibility principle : When too many fn are there in the same class : controller, db and service logic together
OCP : Open for extension, closed for modification : When if else logic : 
LSP : Liskov Substituiton principle : Forced overloads and interfaces : the class objects can be replaced without any effect
ISP : Interface segregation principle  :  Basic interfaces : when a derived class is forced to implement something from an inherited class, it is not supposed to inherit
DIP : Dependency Inversion principle :  concrete class objects used inside:  objects as interfaces should be passed in params
*/

using namespace std;

struct User { 
    string email; 
    string phone; 
};

class INotifier{
    public :

    // even the defn while overriding should match 
    // this should be discoverable : put under private : gives compile time error 
    virtual void send(const User &u) = 0;
};

// public is access specifier

class SmtpMailer : public INotifier{

    string templ;
    string body;

public:

    SmtpMailer(const string templ, const string body) : templ(templ) , body(body) {};

    // by using the word : override : you are mentiooning runtime - dispath : during execution override this with the derived class member function
    void send(const User &u)  override {

        if( u.email == "") {
            cout << "No email found " << endl;
            return;
        }
        cout << "[SMTP] template=" << templ << " to=" << u.email << " body=" << body << "\n";
    }
};

// the both implement a send / notfy fnction
class TwilioClient : public INotifier {

    string code;

public:

    TwilioClient( string code) : code(code) {};

    void send(const User &u) override {

        if( u.phone == "") {
            cout << "No phone number foubd" << endl;
            return;
        }
        cout << "[Twilio] OTP " << code << " -> " << u.phone << "\n";
    }
};



class IPostSignUp{

    public : 
    virtual void execute(User &u) = 0;
};

// set of all notiifers needed 
class NotificationService : public IPostSignUp {

    // what all notiifers I need

    vector<INotifier*> notifiers;
    public : 

    NotificationService( vector<INotifier*> notifiers) : notifiers(notifiers) {};

    // pass in the function
    void execute (User & u) override {
        for(auto notifier : notifiers){
            notifier->send(u);
        }
    }
};

// not following -> LSP, DIP, 
class SignUpService {

    IPostSignUp* postSignUpAction;
public:

    // signuo serivce should tell that one is created : the DIP : interfaces are sent in the ocnstructor : behaviour decided

    // cpmstructor to deal with what happens when we sing up

    // bool signuo{
    //}

    SignUpService(IPostSignUp * postSignUp){
        postSignUpAction = postSignUp;

    }

    void executeAction(User & u){
        postSignUpAction->execute(u);
    }    

// object is used an interface and that is basic and passed as a parameter
// class only for singing up and storing user details and then doing post sign up operations
    // bool signUp(const User& u){

    //     // if (u.email.empty()) return false; : LSP : not followed : what if just want to send message : that eill also fail then
    //     // pretend DB save here…

    //     // hard-coded providers : DIP : concrete classes used up : wrong we should use interfaces : base classes
    //     // 
    //     // SmtpMailer mailer;
    //     // mailer.send("welcome", u.email, "Welcome!");

    //     // TwilioClient sms;
    //     // sms.sendOTP(u.phone, "123456");
      
        
    //     return true;
    // }
};

int main() 
{
    // create object for each signup service alog with that create notifiers respectively to be used and passed in the signup sevice class
    
    User user =  {"user@example.com", "+15550001111"};


    INotifier* mailer = new SmtpMailer("hello" , "how are you man");
    INotifier* smsSender = new TwilioClient("1234");

    vector<INotifier*> notifiers = {mailer, smsSender};


    IPostSignUp * postSignupActions = new NotificationService(notifiers);

    SignUpService svc(postSignupActions);

    svc.executeAction(user);
    return 0;
}