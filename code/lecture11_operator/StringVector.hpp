#pragma once
#include<vector>
#include<string>
class StringVector : public std::vector<std::string>{

public:

    using std::vector<std::string>::vector;//use vector<string>'s construct function

    StringVector& operator+=(const std::string& str);
    StringVector& operator+=(const std::vector<std::string>& other);

    StringVector& operator+=(const std::initializer_list<std::string>& other);
        
    // StringVector operator+(const StringVector& other)const {
    //     StringVector result = *this;
    //     result += other;
    //     return result;
    // }


};
StringVector operator+(const StringVector& lhs , const StringVector& rhs);
