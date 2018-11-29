#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Point{
private:
    T x, y;

public:
    Point(T x, T y) : x(x), y(y) {}

    T getX() const {
        return x;
    }

    void setX(T x) {
        Point::x = x;
    }

    T getY() const {
        return y;
    }

    void setY(T y) {
        Point::y = y;
    }

};

void sortPoints()

int main() {
    Point<int> point1(15, 13);
    Point<int> point2(7, 23);
    Point<int> point3(44, 0);
    Point<int>

    return 0;
}