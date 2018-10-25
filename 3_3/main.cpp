#include <iostream>

using namespace std;

class Time{
private:
    int sec;
    int min;
    int hour;

public:
    Time(int hour, int min, int sec) : sec(sec), min(min), hour(hour) {
    }

    Time(){

    }

    // Overload + operator
    Time operator+(const Time &second){
        Time result;

        result.setSec(this->getSec() + second.getSec());
        result.setMin(result.getSec() / 60);
        result.setSec(result.getSec() % 60);
        result.setMin(result.getMin() + this->getMin() + second.getMin());
        result.setHour(result.getMin() / 60);
        result.setMin(result.getMin() % 60);
        result.setHour(result.getHour() + this->getHour() + second.getHour());

        return result;
    }

    // Overload - operator
    Time operator-(const Time &second){
        Time result;

        result.setSec(abs(this->getSec() - second.getSec()));
        result.setMin(abs(this->getMin() - second.getMin()));
        result.setHour(abs(this->getHour() - second.getHour()));

        return result;
    }

    // Overload << operator
    friend ostream& operator<<(ostream& os, const Time& time)
    {
        os << "New time is: ";
        if(time.hour < 10)
            os << "0";
        os << time.hour << ":";
        if(time.min < 10)
            os << "0";
        os << time.min << ":";
        if(time.sec < 10)
            os << "0";
        os << time.sec << endl;

        return os;
    }

    // Overload >> operator
    friend istream& operator>>(istream& is, Time& time)
    {
        is >> time.hour;
        is >> time.min;
        is >> time.sec;

        // validate the input
        if(time.hour > 24 || time.hour < 0 || time.min > 60 || time.min < 0 || time.sec > 60 || time.sec < 0){
            cout << "Input is invalid. Closing the app.\n";
            exit(1);
        }

        return is;
    }

    int getSec() const {
        return sec;
    }

    void setSec(int sec) {
        Time::sec = sec;
    }

    int getMin() const {
        return min;
    }

    void setMin(int min) {
        Time::min = min;
    }

    int getHour() const {
        return hour;
    }

    void setHour(int hour) {
        Time::hour = hour;
    }

    void toString(){
        if(this->getHour() < 10)
            cout << "0";
        cout << this->getHour() << ":";
        if(this->getMin() < 10)
            cout << "0";
        cout << this->getMin() << ":";
        if(this->getSec() < 10)
            cout << "0";
        cout << this->getSec() << endl;
    }
};

int main() {

    Time first(12, 30, 7);
    Time second(10, 59, 55);
    Time third;

    cout << "First time: ";
    first.toString();

    cout << "Second time: ";
    second.toString();

    third = first + second;

    cout << "Final time after first + second: ";
    third.toString();

    third = first - second;

    cout << "Final time after first - second: ";
    third.toString();

    cout << "Enter new fields' values for Time object: \n";

    cin >> third;
    cout << third;

    return 0;
}