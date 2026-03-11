#include<bits/stdc++.h>
using namespace std;

// Design a meeting scheduler

/*
n given meetings rooms
book a meeting room for the current day in a given meetng room with capacity, start and end time
Send notif to all people present in the meeting 
meeting room calender to track meeting's date and time


step1 ; clarofying questions : rooms have some type as well? or all are same : ? med / small. large ? 
// allocation of rooms is also difficut : logig be? to be based on capacity? availability : time 
// is it also based on prestoge seniority? of someone NO
// concurrency

Maintain a per room calender to track all the that days meetings with time


core apis 

// meetings will b e recurring or not?
// room allocated based on senioroity? 
// meeting room calender only for the current day?
// 

MeetingRoomService{

public : 

Meeting* bookMeetingRoom(int start, int end, int capacity)
// find room/
// book meeting
// send notif to all the invitees


findAvailableRoom(start, end ,capacity)
// find room based on capacity

cancelBooking(meeting_id)
// free up the room
// 
}

vector<MeetingSummary> showCalender(MeetingRoom id)

};

FIRST 10-15 MINUTES

User
-name
-email
`id


Meeting
-id
-meeting_room_id
-startTime
-endTime
-reciepeients vector<User*>
-capacity


MeetingRoom
-id
-maxCapacity
- isAvailable

Attendee
-userid
-meeting_id


DB based stuff : Controller, Service, Repository 
MeetingRepository
UserRepository


*/


class User{

};

class Meeting{
    int id;
    int room_id;
    string title;
    int starttime;
    int endtime;
    int capacity;
    vector<int> invites; // list of ids for all users invited to the meeting 

    public : 
    int getStartTime(){
        return starttime;
    }

    int getEndTime(){
        return endtime;
    }
};

// either creae a class CaldnerService storign the meetings for each fixed room id
// roomid-> meetings : 

class Room {
    int id;
    int maxCapacity;

    // for a room store the 
    public : 

    int getId(){
        return id;
    }

    int getMaxCapacity(){
        return maxCapacity;
    }
};


struct MeetingSummary {
    int id;
    int startTime;
    int endTime; 
};

// Core APIS : inputs and parameters : Key APIs
// exposes the main routes : inout outpir hadles from here: not from anywhere else : 

//

class INotifier{

    public : 
    virtual void send(vector<string>& emails) = 0;
    virtual ~INotifier() = default;
};

class OutlookSender : public INotifier {
    
    public : 
    void send(vector<string> & emails) override {

    }
    
};


class MeetingRepository{

    public :

    Meeting* createMeeting(int capacity, int starttime, int endtime, int room_id, vector<int>& invitees ){

        // save to db : 
        
    }

    Meeting * findMeetingById(int meeting_id){

    }

};

class UserRepository{

    public :

    vector<string> getEmailsForIds(vector<int> & invitees){

    }
};

class RoomRepository{

    public : 

    vector<Room*> getAllRooms(){

    }
};

// responisble for telling me which room is available in the time slot or not ;
// storign all the slots for a room for meeting for that day
// logicm for timeb ased selection is handled here : whch room is 
// id -> slots it is taken 


//  A SINGLKE INSTANCE OF EACH OF THESE SERVICEW MUST BE RUNNING : YOU MAY EVEN USE SONGLETON PATTWRN FOR THME
class CalenderService{
    
    unordered_map<int, vector<Meeting*>> roomSchedule;

    public : 

    bool isRoomFree(int room_id, int start, int end){

        vector<Meeting*> meetings = roomSchedule[room_id];

        for(auto meeting : meetings){
            // if interesction retirn false
            
            if( start > meeting->getEndTime() || end < meeting->getStartTime()) {
                return false;
            }
        }
        return true;

    }

    void addMeetingToCalender(int room_id, Meeting* meeting){

        roomSchedule[room_id].push_back(meeting);
    }

    vector<Meeting*> showCalender(int room_id){
        return roomSchedule[room_id];
    } 

    void cancelMeeting(int room_id, Meeting * meeting){
        // vector<Meeting*> meetings = roomSchedule[room_id];
        // meetings.remove(meetings.begin(), meetings.end(), meeting);

        vector<Meeting*>& meetings = roomSchedule[room_id];

    // 2. Use the Erase-Remove Idiom
    meetings.erase(
        std::remove(meetings.begin(), meetings.end(), meeting), 
        meetings.end()
    );
    }   

};

class MeetingSchedulerService {

    // use an interface class ideally
    // can also use a pointer too
    // MeetingReposoty * pointer : all the poiters are pointing to the same objedct in the heap meoery in c++

    CalenderService & calenderService;
    MeetingRepository & meetingRepository;

    RoomRepository & roomRepository;
    UserRepository & userRepository;
    // either as a pointer or as a reference, because you can;t have an instance of the abstract class
    INotifier & notifier;
    // implementing strategy pattrn

    public : 

    MeetingSchedulerService(MeetingRepository & meetingRepository, INotifier & notifier, UserRepository & userRepository, RoomRepository & roomRepository, CalenderService & calenderService) : meetingRepository(meetingRepository) , notifier(notifier) , userRepository(userRepository), roomRepository(roomRepository), calenderService(calenderService){};
    // book a meeting
    Meeting * bookMeetingRoom(int capacity, int start, int end, vector<int> invitees){

        // find an available room

        Room* availableRoom = findAvailableRoom(capacity, start, end);

        if(availableRoom == nullptr){
            throw runtime_error("No room availabe for the desired meeting. Please select a different time slot or reduce capacity!");
        }

        // we have a meeting room
        
        // create a new meeting and save it in the db : like we did for ticket or we did for booking?
        // meetig created and saved to DB
        Meeting* newMeeting = meetingRepository.createMeeting(capacity, start, end, availableRoom->getId(),  invitees);

        calenderService.addMeetingToCalender(availableRoom->getId(), newMeeting);

        // roll out an invite to all the attendees : 
        

        // comversiom logoc for getting all emails

        // get a bulk api for getting all emails for all user _ids

        vector<string> emails = userRepository.getEmailsForIds(invitees);

        notifier.send(emails);
    }

    // base don capacoty
    Room* findAvailableRoom(int capacity, int start, int end){

        // strategu to be able to find the best room
        // first choose strategy

        // handle complex code in the service apis : 
        vector<Room*> rooms = roomRepository.getAllRooms();

        // from the set of rooms, determine the ideal one 

        Room* selectedRoom = nullptr;

        vector<int> possibleRooms;
        for(auto room : rooms){

            if(calenderService.isRoomFree(room->getId(), start, end)){

                // use a strategy : 
                possibleRooms.push_back(room->getId());
            }
        }

        // use a pattern here

    }

    vector<Meeting*> showRoomCalender(int room_id){

        return calenderService.showCalender(room_id);
    }

    void cancelMeeting(int room_id, int meeting_id){

        Meeting * meeting = meetingRepository.findMeetingById(meeting_id);
        calenderService.cancelMeeting(room_id, meeting);
    }
    
};


/*
Design Patterns to use for our case : 

Strategy/ Factory
for finding the room : ?

// based on the max capacity : 

// Based on special rooms : something like that : 


For sending notification : 
*/

/*

DB level stuff : 

Use a repository for stuff : 

// Well known to be used for accessng memery and we have written APIS for this
MeetingRepository
UserRepositoy 
RoomRepository
*/
