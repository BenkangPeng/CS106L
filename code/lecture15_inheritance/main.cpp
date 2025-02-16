
#include<iostream>
#include<string>
class Drink{
private:
    std::string flavor;
public:
    Drink() = default;
    Drink(const std::string& _flavor): flavor(_flavor){}

    virtual void make(){
        std::cout << "Make tea from Drink class" << std::endl;
    }

    virtual ~Drink(){}//must set the destructor of base class into a virtual function
};

class Tea : public Drink{
public:
    Tea() = default;
    Tea(const std::string& _flavor): Drink(_flavor){}

    void make()override{
        std::cout << "Make a tea from Tea class" << std::endl;
    }
    
    ~Tea() = default;
};

int main(){
    Tea t("Red");
    t.make();
    t.Drink::make();
}