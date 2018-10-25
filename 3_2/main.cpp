#include <iostream>

using namespace std;

class Complex{
private:
    double real;
    double imaginary;

public:
    Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

    Complex(){

    }

    // Override + operator
    Complex operator+(const Complex &second){
        Complex result;

        result.setReal(this->getReal() + second.getReal());
        result.setImaginary(this->getImaginary() + second.getImaginary());

        return result;
    }

    // Override - operator
    Complex operator-(const Complex &second){
        Complex result;

        result.setReal(this->getReal() - second.getReal());
        result.setImaginary(this->getImaginary() - second.getImaginary());

        return result;
    }

    // Override * operator
    Complex operator*(const Complex &second){
        Complex result;

        result.setReal(this->getReal() * second.getReal() - this->getImaginary() * second.getImaginary());
        result.setImaginary(this->getReal() * second.getImaginary() + this->getImaginary() * second.getReal());

        return result;
    }

    // Override / operator
    Complex operator/(const Complex &second){
        Complex result;

        double div = (second.getReal() * second.getReal()) + (second.getImaginary() * second.getImaginary());
        result.setReal((this->getReal() * second.getReal()) + (this->getImaginary() * second.getImaginary()));
        result.setReal(result.getReal() / div);
        result.setImaginary((this->getImaginary() * second.getReal()) - (this->getReal() * second.getImaginary()));
        result.setImaginary(result.getImaginary() / div);

        return result;
    }

    double getReal() const {
        return real;
    }

    void setReal(double real) {
        Complex::real = real;
    }

    double getImaginary() const {
        return imaginary;
    }

    void setImaginary(double imaginary) {
        Complex::imaginary = imaginary;
    }
};

int main() {

    Complex first(15, 5);
    Complex second(24, 18);

    Complex result = first + second;

    cout << "Result of adding x = (" << first.getReal() << ", " << first.getImaginary() << "i) to "
        << "y = (" << second.getReal() << ", " << second.getImaginary() << "i) = "
        << "(" << result.getReal() << ", " << result.getImaginary() << "i)\n";

    result = first - second;

    cout << "Result of subtracting x = (" << first.getReal() << ", " << first.getImaginary() << "i) from "
         << "y = (" << second.getReal() << ", " << second.getImaginary() << "i) = "
         << "(" << result.getReal() << ", " << result.getImaginary() << "i)\n";

    result = first * second;

    cout << "Result of multiplying x = (" << first.getReal() << ", " << first.getImaginary() << "i) times "
         << "y = (" << second.getReal() << ", " << second.getImaginary() << "i) = "
         << "(" << result.getReal() << ", " << result.getImaginary() << "i)\n";

    result = first / second;

    cout << "Result of dividing x = (" << first.getReal() << ", " << first.getImaginary() << "i) with "
         << "y = (" << second.getReal() << ", " << second.getImaginary() << "i) = "
         << "(" << result.getReal() << ", " << result.getImaginary() << "i)\n";

    return 0;
}