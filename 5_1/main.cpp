#include <iostream>
#include <cmath>

using namespace std;

class Rectangle{
private:
    float a,b;

public:
    Rectangle(int x, int y){
        this->setA(x);
        this->setB(y);
    }

    Rectangle(float x, float y){
        this->setA(x);
        this->setB(y);
    }

    float field(){
        return this->getA() * this->getB();
    }

    virtual float diagonal(){
        return sqrt(this->getA() * this->getA() + this->getB() * this->getB());
    }

    float getA() const {
        return a;
    }

    void setA(float a) {
        Rectangle::a = a;
    }

    float getB() const {
        return b;
    }

    void setB(float b) {
        Rectangle::b = b;
    }
};

class Cuboid : public Rectangle{
private:
    float c;

public:
    Cuboid(float x, float y, float z)
    : Rectangle(x, y)   // call constructor from superclass
    {
        this->setC(z);
    }

    Cuboid(int x, int y, int z)
    : Rectangle(x, y)
    {
        this->setC(z);
    }

    float lateral(){
        return Rectangle::field() * 2 + this->getA() * this->getC() * 2 + this->getB() * this->getC() * 2;
    }

    float diagonal(){
        return sqrt(Rectangle::diagonal() * Rectangle::diagonal() + this->getC() * this->getC());
    }

    float getC() const {
        return c;
    }

    void setC(float c) {
        Cuboid::c = c;
    }
};

int main() {
    float a,b,c;
    int choice;

    cout << "Give a: ";
    if(!(cin >> a)){
        cout << "\n\n\nBad input! Exiting the program\n\n\n";
        exit(0);
    }
    cout << "Give b: ";
    if(!(cin >> b)){
        cout << "\n\n\nBad input! Exiting the program\n\n\n";
        exit(0);
    }
    cout << "Give c: ";
    if(!(cin >> c)){
        cout << "\n\n\nBad input! Exiting the program\n\n\n";
        exit(0);
    }

    cout << "If you want to display lateral area of cuboid choose 1\n"
         << "If you want to display diagonal of cuboid choose 2\n"
         << "If you want to exit, type whatever.\n";

    cin >> choice;

    Cuboid cuboid(a, b, c);

    switch(choice){
        case 1:{
            cout << "Lateral area of this cuboid = " << cuboid.lateral() << "\n";
        }break;
        case 2:{
            cout << "Diagonal of this cuboid = ";
            printf("%.2f\n", cuboid.diagonal());
            cout << "\n";
        }break;
        default:
            cout << "You decided to exit.";
            break;
    }

    return 0;
}