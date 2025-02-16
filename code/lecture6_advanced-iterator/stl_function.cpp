#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>

using std::cout;
using std::cin;
using std::vector;


void printVec(const vector<int> &vec){
    for(auto elem : vec){
        cout << elem << " ";
    }
    cout << std::endl; 
}
int main(){
    vector<int> vec{3,1,4,1,5,9,2,6};
    std::sort(vec.begin() , vec.end());
    printVec(vec); 

    std::set<int> elems{3,1,4,1,5,9,2,6};
    std::cout << "SET SIZE: " << elems.size() << std::endl;
    const int ELEM_TO_FIND = 5;

    auto testit = std::find(elems.begin() , elems.end() , ELEM_TO_FIND);
    if(testit != elems.end()){
        std::cout << "Found " << *testit << std::endl; 
    }
    else{
        std::cout << "Not Found! " << std::endl;
    }

    auto lower_bound = std::lower_bound(elems.begin() , elems.end() , 4);//first elem >= 6
    auto upper_bound = std::upper_bound(elems.begin() , elems.end() , 6);//last elem <= 6

    std::cout << "start: " << *lower_bound << " end: " << *upper_bound << std::endl;
    for(; lower_bound != upper_bound ; ++lower_bound){
        std::cout << *lower_bound << " ";
    }

    

}