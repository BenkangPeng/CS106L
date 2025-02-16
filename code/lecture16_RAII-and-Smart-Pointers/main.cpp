// RAII: Resource Acquisition Is Initialization
// CADRE: Constructor Acquires, Destructor REleases

#include<fstream>
#include<string>
#include<iostream>

int main(){
    std::ifstream input("data.txt");

    std::string line;
    while(std::getline(input, line)){
        std::cout << line << std::endl;
    }

    // input.close(); //It's unnecessary to write this line
    // But if you write input.open("data.txt"); before, it needs `close()` here.

    //Actually, you isn't allowed to write something like `new`&`delete`, `open`&`close`
    // and `lock`&`unlock`......
    return 0;
}