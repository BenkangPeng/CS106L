#include<iostream>
#include<list>
#include<vector>
#include<deque>

/* bad code , as not every container is indexable(like std::list) and has .size() method(like stack)
template <typename Collection , typename DataType>
int countOccurences(const Collection& c, DataType value) {
    int count = 0;
    for (size_t i = 0; i < c.size(); ++i) {
        if (c[i] == value) {
            ++count;
        }
    }
    return count;
}
*/

// use iterator as a uniform interface
template <typename Collection , typename DataType>
int countOccurences(const Collection& c, DataType value) {
    int count = 0;
    for (auto it = c.begin() ; it != c.end(); ++it) {
        if (*it == value) {
            ++count;
        }
    }
    return count;
}

int main(){
    std::list<int> L{1,2,3,3,4,5};
    std::cout << countOccurences<std::list<int> , int>(L, 3) << std::endl;

    //The compiler literally replaces each template 
    //parameter with whatever you instantiate it with
    std::cout << countOccurences(L, 3) << std::endl;//infer the template parameters

    // std::vector<int> V{1,2,3,3,4,5};
    // std::cout << countOccurences(V, 3) << std::endl;

    std::deque<char> D{'a','b','c','c','c','d','e'};
    std::cout << countOccurences(D, 'c') << std::endl;
}