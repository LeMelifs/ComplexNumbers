#include <iostream>

class ComplexNumber {

private:
    double real;
    double imaginary;

public:

    friend std::ostream& operator <<(std::ostream&, const ComplexNumber&);

    ComplexNumber() {
        real = 0;
        imaginary = 0;
    }

    ComplexNumber(double real, double imaginary) {
        this->real = real;
        this->imaginary = imaginary;
    }

    double GetReal() const {
        return real;
    }

    double GetImaginary() const {
        return imaginary;
    }

    void SetReal(double value) {
        real = value;
    }

    void SetImaginary(double value) {
        imaginary = value;
    }

    ComplexNumber operator +(const ComplexNumber& other) {
        double new_real = real + other.real;
        double new_imaginary = imaginary + other.imaginary;
        return ComplexNumber(new_real, new_imaginary);
    }

    ComplexNumber operator -(const ComplexNumber& other) {
        double new_real = real - other.real;
        double new_imaginary = imaginary - other.imaginary;
        return ComplexNumber(new_real, new_imaginary);
    }

    ComplexNumber operator *(const ComplexNumber& other) {
        double new_real = real * other.real - imaginary * other.imaginary;
        double new_imaginary = real * other.imaginary + other.real * imaginary;
        return ComplexNumber(new_real, new_imaginary);
    }

    ComplexNumber operator /(const ComplexNumber& other) {
        double denominator = other.real * other.real + other.imaginary * other.imaginary;
        double new_real = (real * other.real + imaginary * other.imaginary) / denominator;
        double new_imaginary = (other.real * imaginary - real * other.imaginary) / denominator;
        return ComplexNumber(new_real, new_imaginary);
    }

    void operator +=(const ComplexNumber& other) {
        real = (*this + other).real;
        imaginary = (*this + other).imaginary;
    }

    void operator -=(const ComplexNumber& other) {
        real = (*this - other).real;
        imaginary = (*this - other).imaginary;
    }

    void operator *=(const ComplexNumber& other) {
        real = (*this * other).real;
        imaginary = (*this * other).imaginary;
    }

    void operator /=(const ComplexNumber& other) {
        real = (*this / other).real;
        imaginary = (*this / other).imaginary;
    }

    bool operator ==(const ComplexNumber& other) {
        return (real == other.real && imaginary == other.imaginary);
    }

    bool operator ==(const double& other) {
        return (real = other && imaginary == 0);
    }

    double Abs() {
        return std::sqrt(real * real + imaginary * imaginary);
    }

    ComplexNumber Pow(int degree) {
        double r = std::pow(this->Abs(), degree);
        double phi = std::atan2(imaginary, real);
        double new_real = r * std::cos(degree * phi);
        double new_imaginary = r * std::sin(degree * phi);
        return ComplexNumber(new_real, new_imaginary);
    }
};

std::ostream& operator << (std::ostream& out, const ComplexNumber& num)
{
    if (num.imaginary < 0)
        out << num.real << num.imaginary << "i\n";
    else
        out << num.real << "+" << num.imaginary << "i\n";
    return out;
}