#include <iostream>

using namespace std;

class Vehicle{
private:
    int productionYear;
    float mileage;
    string brand;
    string fuel;

public:
    bool isDiesel(){
        return (this->getFuel() == "Diesel" || this->getFuel() == "diesel");
    }

    float calculateLitres(float x){
        return (x * this->mileage) / 100;
    }

    bool isAntique(){
        return (2018 - this->getProductionYear() >= 25);
    }

    bool hasIndicator(){
        return bool(this->getBrand() != "BMW" || this->getBrand() != "bmw");
    }

    void toString(){
        cout << " productionYear = " << this->getProductionYear() << " mileage = " << this->getMileage()
             << " brand = " << this->getBrand() << " fuel = " << this->getFuel() << endl;
    }

    int getProductionYear() const {
        return productionYear;
    }

    void setProductionYear(int productionYear) {
        Vehicle::productionYear = productionYear;
    }

    float getMileage() const {
        return mileage;
    }

    void setMileage(float mileage) {
        Vehicle::mileage = mileage;
    }

    const string &getBrand() const {
        return brand;
    }

    void setBrand(const string &brand) {
        Vehicle::brand = brand;
    }

    const string &getFuel() const {
        return fuel;
    }

    void setFuel(const string &fuel) {
        Vehicle::fuel = fuel;
    }
};

class Car: public Vehicle{
private:
    int registrationYear;

public:
    Car(int registrationYear, int productionYear, float mileage, string brand, string fuel){
        this->setRegistrationYear(registrationYear);
        this->setProductionYear(productionYear);
        this->setMileage(mileage);
        this->setBrand(brand);
        this->setFuel(fuel);
    }

    int yearsSinceRegistration(){
        return 2018 - this->getRegistrationYear();
    }

    int getRegistrationYear() const {
        return registrationYear;
    }

    void setRegistrationYear(int registrationYear) {
        Car::registrationYear = registrationYear;
    }
};

class Bus: public Vehicle{
private:
    int numberOfSeats;

public:
    Bus(int numberOfSeats, int productionYear, float mileage, string brand, string fuel){
        this->setNumberOfSeats(numberOfSeats);
        this->setProductionYear(productionYear);
        this->setMileage(mileage);
        this->setBrand(brand);
        this->setFuel(fuel);
    }

    bool isEnoughSeats(int x){
        return x <= this->getNumberOfSeats();
    }

    int getNumberOfSeats() const {
        return numberOfSeats;
    }

    void setNumberOfSeats(int numberOfSeats) {
        Bus::numberOfSeats = numberOfSeats;
    }
};

int main() {
    int choice;

    cout << "If you want to create a Car type 1, if you prefer a Bus type 2, if you want to exit type whatever.\n";
    cin >> choice;

    int productionYear;
    float mileage, km;
    string brand, fuel;

    switch(choice){
        case 1:{
            int registrationYear;
            cout << "Give registration year: ";
            cin >> registrationYear;
            cout << "Give production year: ";
            cin >> productionYear;
            cout << "Give mileage: ";
            cin >> mileage;
            cout << "Give brand: ";
            cin >> brand;
            cout << "Give fuel type: ";
            cin >> fuel;

            Car car(registrationYear, productionYear, mileage, brand, fuel);

            cout << "Some information about this car:\n registrationYear = " << car.getRegistrationYear();
            car.toString();

            cout << "Does it have an indicator? " << car.hasIndicator() << endl;
            cout << "Is that Diesel? " << car.isDiesel() << endl;
            cout << "Is that antique? " << car.isAntique() << endl;
            cout << "How many kilometers do you want to travel? ";
            cin >> km;
            cout << "You will need " << car.calculateLitres(km) << " litres of fuel." << endl;
            cout << "Years since registration: " << car.yearsSinceRegistration() << endl;
        }break;
        case 2:{
            int numberOfSeats, amountOfPeople;
            cout << "Give number of seats: ";
            cin >> numberOfSeats;
            cout << "Give production year: ";
            cin >> productionYear;
            cout << "Give mileage: ";
            cin >> mileage;
            cout << "Give brand: ";
            cin >> brand;
            cout << "Give fuel type: ";
            cin >> fuel;

            Bus bus(numberOfSeats, productionYear, mileage, brand, fuel);

            cout << "Some information about this bus:\n numberOfSeats = " << bus.getNumberOfSeats();
            bus.toString();

            cout << "Does it have an indicator? " << bus.hasIndicator() << endl;
            cout << "Is that Diesel? " << bus.isDiesel() << endl;
            cout << "Is that antique? " << bus.isAntique() << endl;
            cout << "How many kilometers do you want to travel? ";
            cin >> km;
            cout << "You will need " << bus.calculateLitres(km) << " litres of fuel." << endl;
            cout << "How many people do you want to take on trip? ";
            cin >> amountOfPeople;
            if(bus.isEnoughSeats(amountOfPeople))
                cout << "There is enough space.\n";
            else
                cout << "This bus is too small for you.\n";
        }break;
        default:
            cout << "You decided to exit.";
            break;
    }

    return 0;
}