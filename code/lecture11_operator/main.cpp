#include<iostream>
#include<vector>
#include<string>
#include"StringVector.hpp"
#include"Fraction.hpp"

int main()
{
    std::vector<std::string> v{"Hello", "World"};

    // how compiler understands "v[1] += "!" : 
    v.operator[](1).operator+=("!");
    // operator[] is the member function of vector class
    // and operator+= is the memver function of string class



    //how compiler understands "std::cout << v[1]":
    operator<<(std::cout, v[1]);//operator<< is free function
    //well, it gets a lots compiler-errors of(std::cout.operator<<(v[1]))

    std::cout << std::endl;


    StringVector StrVec{"Hello" , "World"};
    std::cout << StrVec[0] << " " << StrVec[1] << std::endl;

    StrVec.push_back("CS106L");
    (StrVec += "CS106B") += "Math";
    StrVec += {"English" , "Chem"};

    for(auto& elem : StrVec){
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    StringVector v1{"Hello"};
    StringVector v2{"World"};
    StringVector v3 = v1 + v2;
    for(const auto& elem : v3){
        std::cout << elem << " ";
    }

    Fraction f1{6,7};
    Fraction f2{2,3};
    std::cout << f1 * f2 << std::endl;
}