#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {

    int n, tmp;

    cout << "How many numbers your vectors will have?\n";
    if(!(cin >> n)) {
        cout << "\t\t\t Bad input!\t\t\t \nProvide a valid one(int)\n";
        exit(0);
    }

    // == First vector ==

    vector<int> orderVectorFirst;
    vector<int> valuesVectorFirst;

    cout << "Provide numbers for first vector: \n";
    for(int i = 0; i < n; ++i){
        if(!(cin >> tmp)) {
            cout << "\t\t\t Bad input!\t\t\t \nProvide a valid one(int)\n";
            exit(0);
        }

        if(tmp != 0){
            orderVectorFirst.push_back(1);
            valuesVectorFirst.push_back(tmp);
        }
        else
            orderVectorFirst.push_back(0);
    }

    /*
     *
     * DEBUG
     *
     *
    cout << "[";
    for(int temp : orderVectorFirst)
        cout << temp << ",";
    cout << "]";

    cout << "[";
    for(int temp : valuesVectorFirst)
        cout << temp << ",";
    cout << "]";
    */

    // == Second vector ==

    vector<int> orderVectorSecond;
    vector<int> valuesVectorSecond;

    cout << "Provide  numbers for second vector: \n";
    for(int i = 0; i < n; ++i){
        if(!(cin >> tmp)) {
            cout << "\t\t\t Bad input!\t\t\t \nProvide a valid one(int)\n";
            exit(0);
        }

        if(tmp != 0){
            orderVectorSecond.push_back(1);
            valuesVectorSecond.push_back(tmp);
        }
        else
            orderVectorSecond.push_back(0);
    }

    /*
     *
     * DEBUG
     *
     * cout << "[";
    for(int temp : orderVectorSecond)
        cout << temp << ",";
    cout << "]";

    cout << "[";
    for(int temp : valuesVectorSecond)
        cout << temp << ",";
    cout << "]";*/

    // == calculate scalar product ==
    int result = 0;
   for(int i = 0; i < n; ++i){
       if(orderVectorFirst.back() == 1 && orderVectorSecond.back() == 1) {
           result += valuesVectorFirst.back() * valuesVectorSecond.back();
           orderVectorFirst.pop_back();
           orderVectorSecond.pop_back();
           valuesVectorFirst.pop_back();
           valuesVectorSecond.pop_back();
       }
       else{
           orderVectorFirst.pop_back();
           orderVectorSecond.pop_back();
       }
   }

    cout << "Scalar product of these two vectors = " << result;

    return 0;
}