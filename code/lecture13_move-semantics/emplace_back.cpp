#include <vector>
#include <cassert>
#include <iostream>
#include <string>
 
struct President
{
    std::string name;
    std::string country;
    int year;
 
    President(std::string p_name, std::string p_country, int p_year)
        : name(std::move(p_name)), country(std::move(p_country)), year(p_year)
    {
        std::cout << "I am being constructed.\n";
    }
 
    // move constructor
    President(President&& other)
        : name(std::move(other.name)), country(std::move(other.country)), year(other.year)
    {
        std::cout << "I am being moved.\n";
    }

    // copy constructor
    President(const President& other)
        : name(other.name), country(other.country), year(other.year){
        std::cout << "copy constructor is called.\n";    
    }
 
    President& operator=(const President& other) = default;
};
 
int main()
{
    std::vector<President> elections;
    std::cout << "emplace_back:\n";
    auto& ref = elections.emplace_back("Nelson Mandela", "South Africa", 1994);
    //emplace_back construct an element in-place at the end of container,
    //which avoids unnecessary copies by directly constructing the object inside the container's memory
    assert(ref.year == 1994 && "uses a reference to the created object (C++17)");
 
    std::vector<President> reElections;
    std::cout << "\npush_back:\n";
    
    // reElections.push_back(President("Franklin Delano Roosevelt", "the USA", 1936));
    //Firstly, call President's constructor to construct a temporary President object
    //Secondly, pass this object(a rvalue) into push_back(T&& value)
    //Thirdly, call President's move constructor to move the object into reElections
    // push_back will prefer move constructor than copy constructor

    President Trump("Donald John Trump" , "The USA" , 2025);
    reElections.push_back(Trump);
    std::cout << "Object Trump has been moved: " << Trump.name << std::endl;
 
    std::cout << "\nContents:\n";
    for (President const& president: elections)
        std::cout << president.name << " was elected president of "
                  << president.country << " in " << president.year << ".\n";
 
    for (President const& president: reElections)
        std::cout << president.name << " was re-elected president of "
                  << president.country << " in " << president.year << ".\n";
}