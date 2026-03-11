#include<bits/stdc++.h>
//#include<mutex>

using namespace std;


/*
Course

Module

Lesson


Student  -> user
Instructor

Enrollement : storing enrollment details for each student and course : 1 student maps to 1 course


Enrollment Service : 
enroll
completeLesson(lesson, enrollemnt ) : in a givwn course for a student : in one enrollment :mark the lesson completed

Sens notification too  for both these things
Stores the enrollment and stores the courses


//data for courses and enrollments are saved in memory
*/

enum class VehicleType {
    TwoWheeler, 
    FourWheeler
};

// VehicleType :: TwoWheeler
// VehicleType :: FourWheeler

//USERS CLASS

class User{
    
    public : 
    int id;
    string name;
    string email;

    //mutex mtx;//
    User(int id, string name, string email) : id(id) , name(name), email(email) {};

    int getId() const{
        return id;
    }

    string getName() const {
        return name;
    }
    
    string getEmail() const {

        // lock_gurad<mutex> lock(mtx) // lock a mutex variable
        //lock_guard<std::mutex> lock(mtx);
        return email;
    }

    virtual ~User() = default;
};

// base class : which is not absract : we have shared state here


class Student : public User {

    public :

    Student(int id, string name, string email) : User(id, name, email) {};


    // vector<Enrollment> getEnrollments(unordered_map<int, vector<Enrollment>> studentEnrollments){
        
    //     return studentEnrollments[this->getId()];
    // }
};

class Instructor: public User{

    public :

    Instructor(int id, string name, string email): User(id, name, email) {};

    // vector<Course> getCourses(){

    // }
};
class INotification{

    public : 
    virtual void send(const User &user, string message) = 0;

    virtual ~INotification() = default;
};

class EmailSender : public INotification{
    public :

    void send(const User &user, string message) override{
        cout << "Email to " << user.getName() << ": " << message << endl;
    }
};

class SMSSender : public INotification{

    public : 
    void send(const User &user, string message) override{
        cout << "SMS to " << user.getName() << ": " << message << endl;
    }
};




class Lesson{

    int id;
    string title;
    string contentUrl;
    int durationInMinutes;
\
    public :
    Lesson(int id, string title, string contentUrl, int durationInMinutes){
        this->id = id;
        this->title = title;
        this->contentUrl = contentUrl;
        this->durationInMinutes = durationInMinutes;
    }

    int getId(){
        return id;
    }
    string getTitle(){
        return title;
    }
};


class Module{
    int id;
    string title;
    


    vector<Lesson> moduleLessons;

    public: 

    Module(int id, string title) :  id(id), title(title) {}
    void addLesson(Lesson & lesson){
        moduleLessons.push_back(lesson);
    }

    // lessons for it's course
    vector<Lesson> getLessons(){
        return moduleLessons;
    }

};


//COURSE STRUCXTURE FOR US : 

// generally abailable gloablly : can be used
class Course{

    int id;
    string title;
    string description;
    vector<Module> courseModules;
    public :

    Course (int id, string title, string d) {
        this->id = id;
        this->title = title;
        description = d;
    }
    void addModule(Module & module){
        courseModules.push_back(module);
    }

    vector<Module> getModules(){

        return courseModules;
    }

    int totalLessons(){
        int cnt = 0;
        for(auto module : courseModules ){
            cnt += module.getLessons().size();
        }
        return cnt;
    }

    int getId(){
        return id;
    }
};


// class CourseRepository{
//     // map storing each course 
//     unordered_map<int,Course> courseDB;
//     // // course id, module id, lesson id
//     // unordered_map<int,Module> moduleDB;
//     // unordered_map<int,Lesson> moduleDB;
//     //unordered_map<int,unordered_map<int,int>> courseMapping;

//     Course findById(int id){
//         // if(courseDB.count(id) == 0) {
//         //     cout << "No course found for this id: " << id << "endl";
//         //     return {}; 
//         // }
//         return courseDB[id];  
//     }

//     void save(Course course){
//         int id = course.getId();
//         courseDB[id] = course;
//     }


// };

enum class EnrollmentStatus {
    ACTIVE,
    COMPLETED
};


// specofic to a given course : for the course we should have the completed percentage
// specofic to a student and for a given course and thw student's rogress in that given course for that specfic student
class Enrollment {

    int id;
    int studentId;
    int courseId;
    string enrollmentDate;
    EnrollmentStatus enrollmentStatus;
    float progressPercentage;
    int totalLessons;
    set<int> completed;

    public : 

