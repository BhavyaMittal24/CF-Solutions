#include<bits/stdc++.h>
using namespace std;

/*
Request  object 

userId, message, channels, priority
// send the messages on all the channels via some API


NotificationService 
1.handles all these request and sends to all the channels based on priority
2. send to all channels
3. if the request fails to be sent, i can retry upto three times 

*/


// create new objects based on a pattern : example : various type : condition, based on this condition you can go ahead and create a new object

class IChannel {

    public : 
    virtual void send(string msg, string userId) = 0;
};

class SMSChannel : public IChannel{

    public : 
    void send(string msg, string userId) {
        cout << "Sending SMS to " << endl;
    }
};

class EmailChannel : public IChannel{
    public : 
    void send(string msg, string userId) {
        cout << "Sending SMS to " << endl;
    }
};


class ChannelFactory{
    
    public : 

    IChannel * createChannel( string channel){

        if(channel == "SMS") {
            return new SMSChannel();
        }   
        else {
            return new EmailChannel();
        }
    }
};

class Request {
    string msg;
    int id;
    int priority;
    vector<string> channels;

    public : 

    int getId(){
        return id;
    }

    void execute(){

        for(int i = 0; i < channels.size(); i ++){

        }
    }
};


class RequestRepo{

    public :

    Request createRequest(string msg, int priority, vector<string> channels){
        // save to db
        // return a request
    }


    
};


class NotificationSvc{


    RequestRepo & requestRepo;

    // set storign the reqqyests
    // use queue or whateveryou want . you can sort them based on priority
    set<Request*> activeRequests;
    unordered_map<int,Request*> requestToId;

    public :


    void sendRequest(string msg, vector<string> channels, int priority){

        // create a new reuqest

        Request newRequest = requestRepo.createRequest(msg, priority, channels);

        // canc check if the id is same or not , then an idempotent call.

        int reqId = newRequest.getId();
        
        requestToId[reqId] = &newRequest;

        activeRequests.insert(&newRequest);

    }

    void deleteRequest(int id){

    }


};


