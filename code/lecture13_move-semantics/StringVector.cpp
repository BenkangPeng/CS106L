#include"StringVector.hpp"
#include<vector>

//default constructor
StringVector::StringVector(int AllocSize):AllocSize(AllocSize)
                            ,elems(new std::string[AllocSize]){

    std::cout << "default constructor(filled) is called." << std::endl;                            
}

StringVector::StringVector(int AllocSize, const std::string& str):AllocSize(AllocSize)
                            ,elems(new std::string[AllocSize]()){
    elems[0] = str;
    std::cout << "default constructor(filled a str) is called." << std::endl;                            
}

StringVector::StringVector():AllocSize(0),elems(nullptr){
    std::cout << "default constructor(not allocate memory) is called." << std::endl;
}

StringVector::StringVector(const std::initializer_list<std::string>& StrVec): AllocSize(StrVec.size()){
    elems = new std::string[AllocSize];
    std::copy(StrVec.begin() , StrVec.end() , begin());
    std::cout << "default constructor(by initializer_list) is called." << std::endl;                            
}

//copy constructor
StringVector::StringVector(const StringVector& other):AllocSize(other.AllocSize){
    
    elems = new std::string[AllocSize];
    std::copy(other.begin() , other.end() , begin());
    std::cout << "copy constructor is called." << std::endl;                            
}

//copy assignment
StringVector& StringVector::operator=(const StringVector& other){
    if(this == &other){
        return *this;
    }

    if(AllocSize > 0){
        delete[] elems;
    }
    elems = new std::string[other.AllocSize];
    AllocSize = other.AllocSize;
    std::copy(other.begin(), other.end(), elems);
    std::cout << "copy assignment is called." << std::endl;

    return *this;
}


// move constructor
StringVector::StringVector(StringVector&& other):
            AllocSize(other.AllocSize), elems(std::move(other.elems)){
    
    std::cout << "move constructor is called." << std::endl;
    other.elems = nullptr;//must set to nullpty otherwise its destructor will delete 
    //other.elems and rise a segmentation fault
}
// move assignment
StringVector& StringVector::operator=(StringVector&& rhs){

    if(this == &rhs){
        return *this;
    }

    if(elems){
        delete [] elems;
    }

    elems = std::move(rhs.elems);//rhs.elems is a lvalue, and std::move turns it into rvalue
    AllocSize = rhs.AllocSize;
    rhs.elems = nullptr;
    std::cout << "move assignment is called." << std::endl;
    return *this;
}

//destructor
StringVector::~StringVector(){
    if(elems){
        delete[] elems;
    }
}


StringVector::iterator StringVector::begin(){
    return elems;
}
StringVector::iterator StringVector::end(){
    return elems + AllocSize;
}

StringVector::const_iterator StringVector::begin() const{
    return elems;
}
StringVector::const_iterator StringVector::end() const{
    return elems + AllocSize;
}


//operator overloading
std::ostream& operator<<(std::ostream& os , const StringVector& sv){
    for(int i = 0 ; i < sv.AllocSize ; ++i){
        os << sv.elems[i] << " ";
    }

    return os;
}

StringVector& StringVector::operator+=(const StringVector& other){

    if(other.AllocSize == 0)    return *this;

    std::string* new_elems = new std::string[AllocSize + other.AllocSize];
    for(int i = 0 ; i < AllocSize ; ++i){
        new_elems[i] = elems[i];//copy old values
    }

    for(int i = AllocSize ; i < AllocSize + other.AllocSize; ++i){
        new_elems[i] = other.elems[i - AllocSize];
    }

    delete[] elems;
    elems = new_elems;
    AllocSize += other.AllocSize;

    return *this;
}

StringVector& StringVector::operator+=(const std::string& str){
    std::string* new_elems = new std::string[AllocSize+1];
    for(int i = 0; i < AllocSize; ++i){
        new_elems[i] = elems[i];
    }
    new_elems[AllocSize] = str;

    delete[] elems;
    elems = new_elems;
    ++AllocSize;

    return *this;
}

StringVector operator+(const StringVector& lhs, const StringVector& rhs){
    StringVector result(lhs);
    result += rhs;

    return result;
}

