#include"StringVector.hpp"

StringVector readNames(int size, const std::string& str){
    StringVector names(size , str);//default constructor 
    return names;//move constructor
}

int main(){
    StringVector sv1 = readNames(6 , "Anna Zeng");
    //default constructor + move constructor + move constructor


    std::cout << sv1 << std::endl; 

    std::cout << "---------------" << std::endl;
    StringVector sv2;//default constructor(no allocated memory)
    sv2 = readNames(8, "Avery Wang");
    //default constructor + copy constructor + move assignment


    swap(sv1 , sv2);
    std::cout << sv1 << std::endl;
    return 0;
}