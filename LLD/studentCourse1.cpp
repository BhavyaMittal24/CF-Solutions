#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

/* =========================
   USER HIERARCHY
   ========================= */

class User {
protected:
    int id;
    string name;
    string email;

public:
    User(int id, string name, string email)
        : id(id), name(name), email(email) {}

    int getId() const { return id; }
    string getName() const { return name; }
    string getEmail() const { return email; }

    virtual ~User() = default;
};

class Student : public User {
public:
    Student(int id, string name, string email)
        : User(id, name, email) {}
};

class Instructor : public User {
public:
    Instructor(int id, string name, string email)
        : User(id, name, email) {}
};


/* =========================
   COURSE STRUCTURE
   ========================= */

class Lesson {
    int id;
    string title;

public:
    Lesson(int id, string title) : id(id), title(title) {}

    int getId() const { return id; }
    string getTitle() const { return title; }
};

class Module {
    int id;
    string title;
    vector<Lesson> lessons;

public:
    Module(int id, string title) : id(id), title(title) {}

    void addLesson(const Lesson &lesson) {
        lessons.push_back(lesson);
    }

    const vector<Lesson>& getLessons() const {
        return lessons;
    }
};

class Course {
    int id;
    string title;
    vector<Module> modules;

public:
    Course(int id, string title) : id(id), title(title) {}

    int getId() const { return id; }

    void addModule(const Module &module) {
        modules.push_back(module);
    }

    const vector<Module>& getModules() const {
        return modules;
    }

    int totalLessons() const {
        int count = 0;
        for (const auto &m : modules) {
            count += m.getLessons().size();
        }
        return count;
    }
};


/* =========================
   ENROLLMENT
   ========================= */

enum class EnrollmentStatus {
    ACTIVE,
    COMPLETED
};

class Enrollment {

    int id;
    int studentId;
    int courseId;

    EnrollmentStatus status;
    set<int> completedLessons;

    int totalLessons;

public:

    Enrollment(int id, int studentId, int courseId, int totalLessons)
        : id(id),
          studentId(studentId),
          courseId(courseId),
          status(EnrollmentStatus::ACTIVE),
          totalLessons(totalLessons) {}

    int getId() const { return id; }

    int getStudentId() const { return studentId; }

    int getCourseId() const { return courseId; }

    void completeLesson(int lessonId) {
        completedLessons.insert(lessonId);

        if (completedLessons.size() == totalLessons) {
            status = EnrollmentStatus::COMPLETED;
        }
    }

    float getProgress() const {
        if (totalLessons == 0) return 0;
        return (float)completedLessons.size() / totalLessons * 100;
    }

    EnrollmentStatus getStatus() const {
        return status;
    }
};


/* =========================
   NOTIFICATION
   ========================= */

class INotificationChannel {
public:
    virtual void send(const User &user, const string &message) = 0;
    virtual ~INotificationChannel() = default;
};

class EmailNotificationChannel : public INotificationChannel {

public:
    void send(const User &user, const string &message) override {
        cout << "Email to " << user.getEmail()
             << ": " << message << endl;
    }
};

class SmsNotificationChannel : public INotificationChannel {

public:
    void send(const User &user, const string &message) override {
        cout << "SMS to " << user.getName()
             << ": " << message << endl;
    }
};


/* =========================
   REPOSITORIES
   ========================= */

class ICourseRepository {
public:
    virtual void save(const Course &course) = 0;
    virtual Course* findById(int id) = 0;
    virtual ~ICourseRepository() = default;
};

class IEnrollmentRepository {
public:
    virtual void save(const Enrollment &enrollment) = 0;
    virtual Enrollment* findByStudentAndCourse(int studentId, int courseId) = 0;
    virtual Enrollment* findById(int id) = 0;
    virtual ~IEnrollmentRepository() = default;
};


/* =========================
   IN-MEMORY IMPLEMENTATIONS
   ========================= */

class InMemoryCourseRepository : public ICourseRepository {

    unordered_map<int, Course> courses;

public:
    void save(const Course &course) override {
        courses[course.getId()] = course;
    }

    Course* findById(int id) override {
        if (courses.count(id))
            return &courses[id];
        return nullptr;
    }
};

class InMemoryEnrollmentRepository : public IEnrollmentRepository {

    unordered_map<int, Enrollment> enrollments;

public:
    void save(const Enrollment &enrollment) override {
        enrollments[enrollment.getId()] = enrollment;
    }

    Enrollment* findById(int id) override {
        if (enrollments.count(id))
            return &enrollments[id];
        return nullptr;
    }

    Enrollment* findByStudentAndCourse(int studentId, int courseId) override {

        for (auto &pair : enrollments) {

            if (pair.second.getStudentId() == studentId &&
                pair.second.getCourseId() == courseId) {

                return &pair.second;
            }
        }

        return nullptr;
    }
};


/* =========================
   SERVICE LAYER
   ========================= */

class EnrollmentService {

    IEnrollmentRepository *enrollmentRepo;
    INotificationChannel *notifier;

    int nextId = 1;

public:

    EnrollmentService(IEnrollmentRepository *repo,
                      INotificationChannel *notifier)
        : enrollmentRepo(repo), notifier(notifier) {}

    Enrollment enroll(const Student &student, const Course &course) {

        Enrollment *existing =
            enrollmentRepo->findByStudentAndCourse(
                student.getId(), course.getId());

        if (existing)
            return *existing;

        Enrollment enrollment(
            nextId++,
            student.getId(),
            course.getId(),
            course.totalLessons()
        );

        enrollmentRepo->save(enrollment);

        notifier->send(
            student,
            "You have been enrolled in course!"
        );

        return enrollment;
    }

    void completeLesson(Student &student,
                        Enrollment &enrollment,
                        const Lesson &lesson) {

        enrollment.completeLesson(lesson.getId());

        notifier->send(
            student,
            "Completed lesson: " + lesson.getTitle()
        );

        if (enrollment.getStatus() == EnrollmentStatus::COMPLETED) {

            notifier->send(
                student,
                "Congratulations! Course completed!"
            );
        }

        enrollmentRepo->save(enrollment);
    }
};


/* =========================
   DEMO / MAIN
   ========================= */

int main() {

    Instructor instructor(1, "Dr. Smith", "smith@lms.com");

    Course course(1, "C++ Fundamentals");

    Module module1(1, "Basics");

    Lesson l1(1, "Variables");
    Lesson l2(2, "Loops");

    module1.addLesson(l1);
    module1.addLesson(l2);

    course.addModule(module1);


    Student student(101, "Alice", "alice@mail.com");


    InMemoryCourseRepository courseRepo;
    InMemoryEnrollmentRepository enrollmentRepo;

    EmailNotificationChannel emailNotifier;

    EnrollmentService service(
        &enrollmentRepo,
        &emailNotifier
    );


    courseRepo.save(course);


    Enrollment enrollment =
        service.enroll(student, course);


    service.completeLesson(student, enrollment, l1);
    service.completeLesson(student, enrollment, l2);


    cout << "\nFinal Progress: "
         << enrollment.getProgress()
         << "%" << endl;

    cout << "Status: "
         << (enrollment.getStatus() ==
             EnrollmentStatus::COMPLETED
             ? "COMPLETED"
             : "ACTIVE")
         << endl;

}