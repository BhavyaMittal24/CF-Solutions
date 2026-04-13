/*
WHAT I LEARNT HERE FROM THIS CODE?

PAYMENT GATEWAY -> TAKES AWAY WHEN THE BOOKING IS GENERATED AND MAKES THE USER PAY FROM ONE OF THE PAYMENT STRATEGIES AND RETURNS A SUCCESSFULL PAYMEMT ID ON PAYMENT BEING DONE

IT WILL THEN CALL A COMPLETEPAYMENTMETHOD(BOOKING ID, PAYMENT ID) TO USE : THIS WILL BASICALLY MARK THE SHOWSEATS AS BOOKED AND ALSO THE BOOKING AS BOOKED

PAYMENTSTRATEGY : USE STRATEGY PATTRN HERE FOR VARIOUS PATMENT THAT WILL in the end return us with a payment Id upon completetion


we use a lease base format for storing if the showSeat is avaiable or not. The showSeat is very useful as it is a virtual representtion for the given show_id and the
actaula seat_id. Once the showSeat is locked, it automatically gets free on the expiration time, and when someone else i viewing it get free then as well.

The time format here is basically, about 5 mins :  i can add to wait for the lock to expire




throw runtime_error("This is invalid, please take care...")

CRUD are handled by a ticketRepository

BMS system


1. clarify and scope
Type : movies
Mulitplicity : City Theatre, Screen, Seat
Concurrency

2. Key APIs and Core functionalities

a. list all movies in a given city

b. all shows for a given movie and given city

c. booking a given show for a movie in a given city.

d. cancel a booking

e. getSeatLayout in a given show


3. Entity relationships and data model. We want to fogure out how the data persists and how we create the dbs and foreign keys

City
-id

Movie
-movie_id
-name

Theatre
- theatre_id,
-city_id : as fk : so unique records are based on both theatre_id and city_id
- name

Screen
-screen_id
-theatre_id
- int totalSeats

less significance :
Seat
seatId
screenId
theatreId


// show is for a given movie in a theatre in a given screen
Show
id : unique
movie_id
Screen_id
price
start_time

ShowSeat

-seat_id
-show_id
-status : enum FREE/LOCKED/inprogress
-lock_expiryTime : a time period i am putting here till it can be blocked

Booking
-id
-show_id
-vector<int> showSeatIds
-amount
-paymentStatus



*/

// keep these screenId, theatreId, movieId all unquue lways as primary keys

#include<bits/stdc++.h>
using namespace std;


class City{

};

class Theatre {
    int theatre_id;
    int city_id;
};

class Movie{
    int movie_id;
    int duration;
    string name;
};



class Show{

    int show_id;
    int movie_id;
    int screen_id;
};

class Seat{
    int id;
    int screen_id;
    int row_num;
    int col_num;
};


// Status for a given shows seat
// the seat for a show can be locked, free or booked
enum class SeatStatus {
    FREE,
    LOCKED,
    BOOKED
};

class ShowSeat {

    int id;
    int show_id;
    SeatStatus status;
    int seat_id;
    // time till which the show seat will stay locked in my scope
    int lock_expiryTime;

};

enum class BookingStatus {
    PENDING,
    CONFIRMED,
    FAILED
};

enum class PaymentStatus {
    PENDING, 
    CONFIRMED,
    FAILED
};

class Booking{
    int id;
    int show_id;
    int price;
    int expiry;
    vector<int> showSeatIds;
};

// different tyoes of repositories we have and we will be usig 

class MovieRepository {
    // returns all shows for a given movie
};

class TheatreRepository {
    // returns the theatres, screens, city etc
};


class SeatInfo {
    int seatId;
    SeatStatus status; // infor 
};


// multiple payment for the same booking. finally one succeeds/
class Payment {
    int paymentId;
    PaymentStatus status;
    int bookingId;

};

class PaymentService{

    public :

    // redirects and uses payment method to make payment from the amount and see then, return some payment Id
    string makePayment(double amount, PaymentStrategy* paymentStrategy){

        string paymentId = paymentStrategy->collectPaymentMethodAndProcess(amount);

        return paymentId;
    }
};

class PaymentStrategy {

    // the payment gateway basocally goes from frontend, when the bookingId is created : status is set to pending for booking and all showSeats are LOCKED
    // the payment gateay redurects and ask you to majke payment by some payment strategy and then returns some paymentId

    public : 
    virtual string collectPaymentMethodAndProcess(double amount) = 0;
};

class CardPayment : public PaymentStrategy {

    public :

    string collectPaymentMethodAndProcess(double amount) override {

        // 
        cout << "Paid" << endl;
        return "card1234";
    }
};

class ShowRepository {

    
};

class MovieBookingService {

    public : 


    // lst all the movies for a given data and city

    // show me all movis for this date ad in this city
    vector<Movie> listAllMovies(int date, int city_id) {

    }

    // give show details for a given movie in a city on a  date and for  given movie

    // a map based on which theatre and which show in the city : makes more sense
    //<theatreId, Show>
    map<int,Show> listAllShowsForMovie(int city_id, int date, int movie_id){

    }


    // show is selected

    // vector<SeatInfo> : seatid, and showSeat status
    vector<pair<int,SeatStatus>> getSeatLayout(int show_id) {
        // frpm the show_id, i can get details for everything from screen_id and movie_id and from screen_id i can then know the showSeats: total seats availbe fro th given sow+od
    }


    // creating a booking / parking a vehicle when there is some payment gateway involved or you want to get a tocket
    // park and unpark : use the same id cancel and uncance:

    string createBooking(int show_id, vector<int> seat_ids){


        // poat payment generae a ticket Id and update in the DB fro TicketRepository and return back the ticketId


        // get seat status for this show_id

        map<int, ShowSeat> seatInfo = ShowRepository.find_showSeatLayoutForShowId(show_id);

        // check if all the seats are available
        // USE A MUTEX FOR EACH SHOW : SEATS ARW SHOW SEATS BTW

        // NOW go to eeach seat _id
        
        int currentTime = now;
        for( auto seat_id : seat_ids){

            // get the status for each seat_id usng the seatstatis
            if(seatInfo[seat_id].status == SeatStatus::BOOKED){
                __throw_runtime_error("Seat is booked");
            }

            else if(seatInfo[seat_id].status == SeatStatus::LOCKED && seatInfo[seat_id].lock_expiryTime > currentTime){
                __throw_runtime_error("Seat is loked");
            }
        }

        int newExpiry = currentTIme + lock_duration

        // npw try locking seats


        // create a new vector for showSeats and then update in the db



        // post locking, 
        // create a booking

        int amt  = 0;
        // amount can be also calculated by some pricig strategy
        Booking newBooking = BookingRepository.createNew(show_id, seat_ids, amount, BookingStatus::);

        // make payment : now

        return newBooking.getId();
    }

    string cancelBooking(string booking_id){

    }

    Booking completePayment(int bookingId, int paymentId){

        // go through the selected seat ids, 
        // mark the showSeatStatus for each seat as Booked once the payment is dine

        // verified that payment is done

        vector<ShowSeat> selectedShowSeats = BookingRepo.findSelectedSHowSeats(bookingId);

        vector<int> seatIds;
        for(auto seat : selectedShowSeats){
            // mark the status as complete

        }

        ShowRepository.updateStartus(seatIds, SeatStatus::BOOKED);

        Booking.Repository.updateBooking()


    }


};