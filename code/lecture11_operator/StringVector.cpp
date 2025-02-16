#include"StringVector.hpp"


StringVector& StringVector::operator+=(const std::string& str){
    push_back(str);
    return *this;//return value is StringVector& , for chain-call
}

StringVector& StringVector::operator+=(const std::vector<std::string>& other){
    for(const auto& elem : other){
        push_back(elem);
    }
    return *this;
}

StringVector& StringVector::operator+=(const std::initializer_list<std::string>& other){
    for(const auto& elem : other){
        push_back(elem);
    }
    return *this;
}

StringVector operator+(const StringVector& lhs , const StringVector& rhs){
    StringVector result = lhs;
    result += rhs;
    return result;
}