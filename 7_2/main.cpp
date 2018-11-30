#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

// == abstract class Shape(interface) ==
class Shape{
public:
    virtual void drawShape() = 0;
    virtual float calculateArea() = 0;
};

class Square : public Shape{
private:
    float side;

public:
    Square(float side) : side(side){}

    void drawShape(){
        // First let's draw the top "wall"
        for (int column = 0; column < this->getSide(); ++column)
        {
            cout << "*";
        }
        cout << "\n";

        // Now we're going to print the sides.
        for (int row = 0; row < this->getSide() - 2; ++row)
        {
            // print the left "wall"
            cout << "*";
            for (int column = 0; column < this->getSide() - 2; ++column)
            {
                cout << " ";
            }
            // finally print the right "wall" and a carraige return
            cout << "*\n";
        }

        // Once the loop is done, we can print the bottom wall the same way we printed the top one.
        for (int column = 0; column < this->getSide(); ++column)
        {
            cout << "*";
        }
        cout << "\n";
    }

    float calculateArea(){
        return this->getSide() * this->getSide();
    }

    float getSide() const {
        return side;
    }

    void setSide(float side) {
        Square::side = side;
    }
};

class Rectangle : public Shape{
private:
    float width, height;

public:
    Rectangle(float width, float height) : width(width), height(height) {}

    void drawShape(){
        for (int column = 0; column < this->getWidth(); ++column)
        {
            cout << "*";
        }
        cout << "\n";

        for (int row = 0; row < this->getHeight() - 2; ++row)
        {
            cout << "*";
            for (int column = 0; column < this->getWidth() - 2; ++column)
            {
                cout << " ";
            }
            cout << "*\n";
        }

        for (int column = 0; column < this->getWidth(); ++column)
        {
            cout << "*";
        }
        cout << "\n";
    }

    float calculateArea(){
        return this->getHeight() * this->getWidth();
    }

    float getWidth() const {
        return width;
    }

    void setWidth(float width) {
        Rectangle::width = width;
    }

    float getHeight() const {
        return height;
    }

    void setHeight(float height) {
        Rectangle::height = height;
    }
};

class Triangle : public Shape{
private:
    float height, width;

public:
    Triangle(float height, float width) : height(height), width(width) {}

    void drawShape(){
        for(int i = 1, k = 0; i <= this->getHeight(); ++i, k = 0)
        {
            for(int space = 1; space <= this->getHeight()-i; ++space)
            {
                cout <<"  ";
            }

            while(k != 2*i-1)
            {
                cout << "* ";
                ++k;
            }
            cout << endl;
        }
    }

    float calculateArea(){
        return float(this->getWidth() * this->getHeight() * 0.5);
    }

    float getWidth() const {
        return width;
    }

    void setWidth(float width) {
        Triangle::width = width;
    }

    float getHeight() const {
        return height;
    }

    void setHeight(float height) {
        Triangle::height = height;
    }
};

class Circle : public Shape{
private:
    int radius;

public:
    Circle(int radius) : radius(radius) {}

    void drawShape(){
        int circle_radius = this->getRadius();

        for (int i = 0; i <= 2*circle_radius; i++)
        {
            for (int j = 0; j <= 2*circle_radius; j++)
            {
                float distance_to_centre = static_cast<float>(sqrt((i - circle_radius) * (i - circle_radius) + (j - circle_radius) * (j - circle_radius)));
                if (distance_to_centre > circle_radius-0.5 && distance_to_centre < circle_radius+0.5)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }

    float calculateArea(){
        return float(this->getRadius() * this->getRadius() * M_PI);
    }

    int getRadius() const {
        return radius;
    }

    void setRadius(int radius) {
        Circle::radius = radius;
    }
};

int isValid(string input){
    if(input[0] == '-')
        return 0;

    for (char i : input)
        if (!isdigit(i))
            return 0;

    return 1;
}


int main() {
    string choice;

    cout << "Which shape do you want to use: "
         << "\n1 - square"
         << "\n2 - rectangle"
         << "\n3 - triangle"
         << "\n4 - circle" << endl;

    cin >> choice;

    if(!(isValid(choice))){
        while(!isValid(choice)){
            cout << "Provide a valid number!\n";
            cin >> choice;
        }
    }

    int choiceInteger = stoi(choice);
    string heightString, widthString;
    float height, width;

    switch(choiceInteger){
        case 1:{
            cout << "Provide a length of one side of this square.\n";
            cin >> heightString;
            if(!(isValid(heightString))){
                while(!isValid(heightString)){
                    cout << "Provide a valid number!\n";
                    cin >> heightString;
                }
            }
            height = stof(heightString);
            Square square(height);
            square.drawShape();
            cout << "Area = " << square.calculateArea() << endl;
        }break;
        case 2:{
            cout << "Provide a height of this figure.\n";
            cin >> heightString;
            if(!(isValid(heightString))){
                while(!isValid(heightString)){
                    cout << "Provide a valid number!\n";
                    cin >> heightString;
                }
            }
            cout << "Provide a width of this figure.\n";
            cin >> widthString;
            if(!(isValid(widthString))){
                while(!isValid(widthString)){
                    cout << "Provide a valid number!\n";
                    cin >> widthString;
                }
            }
            height = stof(heightString);
            width = stof(widthString);
            Rectangle rectangle(width, height);
            rectangle.drawShape();
            cout << "Area = " << rectangle.calculateArea() << endl;
        }break;
        case 3:{
            cout << "Provide a height of this triangle.\n";
            cin >> heightString;
            if(!(isValid(heightString))){
                while(!isValid(heightString)){
                    cout << "Provide a valid number!\n";
                    cin >> heightString;
                }
            }
            cout << "Provide a width of this triangle.\n";
            cin >> widthString;
            if(!(isValid(widthString))){
                while(!isValid(widthString)){
                    cout << "Provide a valid number!\n";
                    cin >> widthString;
                }
            }
            height = stof(heightString);
            width = stof(widthString);
            Triangle triangle(height, width);
            triangle.drawShape();
            cout << "Area = " << triangle.calculateArea() << endl;
        }break;
        case 4:{
            cout << "Provide a radius of this circle.\n";
            cin >> widthString;
            if(!(isValid(widthString))){
                while(!isValid(widthString)){
                    cout << "Provide a valid number!\n";
                    cin >> widthString;
                }
            }
            width = (int)stof(widthString);
            Circle circle(width);
            circle.drawShape();
            cout << "Area = " << circle.calculateArea() << endl;
        }break;
        default:
            break;
    }

    return 0;
}