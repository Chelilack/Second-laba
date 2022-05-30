#pragma once
#include <iostream>
using namespace std;
class ComplexNumber
{
private:
    float Real;
    float Imaginary;
public:
    ComplexNumber(float Real, float Imaginary);
    ComplexNumber();

public:
    void RandomInput();
    void RandomInput(float minReal,float maxReal, float minIm, float  maxIm);
    void Input();
    float GetRe() const;
    float GetIm() const;
    bool operator >(const ComplexNumber number)
    {
        if (this->GetRe() > number.GetRe())
        {
            return true;
        }
        else if (this->GetRe() == number.GetRe()) 
        {
            if (this->GetIm() > number.GetIm()) 
            {
                return true;
            }
        }
        else
        {
            return false;
        }
    }
    bool operator <(const ComplexNumber number)
    {
        if (this->GetRe() < number.GetRe())
        {
            return true;
        }
        else if (this->GetRe() == number.GetRe())
        {
            if (this->GetIm() < number.GetIm())
            {
                return true;
            }
        }
        else
        {
            return false;
        }
    }
    bool operator <=(const ComplexNumber number)
    {
        if (this->GetRe() < number.GetRe())
        {
            return true;
        }
        else if (this->GetRe() == number.GetRe() && this->GetIm() == number.GetIm()) return true;
        else if (this->GetRe() == number.GetRe() && this->GetIm() < number.GetIm()) return true;
        else
        {
            return false;
        }
    }
    bool operator >=(const ComplexNumber number)
    {
        if (this->GetRe() > number.GetRe())
        {
            return true;
        }
        else if (this->GetRe() == number.GetRe() && this->GetIm() == number.GetIm()) return true;
        else if (this->GetRe() == number.GetRe() && this->GetIm() > number.GetIm()) return true;
        else
        {
            return false;
        }
    }
    bool operator ==(const ComplexNumber number)
    {
       
        if (this->GetRe() == number.GetRe() && this->GetIm() == number.GetIm()) return true;
        else return false;
    }
    bool operator !=(const ComplexNumber number)
    {

        if (this->GetRe() != number.GetRe() || this->GetIm() != number.GetIm()) return true;
        else return false;
    }
    friend ostream& operator<<(ostream& os, const ComplexNumber& complexNumber);
};
ComplexNumber::ComplexNumber(float Real, float Imaginary) : Real(Real), Imaginary(Imaginary) {}
ComplexNumber::ComplexNumber() : Real(0), Imaginary(0) {}
void ComplexNumber::RandomInput() 
{
    float minReal, maxReal, minIm, maxIm;
    cout << "min Real:" << endl;
    cin >> minReal;
    cout << "max Real:" << endl;
    cin >> maxReal;
    cout << "min Imaginary:" << endl;
    cin >> minIm;
    cout << "max Imaginary:" << endl;
    cin >> maxIm;
    this->Real = ((float)rand() / (float)RAND_MAX) * (maxReal-minReal)+minReal;
    this->Imaginary = ((float)rand() / (float)RAND_MAX) * (maxIm - minIm) + minIm;
}
void ComplexNumber::RandomInput(float minReal, float maxReal, float minIm, float  maxIm)
{
    this->Real = ((float)rand()/(float)RAND_MAX)*(maxReal - minReal) + minReal;
    this->Imaginary = ((float)rand() / (float)RAND_MAX)*(maxIm - minIm) + minIm;
}
void ComplexNumber:: Input() 
{
    cout << "Real:" << endl;
    cin >> this->Real;
    cout << "Imaginary:" << endl;
    cin >> this->Imaginary;
}
float ComplexNumber::GetRe() const 
{ 
    return this->Real;
}
float ComplexNumber::GetIm() const 
{ 
    return this->Imaginary;
}
ostream& operator<<(ostream& os, const ComplexNumber& complexNumber)
{
    os << complexNumber.GetRe() << " + " << "i * " << complexNumber.GetIm() << endl;
    return os;
}