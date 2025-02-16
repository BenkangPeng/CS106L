#include<iostream>
#include<thread>
#include<mutex>
#include<vector>

std::mutex mtx;
void greet(int id){
    std::lock_guard<std::mutex> lg(mtx);
    std::cout << "Hello there! My name is " << id << std::endl;
}

int main(){
   std::cout << "Greetings from my threads..." << std::endl;
   
   std::vector<std::thread> threads;
   size_t NumThreads = 10;
   for(size_t i = 0; i < NumThreads; ++i){
        threads.push_back(std::thread(greet, i));
   }

   for(auto& t : threads){
        t.join();
   }

   std::cout << "All greetings done!" << std::endl;

   return 0;
}