#include <iostream>

class ComplexNumber {

private:
    double real;
    double imaginary;

public:
    friend std::ostream& operator <<(std::ostream&, const ComplexNumber&);
    ComplexNumber(double real, double imaginary);
    double GetReal() const;
    double GetImaginary() const;
    void SetReal(const double value);
    void SetImaginary(const double value);
    ComplexNumber operator +(const ComplexNumber& other);
    ComplexNumber operator -(const ComplexNumber& other);
    ComplexNumber operator *(const ComplexNumber& other);
    ComplexNumber operator /(const ComplexNumber& other);
    ComplexNumber& operator +=(const ComplexNumber& other);
    ComplexNumber& operator -=(const ComplexNumber& other);
    ComplexNumber& operator *=(const ComplexNumber& other);
    ComplexNumber& operator /=(const ComplexNumber& other);
    bool operator ==(const ComplexNumber& other);
    bool operator ==(const double& other);
    double Abs() const;
    ComplexNumber Pow(int degree) const;
};

std::ostream& operator << (std::ostream& out, const ComplexNumber& num)
{
    if (num.imaginary < 0) {
        out << num.real << num.imaginary << "i\n";
    }
    else {
        out << num.real << "+" << num.imaginary << "i\n";
    }
    return out;
}
