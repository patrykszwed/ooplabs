#include <iostream>
#include <cmath>

using namespace std;

class Rectangle{
private:
    float a,b;

public:
    Rectangle(int x, int y){
        this->a = x;
        this->b = y;
    }

    Rectangle(float x, float y){
        this->a = x;
        this->b = y;
    }

    float field(float x, float y){
        return x * y;
    }

    float diagonal(float x){
        return static_cast<float>(x * sqrt(2));
    }
};

class Cuboid : public Rectangle{

};

int main() {


    return 0;
}