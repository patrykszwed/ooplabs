#include <iostream>
#include <cmath>

using namespace std;

const int monthDays[12] = {31, 28, 31, 30, 31, 30,
                          31, 31, 30, 31, 30, 31};

class Date{

private:
    int day;
    int month;
    int year;
    int diff;

public:
    Date(int day, int month, int year) : day(day), month(month), year(year) {}

    int calculateHours(Date date) {
        return this->getDiff() * 24;
    }

    int calculateDays(Date date) {
        return this->getDiff();
    }

    int calculateMonths(Date date) {
        return abs((this->getYear() - date.getYear()) * 12 + this->getMonth() - date.getMonth());
    }

    int calculateYears() {
        return (this->getDiff() / 365);
    }

    int calculateLeapYears(Date date){
        int years = date.getYear();

        // Check if current year has to be checked for
        // being leap year
        if(date.getMonth() <= 2)
           years--;

        // Year is a leap year if it is a multiple of 4,
        // multiple of 400 and is not a multiple of 100
        return years / 4 - years / 100 + years / 400;
    }

    void calculateDiff(Date date) {
        // Count total number of days before first date

        long int n1 = this->getYear() * 365 + this->getDay();

        // Add days for months in given date
        for(int i = 0; i < this->getMonth() - 1; ++i)
            n1 += monthDays[i];

        // Since every leap year has 366 days,
        // Add a day for every leap year
        n1 += calculateLeapYears(*this);

        // Now count total number of days before second date

        long int n2 = date.getYear() * 365 + date.getDay();

        for(int i = 0; i < date.getMonth() - 1; ++i)
            n2 += monthDays[i];

        n2 += calculateLeapYears(date);

        // difference between two dates(in days)
        int diff = abs(n2 - n1);

        this->setDiff(diff);
        date.setDiff(diff);
    }

    void setDiff(int diff) {
        Date::diff = diff;
    }

    int getDay() const {
        return day;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }

    int getDiff() const {
        return diff;
    }

    void toString() {
        cout << "day: " << this->getDay() << " month: " << this->getMonth() << " year: " << this->getYear() <<
             endl;
    }
};

int main() {
    Date date1(10, 9, 1998);
    Date date2(15, 2, 2015);

    cout << "\nDate1: ";
    date1.toString();
    cout << "Date2: ";
    date2.toString();

    date1.calculateDiff(date2);

    cout << "\nDifference in years: " << date1.calculateYears() << endl;
    cout << "Difference in months: " << date1.calculateMonths(date2) << endl;
    cout << "Difference in days: " << date1.calculateDays(date2) << endl;
    cout << "Difference in hours: " << date1.calculateHours(date2) << endl;

    return 0;
}