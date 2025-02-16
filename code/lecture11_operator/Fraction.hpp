#pragma once
#include<iostream>
#include<initializer_list>
class Fraction{
private:
    int numerator;
    int denominator;

    // use friend func to access the private variable
    friend Fraction operator*(const Fraction& f1 , const Fraction& f2);
    friend std::ostream& operator<<(std::ostream& os , const Fraction& f);

public:
    Fraction(const std::initializer_list<int>& L);
    Fraction(int num, int denom);
}; 

