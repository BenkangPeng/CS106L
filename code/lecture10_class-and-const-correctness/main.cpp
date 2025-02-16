#include<iostream>
#include<vector>
int main(){
    int a = 1;
    int * const p = &a;//const pointer to a non-const int

    (*p)++; //Allow
    // p++; // not allow
    std::cout << *p << std::endl;

    const int *q = &a;//non-const pointer to a const int
    int const *r = &a;//non-const pointer to a const int
    // ++(*q);//Not allow
    int b = 6;
    r = &b;//modify address non-const pointer points to
    std::cout << *r << std::endl;

    const int * const i = &a;//const pointer to a const int
    int const * const j = &b;//const pointer to a const int
    // (*i)++;//not allow
    // j = &a;//not allow


    //const iterator
    std::vector<int> vec{1,2,3};
    const std::vector<int>::iterator itr = vec.begin();
    // itr++;//don't compiler
    (*itr)++;//allow
    std::cout << *itr << std::endl;

    std::vector<int>::const_iterator citr = vec.begin() + 1;
    citr++;//allow
    // (*citr)++;//don't allow
    std::cout << *citr << std::endl;

    return 0;
}