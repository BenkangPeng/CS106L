#include<iostream>
#include<vector>

template<typename It, typename UnaryPred>
int countOccurences(It begin , It end, UnaryPred predicate){
    int count = 0;
    for(auto it = begin ; it != end ; ++it){
        if(predicate(*it)){
            ++count;
        }
    }
    return count;

}

bool LessThan4(int x){
    return x < 4;
}
int main(){
    std::vector<int> v = {1,2,3,4,5,6};
    int limit = 4;
    //can't write "bool predicate" , as predicate is not a function(lambda class actually)
    // and return-value is also not boolean.
    // So, it common to use auto as lambda's return type.
    auto predicate = [limit](auto i){return i < limit;};
    //Lucky, you can use auto in lambda functions' parameter list
    std::cout << countOccurences(v.begin() , v.end() , predicate) << std::endl;
    std::cout << countOccurences(v.begin() , v.end() , LessThan4/*function pointer*/) << std::endl;
}