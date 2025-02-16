
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector v1{1,2,3,4,5,1};
    int count = 0;
    for(auto& elem : v1){
        if(elem == 1){
            ++count;
        }
    }

    cout << "Mannual count: " << count << endl;

    // billion lines later...

    // I want to use std::count
    // I have declared that `using namespace std`, but why the compiler assumes that
    // the `count` is a integer variable instead of the function `std::count`?
    cout << count(v1.begin(), v1.end() , 1) << endl;
    /*
    error: 'count' cannot be used as a function
   22 |     cout << count(v1.begin(), v1.end() , 1) << endl;
      |             ~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~
    */ 

   // So, it would be better not to declare `using namespace std`.
   // better to: using std::vector or using std::count

    return 0;
}