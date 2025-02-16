#include<iostream>
#include<vector>
#include<deque>
#include<chrono>
void vec_push_back();
void deque_push_back();

int main()
{
    auto start1 = std::chrono::high_resolution_clock::now();
    vec_push_back();
    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end1-start1);


    auto start2 = std::chrono::high_resolution_clock::now();
    deque_push_back();
    auto end2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2-start2);

    std::cout << duration1.count() << "   "  << duration2.count() << std::endl;

    return 0; 
}

void vec_push_back(){
    std::vector<int> vec;
    for(int i = 0 ; i < 1000000 ; ++i){
        vec.push_back(i+99959);
    }
}

void deque_push_back(){
    std::deque<int> deq;
    for(int i = 0 ; i < 1000000 ; ++i){
        deq.push_back(i+99959);
    }
}