#include<iostream>
class base{

public:
    virtual void pureFunc() = 0;//derived must implement `pureFunc`
    virtual void nonPureFunc(){//derived can override or not
        std::cout << "Base class default implementation" << std::endl;
    }
};

class derived: base{
public:
    void pureFunc()override{
        std::cout << "Derived class implementation of pureFunc" << std::endl;
    }

    void nonPureFunc()override{
        std::cout << "Derived class implementation of nonPureFunc" << std::endl;
    }
};

int main(){
    derived d1;
    d1.pureFunc();
    d1.nonPureFunc();
}