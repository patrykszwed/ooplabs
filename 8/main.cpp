#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class Stack{
private:
    vector<T> vector1;

public:
    void push(T x){
        vector1.push_back(x);
    }

    void pop() {
        if(vector1.empty()){
            throw out_of_range("Stack is empty");
        }
        vector1.pop_back();
    }

    T top(){
        if(vector1.empty()){
            throw out_of_range("Stack is empty");
        }
        return vector1.back();
    }

    bool empty(){
        return vector1.empty();
    }
};

int main() {

    Stack<int> stackInt;
    Stack<string> stackString;

    try {
        stackInt.push(15);
        stackString.push("Hello");
        stackString.push("World");
        stackInt.push(-5);
        stackInt.push(1);
        stackString.push("!");

        cout << "\n\t\t\t === stackInt ===\n";
        cout << "\nEmpty(0 - false, 1 - true) = " << stackInt.empty() << endl;
        cout << "Top = " << stackInt.top();
        cout << "\nPop\n";
        stackInt.pop();
        cout << "Top = " << stackInt.top() << endl;
        cout << "Pop\n";
        stackInt.pop();
        cout << "Top = " << stackInt.top() << endl;
        cout << "Pop\n";
        stackInt.pop();

        cout << "\n\t\t\t === stackString ===\n";
        cout << "\nEmpty(0 - false, 1 - true) = " << stackString.empty() << endl;
        cout << "Top = " << stackString.top();
        cout << "\nPop\n";
        stackString.pop();
        cout << "Top = " << stackString.top() << endl;
        cout << "Pop\n";
        stackString.pop();
        cout << "Top = " << stackString.top() << endl;
        cout << "Pop\n";
        stackString.pop();
        cout << "Top = " << stackString.top() << endl;
    }catch(exception &exc){
        cerr << " Exception: " << exc.what() << endl;
        return -1;
    }
    return 0;
}