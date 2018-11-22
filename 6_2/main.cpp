#include <iostream>

using namespace std;

class Thing{
private:
    string color;

public:
    Thing(const string &color) : color(color) {}

    void showColor(){
        cout << "Color = " << this->getColor() << endl;
    }

    void showThing(){
      cout << "That is a thing.\n";
    };

    const string &getColor() const {
        return color;
    }

    void setColor(const string &color) {
        Thing::color = color;
    }
};

class Machine : virtual public Thing{
private:
    int productionYear;

public:
    Machine(const string &color, int productionYear) : Thing(color), productionYear(productionYear) {}

    void showMachine(){
        cout << "That is a machine.\n";
    }

    int getProductionYear() const {
        return productionYear;
    }

    void setProductionYear(int productionYear) {
        Machine::productionYear = productionYear;
    }
};

class Brake{
private:
    float priceOfBrake;

public:
    Brake(float price) : priceOfBrake(price) {}

    float getPriceOfBrake() const {
        return priceOfBrake;
    }

    void setPriceOfBrake(float price) {
        Brake::priceOfBrake = price;
    }
};

class Car : public Machine, public Brake{
public:
    Car(const string &color, int productionYear, float price) : Machine(color, productionYear), Brake(price), Thing(color) {}

    void showCar(){
        cout << "That is a car.\n";
    }
};

class Bicycle : public Machine, public Brake{
public:
    Bicycle(const string &color, int productionYear, float price) : Machine(color, productionYear), Brake(price), Thing(color) {}

    void showBicycle(){
        cout << "That is a bicycle.\n";
    }
};



int main() {
    int choice;

    Bicycle bicycle("red", 2015, 1125);
    Car car("black", 2018, 54000.50);

    cout << "If you want to display info about bicycle choose 1\n"
         << "If you want to display info about car choose 2\n"
         << "If you want to exit, type whatever.\n";

    if(!(cin >> choice)){
        cout << "\t\t\t Bad input! \t\t\t\nExiting the program!";
        return 0;
    }

    switch(choice){
        case 1:{
            cout << "productionYear = " << bicycle.getProductionYear() << endl;
            cout << "priceOfBrake = " << bicycle.getPriceOfBrake() << endl;
            bicycle.showBicycle();
            bicycle.showMachine();
            bicycle.showColor();
            bicycle.showThing();
        }break;
        case 2:{
            cout << "productionYear = " << car.getProductionYear() << endl;
            cout << "priceOfBrake = " << car.getPriceOfBrake() << endl;
            car.showCar();
            car.showMachine();
            car.showColor();
            car.showThing();
        }break;
        default:
            cout << "You decided to exit.";
            break;
    }

    return 0;
}