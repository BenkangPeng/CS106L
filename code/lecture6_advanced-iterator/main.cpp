#include<map>
#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::string;

std::map<string , int> GetUserWords();

int main(){
    std::map<string , int> freqMap;
    freqMap = GetUserWords();

    std::map<string , int>::iterator it = freqMap.begin();
    while(it != freqMap.end()){
       cout << it->first << ", " << it->second << std::endl;
    //    cout << (*it).first << ", " << (*it).second << std::endl;
       ++it;
    }

    // or, use structure binding
    
    cout << "*********structure binding***********" << std::endl;
    for(auto [key , value] : freqMap){
        cout << key << ", " << value << std::endl;
    }


    
    return 0;
}

std::map<string , int> GetUserWords(){
    std::map<string , int> m;
    cout << "input the word: " << std::endl;

    while(true){
        string line;
        cout << ">";
        std::getline(cin , line);
        if(line.empty()){
            return m;
        }
        ++m[line];

    }
}