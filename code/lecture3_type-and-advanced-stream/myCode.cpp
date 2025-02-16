#include<iostream>
#include<string>
#include<vector>
#include<utility>//for pair
#include<tuple>
int main()
{
    auto str = "abc"; // str is referred to a C string(const char *)
    auto str2 = std::string("abc");//str is referred to a C++ string

    auto vec3 = std::vector(2,5);// {5,5} use the construct function
    auto vec4 = std::vector{2,5};// {2,5} use initial list to construct
    
    auto prices = std::make_pair(3, 1.5);
    std::cout << prices.first << ' ' << prices.second << std::endl;
    
    auto values = std::make_tuple(3 , 1.5 , "hi");
    std::cout << std::get<0>(values) << ' ' << std::get<1>(values) << ' ' << std::get<2>(values) << std::endl;

    //structure binding C++17 new features , extract each component
    //useful for returning multiple values in functions
    auto [a , b] = prices;
    auto [x, y, z] = values;
    std::cout << a << ' ' << b << std::endl;
    std::cout << x << ' ' << y << ' ' << z << std::endl;
}