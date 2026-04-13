#include<bits/stdc++.h>
using namespace std;


class User{

    private :

    //manadatory
    string name;
    string id;

    // optional properties
    string email;
    string phone;

    public :

    User(string name, string id, string email, string phone) : name(name) , id(id) , email(email), phone(phone) {};


    class Builder{

        private :
        string _name;
        string _id;

        string _email;
        string _phone;

        public :

        // a constructor is called when an object is created . When we want to create an object of some given class, we call the constructor by default it gets called.

        Builder(string name, string id) : _name(name), _id(id) {};

        Builder & setEmail(string email ){
            _email = email;
            return *this; 
            // reference or address to the current object of class Builder 
        }

        Builder & setPhone(string phone){
            _phone = phone;
            return *this;
        }

        User build(){

            // call the contructir
            return User(_name, _id, _email, _phone);
        }
    };

};


int main(){


    User u = User :: Builder("Bhavya" , "123") // this is creating an object of class Buulder temporiyl
                     .setEmail("abc@gmailc.om")
                     .setPhone("956-7-65")
                     .build();
}