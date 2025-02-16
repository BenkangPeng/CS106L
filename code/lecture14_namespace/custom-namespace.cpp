#include<iostream>
#include<vector>
#include<algorithm>
using std::vector;
using std::cout;
using std::endl;

namespace Lecture{
    int count(const vector<int>& v , int val){
        int ctr = 0;
        for(auto& elem : v){
            if(elem == val){
                ++ctr;
            }
        }

        cout << "Lecture::count is called." << endl;
        return ctr;
    }
}

int main(){
    vector v1{1,2,3,4,5,1};
    int count = 0;
    for(auto& elem : v1){
        if(elem == 1){
            ++count;
        }
    }

    cout << "Mannual count: " << count << endl;

    cout << "Call function" << Lecture::count(v1, 1) << endl;

}