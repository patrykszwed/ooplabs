#include <iostream>

using namespace std;

class Amphibious;

class Vehicle{
private:
    float weight;
    int maxSpeed;
    int productionYear;

public:
    Vehicle(float weight, int maxSpeed, int productionYear) : weight(weight), maxSpeed(maxSpeed),
                                                              productionYear(productionYear) {}

    bool isAntique(){
        return (2018 - this->getProductionYear() >= 25);
    }

    bool isFast(){
        return (this->getMaxSpeed() >= 150);
    }

    float getWeight() const {
        return weight;
    }

    void setWeight(float weight) {
        Vehicle::weight = weight;
    }

    int getMaxSpeed() const {
        return maxSpeed;
    }

    void setMaxSpeed(int maxSpeed) {
        Vehicle::maxSpeed = maxSpeed;
    }

    int getProductionYear() const {
        return productionYear;
    }

    void setProductionYear(int productionYear) {
        Vehicle::productionYear = productionYear;
    }
};

class Car : public Vehicle{
private:
    float mileage;

public:

    Car(float weight, int maxSpeed, int productionYear, float mileage) : Vehicle(weight, maxSpeed, productionYear),
                                                                         mileage(mileage) {}

    float calculateLitres(float x){
        return (x * this->getMileage()) / 100;
    }

    float getMileage() const {
        return mileage;
    }

    void setMileage(float mileage) {
        Car::mileage = mileage;
    }
};

class Boat : public Vehicle{
private:
    int numberOfSeats;

public:

    Boat(float weight, int maxSpeed, int productionYear, int numberOfSeats) : Vehicle(weight, maxSpeed, productionYear),
                                                                              numberOfSeats(numberOfSeats) {}

    bool isEnoughSeats(int x){
        return x <= this->getNumberOfSeats();
    }

    int getNumberOfSeats() const {
        return numberOfSeats;
    }

    void setNumberOfSeats(int numberOfSeats) {
        Boat::numberOfSeats = numberOfSeats;
    }
};

class Amphibious : public Car, public Boat{
private:
    float heightOfAmphibious;

public:

    Amphibious(float weight, int maxSpeed, int productionYear, float mileage, int numberOfSeats, float heightOfAmphibious)
            : Car(weight, maxSpeed, productionYear, mileage),
              Boat(weight, maxSpeed, productionYear, numberOfSeats),heightOfAmphibious(heightOfAmphibious) {}


    bool isAmphibiousHigh(){
        return (this->getHeightOfAmphibious() >= 250.5);
    }

    float getHeightOfAmphibious() const {
        return heightOfAmphibious;
    }

    void setHeightOfAmphibious(float heightOfAmphibious) {
        Amphibious::heightOfAmphibious = heightOfAmphibious;
    }
};

int main() {
    int choice, seats;
    float km;

    Amphibious amphibious(980.5, 120, 2015, 20.7, 32, 254.3);

    cout << "If you want to check if amphibious is high choose 1\n"
         << "If you want to check if there are enough seats choose 2\n"
         << "If you want to calculate litres choose 3\n"
         << "If you want to check if that is an antique choose 4\n"
         << "If you want to exit, type whatever.\n";

    if(!(cin >> choice)){
        cout << "\t\t\t Bad input! \t\t\t\nExiting the program!";
        return 0;
    }

    switch(choice){
        case 1:{
            cout << "Is amphibious high? " << amphibious.isAmphibiousHigh();
        }break;
        case 2:{
            cout << "How many seats do you need?";
            if(!(cin >> seats)){
                cout << "\t\t\t Bad input! \t\t\t\nExiting the program!";
                return 0;
            }
            cout << "Is there enough space? " << amphibious.isEnoughSeats(seats) << endl;
        }break;
        case 3:{
            cout << "How many kilometers do you want to travel?";
            if(!(cin >> km)){
                cout << "\t\t\t Bad input! \t\t\t\nExiting the program!";
                return 0;
            }
            cout << "You will need " << amphibious.calculateLitres(km) << " litres of fuel.\n";
        }break;
        case 4:{
            //cout << "Is amphibious an antique? " << amphibious.isAntique() << endl;
            cout << "We cannot use functions from class Vehicle as"
                    " we have two copies of object and compiler"
                    " doesn't know with which one it should work.\nSolution is making a virtual class.\n";
        }break;
        default:
            cout << "You decided to exit.";
            break;
    }

    return 0;
}