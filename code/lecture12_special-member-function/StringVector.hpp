#pragma once
#include<initializer_list>
#include<string>
#include<iostream>
class StringVector{

private:
    int AllocSize;
    std::string *elems;

public:

    //constructor
    StringVector(int AllocSize);
    StringVector();

    StringVector(const std::initializer_list<std::string>& StrVec);

    // copy construction
    StringVector(const StringVector& other);

    ~StringVector();


    //Iterator
    using iterator = std::string*;
    using const_iterator = const std::string*;
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    //operator overloading
    friend std::ostream& operator<<(std::ostream& os , const StringVector& sv);
    friend StringVector operator+(const StringVector& lhs, const StringVector& rhs);

    StringVector& operator+=(const StringVector& other);
    StringVector& operator+=(const std::string& str);
    StringVector& operator=(const StringVector& other);

};
