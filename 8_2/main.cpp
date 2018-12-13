#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

template <typename T>
class Points{
private:
    vector< pair <T, T> > vector;

public:
    Points(){}

    void setCoords(T x, T y){
        vector.push_back(make_pair(x, y));
    }

    void printPoints(){
        cout << endl;
        for(int i = 0; i < this->vector.size(); ++i) {
            cout << this->vector[i].first << " "
                 << this->vector[i].second << endl;
        }
    }

    bool static cmpfunc(const pair<T, T> &a, const pair<T, T> &b){  // comparison function
        if(a.first < b.first)   // check first values
            return true;
        else if(a.first > b.first)
            return false;
        else                    // if they are equal, then check with respect to second values
            return a.second < b.second;
    }

    const std::vector <pair<T, T>> &getVector() const {
        return vector;
    }

    void setVector(const std::vector <pair<T, T>> &vector) {
        Points::vector = vector;
    }
};

template <typename T>
void sortPoints(Points<T> &points){ // through reference as we assign new vector to variable points
    vector< pair <T, T> > vector = points.getVector();

    sort(vector.begin(), vector.end(), points.cmpfunc);

    points.setVector(vector);
}

int main() {
    // integer points
    Points<int> points1;
    points1.setCoords(5, 3);
    points1.setCoords(17, 10);
    points1.setCoords(17, -3);
    points1.setCoords(-1, 31);
    points1.setCoords(18, 20);
    points1.setCoords(18, 47);
    points1.setCoords(0, 0);
    points1.setCoords(31, -15);

    cout << "\n\t\t\t== Unsorted points ==" << endl;
    points1.printPoints();

    sortPoints(points1);

    cout << "\t\t\t== Sorted points ==" << endl;
    points1.printPoints();

    // floating points
    Points<float> points2;
    points2.setCoords(1.2, 4.15);
    points2.setCoords(-0.5, 21.3);
    points2.setCoords(-0.5, 7.8);
    points2.setCoords(12, -5);

    cout << "\n\t\t\t== Unsorted points ==" << endl;
    points2.printPoints();

    sortPoints(points2);

    cout << "\t\t\t== Sorted points ==" << endl;
    points2.printPoints();

    return 0;
}