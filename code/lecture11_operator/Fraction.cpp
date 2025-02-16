#include"Fraction.hpp"

Fraction::Fraction(const std::initializer_list<int>& L){
        if(L.size() != 2){
            throw std::domain_error("false initializer_list size");
        }
        if(*(L.begin() + 1) == 0){
            throw std::domain_error("denominator can't be 0");
        }
        auto it = L.begin();
        numerator = *it;
        denominator = *(it + 1); 
}

Fraction::Fraction(int num, int denom): numerator(num), denominator(denom){}

//for binary operator equally treats lhs and rhs, overload operator as a non-member function
Fraction operator*(const Fraction& f1 , const Fraction& f2){
    return Fraction{f1.numerator*f2.numerator , f1.denominator*f2.denominator};
}

// overload operator<< as a non-member function instead of overloading ostream's member func operator<<
std::ostream& operator<<(std::ostream& os , const Fraction& f){
    os << f.numerator << "/" << f.denominator;
    return os;
}