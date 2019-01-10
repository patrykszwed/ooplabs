#include <iostream>

using namespace std;

struct yearException : public exception{
    const char * what() const throw(){
        return "Invalid year!";
    }
};

struct nameException : public exception{
    const char * what() const throw(){
        return "Invalid first name or last name!";
    }
};

class Student{
private:
    string firstName;
    string familyName;
    long studentId;
    int yearOfStudy;

public:
    Student(const string &firstName, const string &familyName, long studentId, int yearOfStudy) : firstName(firstName),
                                                                                                  familyName(
                                                                                                          familyName),
                                                                                                  studentId(studentId),
                                                                                                  yearOfStudy(

                                                                                                          yearOfStudy) {

    }

    Student() {}

    const string &getFirstName() const {
        return firstName;
    }

    void setFirstName(const string &firstName) {
        Student::firstName = firstName;
    }

    const string &getFamilyName() const {
        return familyName;
    }

    void setFamilyName(const string &familyName) {
        Student::familyName = familyName;
    }

    long getStudentId() const {
        return studentId;
    }

    void setStudentId(long studentId) {
        Student::studentId = studentId;
    }

    int getYearOfStudy() const {
        return yearOfStudy;
    }

    void setYearOfStudy(int yearOfStudy) {
        Student::yearOfStudy = yearOfStudy;
    }

    void toString(){
        cout << "=========== Student's data ===========\n";
        cout << "ID: " << this->studentId << endl;
        cout << "First name: " << this->firstName << endl;
        cout << "Family name: " << this->familyName << endl;
        cout << "Year of study: " << this->yearOfStudy << endl;
    }

};

int isValidName(string input){
    for (char i : input)
        if (!isalpha(i))
            return 0;

    return 1;
}

int main() {
    int year;
    long id = 0;
    string string1;

    Student *student = new Student();

    cout << "Give first name:";
    try {
        cin >> string1;
        if(!isValidName(string1))
            throw nameException();
    }catch(nameException &exception1){
        cout << exception1.what() << endl;
        return 0;
    }

    student->setFirstName(string1);

    cout << "Give family name:";
    try {
        cin >> string1;
        if(!isValidName(string1))
            throw nameException();
    }catch(nameException &exception1){
        cout << exception1.what() << endl;
        return 0;
    }

    student->setFamilyName(string1);

    cout << "Give year of study:";
    try {
        cin >> year;
        if(!cin >> year)
            throw yearException();
    }catch(yearException &exception1){
        cout << exception1.what() << endl;
        return 0;
    }

    student->setYearOfStudy(year);
    student->setStudentId(id++);

    student->toString();

    return 0;
}