    Enrollment(){

    }
    Enrollment(User& user, Course & course, int id, string enrollmentDate, int totalLessons){
        this->id = id;
        this->enrollmentDate = enrollmentDate;
        this->totalLessons = totalLessons;
        progressPercentage = 0;
        enrollmentStatus = EnrollmentStatus::ACTIVE;
        studentId = user.getId();
        courseId = course.getId();
    }

    // update profress percenragwe in the specofic enrollment
    void markLessonCompleted(Lesson lesson){

        int lessonId = lesson.getId();
        if(completed.count(lessonId) == 0) {
            completed.insert(lessonId);
            progressPercentage = 1.0 * (completed.size()) / totalLessons; 

            if(totalLessons == completed.size()){
                enrollmentStatus = EnrollmentStatus::COMPLETED;
            }
        }
    }

    float getProgressPercent(){
        return progressPercentage;
    }

    EnrollmentStatus getEnrollmentStatus(){
        return enrollmentStatus;
    }

    int getId(){
        return id;
    }

    int getStudentId(){
        return studentId;
    }

    int getCourseId(){
        return courseId;
    }
};


// one enrollment for a student and the class
// multiple enrollments for each studebt
// multiple enrollmenrs for each coourse
class EnrollmentRepository{

    public : 

    // creates a copy for each enrollments object and stores ib the map
    unordered_map<int, Enrollment> enrollementDB;
    // student -> enrollemnts
    // curse -> enrollemnet

    Enrollment* findByStudentAndCourse(User student, Course course){

        int studentId = student.getId();
        int courseId = course.getId();

        // if(studentEnrollments.count(studentId) == 0){
        //     cout << "No enrollement found for " << studentId << endl;
        //     return ;
        // }

        // if(courseEnrollments.count(courseId) == 0){
        //     cout << "No  enrollment in this course "<< courseId << endl;
        //     return {};
        // }

        // use by reference here
        for(auto &it : enrollementDB){
            if ( (it.second.getStudentId() == studentId)  && (it.second.getCourseId() == courseId)) {
                return &it.second;
            }
        }
        // bec there is apossibility of null

        return nullptr;

    }

    void save(Enrollment* enrollment){

        int id = enrollment->getId();

        // creates a new copy : even if you pass s by reference
        enrollementDB[id] = *enrollment;
    }

    Enrollment* findById(int enrollmentId){

        return &enrollementDB[enrollmentId];
    }

};







// main function

class EnrollmentService{

    INotification * notifier;
    EnrollmentRepository * enrollmentRepository;
    int cnt;

    public : 

    EnrollmentService(INotification* notifier, EnrollmentRepository * repo) : notifier(notifier) , enrollmentRepository(repo),  cnt(1) {};
  

    Enrollment* enroll(User &user, Course &course){

        Enrollment *existing = enrollmentRepository->findByStudentAndCourse(user, course);

        if(existing){
            return existing;
        }

        Enrollment* enrollment = new  Enrollment(user, course, cnt++, "today",course.totalLessons());

        enrollmentRepository->save(enrollment);
        notifier->send(user, "enrolled in the course ");

        return enrollment;
    }

    void completeLesson(User &user, Lesson& lesson, Enrollment* enrollment ){

        enrollment->markLessonCompleted(lesson);
        notifier->send(user, "completed the lesson" + lesson.getTitle() );

          if (enrollment->getEnrollmentStatus() == EnrollmentStatus::COMPLETED) {

            notifier->send(
                user,
                "Congratulations! Course completed!"
            );
        }

        enrollmentRepository->save(enrollment);
    }

};


int main(){


    Student student = Student(1, "bhavya", "abc@gmail.com");
    Course course = Course(1, "Maths", "number and theory");

    Module module = Module(1, "Numbers");


    Lesson lesson1 = Lesson(1, "chapter1", "xyzajnff", 12);
    Lesson lesson2 = Lesson(2, "Chapter2" , "sdcnsjkvnfe", 15);

    module.addLesson(lesson1);
    module.addLesson(lesson2);

    course.addModule(module);


    EmailSender *emailSender = new EmailSender();

    EnrollmentRepository* enrollmentRepository = new EnrollmentRepository();

    EnrollmentService enrollmentService  = EnrollmentService(emailSender, enrollmentRepository);

    Enrollment* enrollment = enrollmentService.enroll(student, course);
    
    enrollmentService.completeLesson(student, lesson1, enrollment);

    enrollment->getProgressPercent();

    enrollmentService.completeLesson(student, lesson2, enrollment);

    enrollment->getEnrollmentStatus();




    return 0;
}