#include<iostream>
#include<list>
#include<vector>
#include<forward_list>
#include<algorithm>

int main(){
    std::forward_list<int> f_list{3,1,4,1,5};
    auto forward_it = f_list.begin();
    ++forward_it;
    // --forward_it;//can't decrease
    // auto plus = forward_it - 1;//error

    std::list<int> L{3,1,4,1,5};
    auto bidirectional_it = L.begin();
    ++bidirectional_it;
    --bidirectional_it;
    // auto plus2 = bidirectional_it + 2;//invalid, can't be random accessed
    // std::sort(L.begin() , L.end());//invalid, parameters must be RandomAccessIterator

    std::vector<int> vec{3,1,4,1,5};
    auto random_access_it = vec.begin();
    ++random_access_it;
    --random_access_it;
    int elem3 = random_access_it[2];
    auto plus3 = random_access_it + 3;
    int distance = plus3 - random_access_it;
    std::sort(vec.begin() , vec.end());//std::sort needs RandomAccessIterator as parameters
    //So, std::sort just for std::vector and std::deque
    std::cout << "plus3: " << *plus3 << " distance: " << distance << std::endl;
}