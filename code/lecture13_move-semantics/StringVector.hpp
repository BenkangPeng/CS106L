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
    StringVector(int AllocSize, const std::string& str);
    StringVector();

    StringVector(const std::initializer_list<std::string>& StrVec);

    // copy constructor
    StringVector(const StringVector& other);

    //copy assignment
    StringVector& operator=(const StringVector& other);

    // move constructor
    StringVector(StringVector&& other);

    // move assignment
    StringVector& operator=(StringVector&& rhs);

    // destructor
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


};

template<typename T>
void swap(T& a, T& b){
    T tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}