#include"StringVector.hpp"

int main(){

    StringVector sv1{"Hello" , "World"};

    StringVector sv2(sv1);//equal to: StringVecotr sv2 = sv1;
    sv2 += "CS106L";

    StringVector sv3 = sv1 + sv2;

    StringVector sv4;
    sv4 = sv3;

    sv4 += "CSE234";

    std::cout << sv4 << std::endl;
}