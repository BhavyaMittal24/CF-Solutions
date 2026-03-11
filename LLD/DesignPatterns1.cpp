#include<bits/stdc++.h>
using namespace std;

// object oriented programming : use classes as weappers for a given function
/*
UML Diagrams : 
Association : is related to : class1 is related to class 2 : simple arrow
Aggregation : has / made up of : a team is made up of employees : open diamond : book and bookmark 
Composition : closed diamond : composed of/ consists of/ cant live wouth other : order : and address , book and pages
Inheritance : open arrow : when we do it from an abstract class/ interface ; we use a dotted arrow : Manager IS a kind of employee as well
- private data member or member function
+ public data member or memeber function

// SRP is necessary : Each class should be able to solve only one problem. Each class should have a single responsibility
// decide the use for each function and have a class for each function or role/

// We can use Dependency injection and make use of the object of a given interface onyl when two classes have some common function 
// SHARE BEHAVIOUR AGGRESIVELY
DONT SHARE COMMON STATE
// USe classes to have behaviour if you want in the main service


SRP is not having a single function, but rather to have one objective per class. Basically, each class should have only one objective.
An AudioController will have play(), record(), download(), etc functions. But they are all related to one scope right/

A videoCameraStreaer will hav e play(), liveStream(), record() and more functions

Add interface, if there can be more classes having the same behaviour : eg
// SMSSender, emailSender : ISend class or INotifier class


10 types of commin things

Service
Calculoator
Render : object gets converted into a string
Parser : string -> extract some information
Validator : Class RegistrationValidator : string validatie(Regex & form, )

Adaptor : used to cinvert the input of a new api/ method to an method/ interface

Factory : create ibjects od similar type : implementing similar methods/ based out of a common interface with type handled there : Eliinaee IF elese


*/


int main(){


    return 0;
}