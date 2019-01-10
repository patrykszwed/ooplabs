#include <iostream>
#include <vector>
#include <sstream>

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


bool isOperator(const string &input) {
    string operators[] = {"-", "+", "*", "/"};

    for(int i = 0; i < 4; ++i)
        if(input == operators[i])
            return true;

    return false;
}

template <typename T>
void performOperation(const string &input, Stack<T> &stack) {
    T leftValue, rightValue, result;

    // load values
    rightValue = stack.top();
    stack.pop();
    leftValue = stack.top();
    stack.pop();

    if(input == "-")
        result = leftValue - rightValue;
    else if(input == "+")
        result = leftValue + rightValue;
    else if(input == "*")
        result = leftValue * rightValue;
    else if(input == "/")
        result = leftValue / rightValue;

    cout << result << endl;
    stack.push(result);
}

int main() {

    Stack<double> stack;
    string input;

    cout << "To exit calculator just type 'exit'\n";

    while(true){
        double num;

        cin >> input;

        if(input == "exit")
            break;

        // if numeric value
        if(istringstream(input) >> num){
            stack.push(num);
        }
        // if operator
        else if(isOperator(input))
            performOperation(input, stack);
        else
            cout << "Invalid input!\n";
    }

    return 0;
}