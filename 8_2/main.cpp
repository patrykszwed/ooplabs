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
        for(int i = 0; i < vector.size(); ++i) {
            cout << vector[i].first << " "
                 << vector[i].second << endl;
        }
    }

    const std::vector <pair<T, T>> &getVector() const {
        return vector;
    }

    T cmpfunc()
};


template <typename T>
void sortPoints(Points<T> points){

    vector< pair <T, T> > vector = points.getVector();

    for(int i = 0; i < vector.size(); ++i){

        // DEBUG
        /*cout << vector[i].first << " "
             << vector[i].second << endl;
             */

        // nie ma qsort() dla vectorow chyba
        sort(vector.begin(), vector.end(), cmpfunc());
    }
}

/*template <typename T>
void printSortedPoints(Points<T> points){
    cout << points.getVector().
}*/

int main() {
    Points<int> points1;
    points1.setCoords(5, 3);
    points1.setCoords(17, 10);
    points1.setCoords(-1, 31);
    points1.setCoords(18, 20);
    points1.setCoords(0, 0);

    points1.printPoints();
    cout << "\n";
    sortPoints(points1);
    cout << endl;
    points1.printPoints();

    return 0;
}