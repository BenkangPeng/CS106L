#include"StringVector.hpp"
#include<vector>

StringVector::StringVector(int AllocSize):AllocSize(AllocSize)
                            ,elems(new std::string[AllocSize]){}

StringVector::StringVector():AllocSize(0),elems(nullptr){}

StringVector::StringVector(const std::initializer_list<std::string>& StrVec): AllocSize(StrVec.size()){
    elems = new std::string[AllocSize];
    std::copy(StrVec.begin() , StrVec.end() , begin());
}

StringVector::StringVector(const StringVector& other):AllocSize(other.AllocSize){
    
    elems = new std::string[AllocSize];
    std::copy(other.begin() , other.end() , begin());
}

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

    if(elems){
        delete[] elems;
    }
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

    if(elems){
        delete[] elems;
    }
    elems = new_elems;
    ++AllocSize;

    return *this;
}

StringVector operator+(const StringVector& lhs, const StringVector& rhs){
    StringVector result(lhs);
    result += rhs;

    return result;
}

StringVector& StringVector::operator=(const StringVector& other){
    if(this == &other){
        return *this;
    }

    if(elems){
        delete[] elems;
    }
    elems = new std::string[other.AllocSize];
    AllocSize = other.AllocSize;
    std::copy(other.begin(), other.end(), elems);

    return *this;
}
