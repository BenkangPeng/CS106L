#include"StringVector.hpp"


StringVector readNames(int size, const std::string& str){
    StringVector names(size , str);//default constructor 
    return names;//copy constructor: a return value `names` is constructed by local `name`
    //But compiler will optimize away a copy constructor call by RVO(return value optimization) 
    //We can close it by compiler flag `-fno-elide-constructors`
}

int main(){
    StringVector sv1 = readNames(6 , "Ito");//once call of default constructor + twice call of copy constructor
    // Theoretically, there is a copy constructor call here,
    // which constructs sv1 with return value of `readNames`.
    // But modern C++ compiler always optimizes away a call of copy constructor,
    // initializing directly `sv1` with the temporary object `names`.
    // It's called `copy elision`.
    // Thankfully, we will see this call of copy constructor by flag `-std=c++11`


    std::cout << sv1 << std::endl; 

    std::cout << "---------------" << std::endl;
    StringVector sv2;//default constructor(no allocated memory)
    sv2 = readNames(8, "Avery Wang");//default constructor + copy constructor + copy assignment

    // Can we steal the returned object of `readNames` to sv2, as returned object is 
    // tempoaray and is deleted immediately after copy assignment. 
    // That's why move semantics is arised.

    return 0;
}