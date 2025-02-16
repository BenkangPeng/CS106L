#include<iostream>
#include<vector>

template <typename It , typename Type>
    requires std::input_iterator<It> && 
         std::equality_comparable_with<std::iter_value_t<It>, Type>
int countOccurences(It begin, It end, Type val) {
    int count = 0;
    for (auto it = begin ; it != end; ++it) {
        if (*it == val) {
            ++count;
        }
    }
    return count;
}


int main(){
    // We have writen the templated function above in lecture7.
    // But it still raise some bugs as its implicit interface:
    // 1. Iterator must have the operations like *it, ++it, it != end
    
    std::vector<double> vec = {1.0, 2.1, 3.14, 4};
    std::cout << countOccurences(vec.begin(), vec.end(), 3.14) << std::endl;

    return 0;
}
