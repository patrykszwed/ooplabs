#include <iostream>

using namespace std;

class Vehicle{
private:
    int productionYear;
    float mileage;
    string brand;
    string fuel;

public:
    Vehicle(int productionYear, float mileage, string brand, string fuel){
        this->setProductionYear(productionYear);
        this->setMileage(mileage);
        this->setBrand(brand);
        this->setFuel(fuel);
    }

    Vehicle() {}

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

class Car{
private:
    int registrationYear;

public:
    Vehicle* vehicle;

    Car(int registrationYear, int productionYear, float mileage, string brand, string fuel){
        this->setRegistrationYear(registrationYear);
         vehicle = new Vehicle(productionYear, mileage, brand, fuel);
    }

    bool isDiesel(){
        return (vehicle->getFuel() == "Diesel" || vehicle->getFuel() == "diesel");
    }

    float calculateLitres(float x){
        return (x * vehicle->getMileage()) / 100;
    }

    bool isAntique(){
        return (2018 - vehicle->getProductionYear() >= 25);
    }

    bool hasIndicator(){
        return bool(vehicle->getBrand() != "BMW" || vehicle->getBrand() != "bmw");
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

    void toString(){
        cout << "Some information about this car:\n registrationYear = " << this->getRegistrationYear();
        vehicle->toString();
    }
};

class Bus{
private:
    int numberOfSeats;

public:
    Vehicle* vehicle;

    Bus(int numberOfSeats, int productionYear, float mileage, string brand, string fuel){
        this->setNumberOfSeats(numberOfSeats);
        vehicle = new Vehicle(productionYear, mileage, brand, fuel);
    }

    bool isDiesel(){
        return (vehicle->getFuel() == "Diesel" || vehicle->getFuel() == "diesel");
    }

    float calculateLitres(float x){
        return (x * vehicle->getMileage()) / 100;
    }

    bool isAntique(){
        return (2018 - vehicle->getProductionYear() >= 25);
    }

    bool hasIndicator(){
        return bool(vehicle->getBrand() != "BMW" || vehicle->getBrand() != "bmw");
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

    void toString(){
        cout << "Some information about this bus:\n numberOfSeats = " << this->getNumberOfSeats();
        vehicle->toString();
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
            if(!(cin >> registrationYear)){
                cout << "\n\n\nBad input! Exiting the program\n\n\n";
                exit(0);
            }
            cout << "Give production year: ";
            if(!(cin >> productionYear)){
                cout << "\n\n\nBad input! Exiting the program\n\n\n";
                exit(0);
            }
            cout << "Give mileage: ";
            if(!(cin >> mileage)){
                cout << "\n\n\nBad input! Exiting the program\n\n\n";
                exit(0);
            }
            cout << "Give brand: ";
            if(!(cin >> brand)){
                cout << "\n\n\nBad input! Exiting the program\n\n\n";
                exit(0);
            }
            cout << "Give fuel type: ";
            if(!(cin >> fuel)){
                cout << "\n\n\nBad input! Exiting the program\n\n\n";
                exit(0);
            }

            Car car(registrationYear, productionYear, mileage, brand, fuel);

            car.toString();

            cout << "Does it have an indicator? " << car.hasIndicator() << endl;
            cout << "Is that Diesel? " << car.isDiesel() << endl;
            cout << "Is that antique? " << car.isAntique() << endl;
            cout << "How many kilometers do you want to travel? ";
            if(!(cin >> km)){
                cout << "\n\n\nBad input! Exiting the program\n\n\n";
                exit(0);
            }
            cout << "You will need " << car.calculateLitres(km) << " litres of fuel." << endl;
            cout << "Years since registration: " << car.yearsSinceRegistration() << endl;
        }break;
        case 2:{
            int numberOfSeats, amountOfPeople;
            cout << "Give number of seats: ";
            if(!(cin >> numberOfSeats)){
                cout << "\n\n\nBad input! Exiting the program\n\n\n";
                exit(0);
            }
            cout << "Give production year: ";
            if(!(cin >> productionYear)){
                cout << "\n\n\nBad input! Exiting the program\n\n\n";
                exit(0);
            }
            cout << "Give mileage: ";
            if(!(cin >> mileage)){
                cout << "\n\n\nBad input! Exiting the program\n\n\n";
                exit(0);
            }
            cout << "Give brand: ";
            if(!(cin >> brand)){
                cout << "\n\n\nBad input! Exiting the program\n\n\n";
                exit(0);
            }
            cout << "Give fuel type: ";
            if(!(cin >> fuel)){
                cout << "\n\n\nBad input! Exiting the program\n\n\n";
                exit(0);
            }

            Bus bus(numberOfSeats, productionYear, mileage, brand, fuel);

            bus.toString();

            cout << "Does it have an indicator? " << bus.hasIndicator() << endl;
            cout << "Is that Diesel? " << bus.isDiesel() << endl;
            cout << "Is that antique? " << bus.isAntique() << endl;
            cout << "How many kilometers do you want to travel? ";
            if(!(cin >> km)){
                cout << "\n\n\nBad input! Exiting the program\n\n\n";
                exit(0);
            }
            cout << "You will need " << bus.calculateLitres(km) << " litres of fuel." << endl;
            cout << "How many people do you want to take on trip? ";
            if(!(cin >> amountOfPeople)){
                cout << "\n\n\nBad input! Exiting the program\n\n\n";
                exit(0);
            }
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