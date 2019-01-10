#include <iostream>
#include <vector>
#include <sstream>
#include <map>

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

int operatorPrecedence(const string &input) {
    if (input == "(")
        return 0;
    if (input == "-" || input == "+" || input == ")")
        return 1;
    return 2;
}

bool isOperator(const string &input) {
    if(input == "+" || input == "-" || input == "*" || input == "/")
        return true;

    return false;
}

double performOperations(vector<string> input) {

    double value1, value2;
    Stack<double> values;

    for(string i : input) {
        if(isdigit(i[0])){
            values.push(stod(i));
            continue;
        }

        value1 = values.top();
        values.pop();
        value2 = values.top();
        values.pop();

        if (i == "-")
            values.push(value2 - value1);
        else if (i == "+")
            values.push(value2 + value1);
        else if (i == "*")
            values.push(value2 * value1);
        else if (i == "/")
            values.push(value2 / value1);
    }

    return values.top();
}

vector<string> normalToRpn(vector<string> input) {
    ::vector<string> outputVector;
    Stack<string> operatorStack;
    string temp;

    for (string i : input) {
        if (isdigit(i[0]))
            outputVector.push_back(i);
        else if (isOperator(i)) {
            while (!operatorStack.empty() && operatorPrecedence(operatorStack.top()) >= operatorPrecedence(i)){
                outputVector.push_back(operatorStack.top());
                operatorStack.pop();
            }
            operatorStack.push(i);
        }
        else if (i == "(")
            operatorStack.push(i);
        else if (i == ")"){
            while(operatorStack.top() != "("){
                outputVector.push_back(operatorStack.top());
                operatorStack.pop();
            }
            operatorStack.pop();
        }
    }
    while(!operatorStack.empty()){
        outputVector.push_back(operatorStack.top());
        operatorStack.pop();
    }

    return outputVector;
}

int main() {

    string input, output, temp;
    getline(cin, input);
    istringstream istringstream1(input);

    vector<string> tempVector;

    while(istringstream1 >> temp)
        tempVector.push_back(temp);

    vector<string> rpn = normalToRpn(tempVector);
    for(const string &i : rpn)
        cout << i;

    cout << "\nResult is = " << performOperations(rpn);

    return 0;
}