#include <iostream>

class MyClass {
public:
    int* data;

    // Constructor
    MyClass(int value) {
        data = new int(value); // Dynamically allocate memory
    }
    /*default copy constructor
    MyClass(const Myclass& other){
        data = other.data;//simple assignment
    }

    */
   /*default assignment operator=
    MyClass& operator=(const MyClass& other){
    	*this = other;
    	return this;
    }
    */
    //copy constructor, deep copy
    MyClass(const MyClass& other){
        data = new int(*other.data);
    }

    MyClass& operator=(const MyClass& other){
        if(this != &other){
            delete data;
            data = new int(*other.data);
        }

        return *this;
    }

    // Destructor
    ~MyClass() {
        delete data; // Free the allocated memory
    }
};

int main() {
    MyClass obj1(42);
    MyClass obj2 = obj1; 
    MyClass obj3(66);
    obj3 = obj2;

    std::cout << "obj1 data: " << *obj1.data << std::endl;
    std::cout << "obj2 data: " << *obj2.data << std::endl;
    std::cout << "obj3 data: " << *obj3.data << std::endl;

    *obj2.data = 100; // Modify obj2's data

    std::cout << "After modification:" << std::endl;
    std::cout << "obj1 data: " << *obj1.data << std::endl;
    std::cout << "obj2 data: " << *obj2.data << std::endl;
    std::cout << "obj3 data: " << *obj3.data << std::endl;

    return 0;
}