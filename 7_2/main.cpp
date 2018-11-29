#include <iostream>
#include <string.h>
#include <Windows.h>

using namespace std;

// == abstract class Shape(interface) ==
class Shape{
public:
    virtual void drawShape(int x, int y, int width, int height, int curPosX, int curPosY) = 0;
    virtual bool setxy(int x, int y) = 0;
};

class TwoDimensionalShape : public Shape{
private:
    float width, height;
    string shape;

public:

    TwoDimensionalShape(float width, float height, const string &shape) : width(width), height(height), shape(shape) {}

    void drawShape(int x, int y, int width, int height, int curPosX=0, int curPosY=0){
        setxy(x,y);cout << char(201);
        for(int i = 1; i < width; i++)cout << char(205);
        cout << char(187);
        setxy(x,height + y);cout << char(200);
        for(int i = 1; i < width; i++)cout << char(205);
        cout << char(188);
        for(int i = y + 1; i < height + y; i++)
        {
            setxy(x,i);cout << char(186);
            setxy(x + width,i);cout << char(186);
        }
        setxy(curPosX,curPosY);
    }

    bool setxy(int x, int y){
        COORD c = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
        return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
    }

    const string &getShape() const {
        return shape;
    }

    void setShape(const string &shape) {
        TwoDimensionalShape::shape = shape;
    }

    float getWidth() const {
        return width;
    }

    void setWidth(int width) {
        TwoDimensionalShape::width = width;
    }

    float getHeight() const {
        return height;
    }

    void setHeight(int height) {
        TwoDimensionalShape::height = height;
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
            TwoDimensionalShape twoDimensionalShape(height, height, "square");
            //cout << "Area = " << twoDimensionalShape.calculateArea();
            twoDimensionalShape.drawShape(15,10, height, height );
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
            //TwoDimensionalShape twoDimensionalShape(width, height, "rectangle");
            //cout << "Area = " << twoDimensionalShape.calculateArea();
        }break;
        case 3:{
            cout << "Provide a height of this figure.\n";
            cin >> heightString;
            if(!(isValid(heightString))){
                while(!isValid(heightString)){
                    cout << "Provide a valid number!\n";
                    cin >> heightString;
                }
            }
            cout << "Provide a base of this figure.\n";
            cin >> widthString;
            if(!(isValid(widthString))){
                while(!isValid(widthString)){
                    cout << "Provide a valid number!\n";
                    cin >> widthString;
                }
            }
            height = stof(heightString);
            width = stof(widthString);
            TwoDimensionalShape twoDimensionalShape(width, height, "triangle");
            //cout << "Area = " << twoDimensionalShape.calculateArea();
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
            width = stof(widthString);
            TwoDimensionalShape twoDimensionalShape(width, width, "circle");
            //cout << "Area = " << twoDimensionalShape.calculateArea();
        }break;
        default:
            break;
    }

    return 0;
}