#include <iostream>

using namespace std;

class Arabic{
protected:
    int a;

public:
    Arabic(int x){
        this->setA(x);
    }

    void printArabicValue(){
        cout << "Value of this arabic number = " << this->getA() << "\n";
    }

    int getA() const {
        return a;
    }

    void setA(int a) {
        Arabic::a = a;
    }
};

class Roman : public Arabic{
private:
    string romanNumber;
public:
    Roman(int a)
    : Arabic(a)
    {
            string result;
            string M[] = {"","M","MM","MMM"};
            string C[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
            string X[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
            string I[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
            result = M[a/1000]+C[(a%1000)/100]+X[(a%100)/10]+I[(a%10)];
            this->setRomanNumber(result);
    }

    void printRomanValue(){
        cout << "Value of " << this->getA() << " in roman system = "
             << this->getRomanNumber() << endl;
    }

    const string &getRomanNumber() const {
        return romanNumber;
    }

    void setRomanNumber(const string &romanNumber) {
        Roman::romanNumber = romanNumber;
    }
};

int main() {
    int a;

    cout << "Give an integer number: ";
    if(!(cin >> a)){
        cout << "\n\n\nBad input! Exiting the program\n\n\n";
        exit(0);
    }

    Roman roman(a);
    roman.printArabicValue();
    roman.printRomanValue();

    return 0;
}