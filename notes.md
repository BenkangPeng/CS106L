C++ coreguide

C++-ism

All the standard library header files are part of the std namespace.

#### Stream



#### [Usage notes](https://en.cppreference.com/w/cpp/named_req/SequenceContainer)

|                          Container                           |                             Pros                             |                             Cons                             |
| :----------------------------------------------------------: | :----------------------------------------------------------: | :----------------------------------------------------------: |
| [std::vector](https://en.cppreference.com/w/cpp/container/vector) |               Fast access, contiguous storage                |           Mostly inefficient insertions/deletions            |
| [std::inplace_vector](http://en.cppreference.com/w/cpp/container/inplace_vector) |           Fast access, inplace contiguous storage            |  Fixed capacity and mostly inefficient insertions/deletions  |
| [std::array](https://en.cppreference.com/w/cpp/container/array) |           Fast access, inplace contiguous storage            |      Fixed number of elements and no insertion/deletion      |
| [std::deque](https://en.cppreference.com/w/cpp/container/deque) | Fast access, efficient insertion/deletion at the beginning/end | Inefficient insertion/deletion in the **middle** of the sequence |
| [std::list](https://en.cppreference.com/w/cpp/container/list) [std::forward_list](https://en.cppreference.com/w/cpp/container/forward_list) |  Efficient insertion/deletion in the middle of the sequence  |      Access is mostly linear-time(based on linked list)      |

####  Types of `Iterator`

`input/output iterator` , `forward iterator` , `bidirectional iterator`,`random access iterator`. It's the inheritance relationship in sequence.

| **Iterator Type**      | Direction     | Read/Write Capability | Navigation Ability | Typical Containers                  |
| :--------------------- | :------------ | :-------------------- | :----------------- | :---------------------------------- |
| Input Iterator         | Forward Only  | Read-Only             | Only `++`          | `std::istream_iterator`             |
| Output Iterator        | Forward Only  | Write-Only            | Only `++`          | `std::ostream_iterator`             |
| Forward Iterator       | Forward Only  | Read and Write        | Only `++`          | `std::forward_list`                 |
| Bidirectional Iterator | Bidirectional | Read and Write        | `++` and `--`      | `std::list`, `std::set`, `std::map` |
| Random Access Iterator | Arbitrary     | Read and Write        | `++`, `--`, `+n`   | `std::vector`, `std::deque`         |

Only the `Random Access Iterator` supports arbitrary read and write operations. This means that only iterators of `vector` and `deque` can perform operations like `it1 - it2`, `it1 = it1 + 2`, and `c.begin() + c.size()/2`.

#### STL Algorithm

<span style = "color : red; font-size:30px">`std::transform`</span>



std::range::views::filter



#### Template

模板函数可以不需要显示传入参数，可以自行隐式推断：

```cpp
template <typename Collection , typename DataType>
int countOccurences(const Collection& c, DataType value) {
    int count = 0;
    for (auto it = c.begin() ; it != c.end(); ++it) {
        if (*it == value) {
            ++count;
        }
    }
    return count;
}

int main(){
    std::list<int> L{1,2,3,3,4,5};
    std::cout << countOccurences<std::list<int> , int>(L, 3) << std::endl;
    
    //The compiler literally replaces each template 
    //parameter with whatever you instantiate it with
    std::cout << countOccurences(L, 3) << std::endl;//infer the template parameters
}
```



```cpp
template<typename It , typename DataType , typename AUTO>
int countOccurences(It begin , It end , DataType value ,  AUTO predicate){
    int count = 0;
    for(auto it = begin ; it != end ; ++it){
        if(predicate(*it)){
            ++count;
        }
    }
    return count;

}
int main(){
    std::vector<int> v = {1,2,3,4,5,6};
    int limit = 6;
    //can't write "bool predicate = ..." , as predicate is not a true function(lambda class actually)
    // and return-value is also not boolean.
    // So, it common to use auto as lambda's return type.
    auto predicate = [limit](auto i){return i < limit;};
    //Lucky, you can use auto in lambda functions' parameter list
    std::cout << countOccurences(v.begin() , v.end() , 2 , predicate) << std::endl;
}
```

#### Constructor function initializer list

Two ways to initialize variables of a class:

```cpp
class MyClass {
public:
    int x;
    double y;
    std::string name;

    // 1st way
  	MyClass(int a , double b, const std::string& _name){
        x = a;
        y = b;
        name = _name;
    }
    // 2nd way, using initialize list
    MyClass(int a, double b, std::string _name) : x(a), y(b), name(_name) {}
};
```

For non-primitive types(like self-defined class or std::string), using initialization list can avoid unnecessary overhead in constructor function:

* While using initialization list, `name` is initialized `directly` through the `copy constructor`.
* While not using initialization list , there are 2 steps to initialize variables:
  * `Step 1`: The member variable is default-constructed with a random value.
  * `Step 2`: The assignment operator(`operator=`) is called to assign value to the member variable.

So, it's more effient to use initialization list in constructor function.

==Attention==

* `Constant member variables` and `reference variable` must be initialized by initialization list in constructor.

```cpp
class MyClass {
public:
    const int value;
    int& w;

    MyClass(int v, int& w) : value(v), w(w) {}
};
```

It makes sense that you can't reassign a new value to `value` after construction cause `value` is a constant variable.

* The order of Variable assignment in initialization list should be same as declaration of variable .



#### Special member functions

**Special member functions are (usually) automatically generated by the `compiler`.**

* `Default construction`: object created with `no parameters`.
* `Copy construction`: object is created as a copy of an existing object.
* `Copy assighnment`: existing object replaced as a copy of another existing object.
* `Destruction`: object destroyed when it is out of scope.



#### Shallow Copy

* If `copy constructor` isn't customized in a class, the compiler will generate a default copy constructor for this class.

  [Run](https://ideone.com/vtVAdZ)

```cpp
#include <iostream>

class MyClass {
public:
    int* data;

    // Constructor
    MyClass(int value) {
        data = new int(value); // Dynamically allocate memory
    }
    
    /*default copy constructor
    MyClass(const MyClass& other){
        data = other.data;//simple assignment
    }
    */
    /*default assignment operator=
    MyClass& operator=(const MyClass& other){
    	*this = other;
    	return this;
    }
    */

    // Destructor
    ~MyClass() {
        delete data; // Free the allocated memory
    }
};

int main() {
    MyClass obj1(42);
    MyClass obj2 = obj1; // Shallow copy (default copy constructor)
    MyClass obj3(66);
    obj3 = obj2;// default assignment with shallow copy

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
```

Result:

* Data of `obj1` and `obj3` is also modified when we just modified `obj2`, because the data pointer of `obj1` and `obj3` is just pointing to the same address of `obj2` and doesn't allocate independent memory. 
* For the primitive types(like `int`,`double`) and types in `STL` , there is no difference between `deep copy` and `shallow copy`, which means they always do `deep copy`.
* Example above also throwed a run-time error of `double free memory` : When `obj1`,`obj2`,`obj3` leave the scope of `main` function, they will free the memory of `data` repeatly.
* It's worth noting that `MyClass obj2 = obj1;` actually calles the `copy constructor` (equal to `MyClass obj2(obj1);`) , and `obj3 = obj2` calles the `operator=`.

**How to implement the copy constructor and assignment with deep copy**: 

[run](https://ideone.com/7tExBf)

```cpp
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
```



#### push_back and emplace_back

`related code ` : [emplace_back.cpp](./code/lecture13_move-semantics/emplace_back.cpp)  [full code](https://coliru.stacked-crooked.com/a/5f8b6bc6dcf4cdf0)



If we push_back a object into a vector, how many times are the constructor called ?

```cpp
std::vector<President> reElections;
President Trump("Donald John Trump" , "The USA" , 2025);
reElections.push_back(Trump);
```

* The code firstly called struct `President`'s `constructor` to initialize object `Trump`, then passed `Trump` into function `push_back(const T& value)` as a parameter, <del>which means it needs a copy(Formal parameters are copies of actual parameters.). </del>  **Copy isn't needed when passing parameters by reference(right reference).**
* In scope of `push_back`, the formal parameter `Trump` was placed in the end of `reElections` by `copy constructor`.

```cpp
// copy constructor
    President(const President& other)
        : name(other.name), country(other.country), year(other.year){
        std::cout << "copy constructor is called.\n";    
    }
```

> Result : constructor 1 time + copy constructor 1 time



There are 2 templates of `push_back`:

```cpp
void push_back(const T& lvalue);

void push_back(T&& rvalue);
```

**Two Types of reference**

* An `I-value` is an expression that has a name (`identity`).
  can find address using address-of operator(&var)
* An `r-value` is an expresion that does not have a name (`identity`).
  temporary values and `cannot` `find address` using address-of operator (&var)

You can steal from `rvalue` but can't from `lvalue`.



```cpp
std::cout << "Biden: " << std::endl;
President Biden("Joseph Robinette Biden Jr." , "The USA" , 2020);
elections.push_back(std::move(Biden));
std::cout << "The object Biden isn't existed: " << Biden.name <<Biden.country << Biden.year << std::endl;
```

The code above used `push_back`'s template `void push_back(T&& rvalue)` :

* The rvalue of `Biden` is returned by `std::move(Biden)`
* In the scope of `void push_back(T&& rvalue)` , `Biden`'s resources(`name`,`country`and `year`) are moved to `elections.end()` by `move constructor`. Then `name` and `country` can't be access by syntax `Biden.name` and `Biden.country`, while `Biden.year` is accessible as primitive types' move semantics act the same as `deep copy`.

```cpp
// move constructor
    President(President&& other)
        : name(std::move(other.name)), country(std::move(other.country)), year(other.year){
        std::cout << "I am being moved.\n";
        // The object other is deleted when leaving the scope. 
    }
```

> Result: constructor 1 time + move constructor 1 time

:triangular_flag_on_post:[run code](https://coliru.stacked-crooked.com/a/4dc5a098e6bdefab)

We can also pass the `rvalue` into `push_back(T&& rvalue)` directly without `std::move` .

```cpp
elections.push_back(President("Joseph Robinette Biden Jr." , "The USA" , 2020);
```

At the same time, you can further use `emplace_back` to save a call of `copy constructor` or `move constructor`.`emplace_back` only need to do construction once in the memory location corresponding to the container.

```cpp
std::vector<President> elections;
std::cout << "emplace_back:\n";
auto& ref = elections.emplace_back("Nelson Mandela", "South Africa", 1994);
    //emplace_back construct an element in-place at the end of container,
    //which avoids unnecessary copies by directly constructing the object inside the container's memory.
assert(ref.year == 1994 && "uses a reference to the created object (C++17)");
```

**If the move constructor of class isn't defined, `void push_back(T&& rvalue)` will call `construcor`(or default constructor).**



==**Practical Takeaway**==

* Use `move constructor`(if existed) instead of `copy constructor`, while `move constructor ` has better performance.

```cpp
President Biden("Joseph Robinette Biden Jr." , "The USA" , 2020);
elections.push_back(Biden);
```

**Modified to**

```cpp
President Biden("Joseph Robinette Biden Jr." , "The USA" , 2020);
elections.push_back(std::move(Biden));

//Or
elections.push_back(President("Joseph Robinette Biden Jr." , "The USA" , 2020));
```



* Save a call of `copy construction` or `move construction`

```cpp
President Biden("Joseph Robinette Biden Jr." , "The USA" , 2020);
elections.push_back(std::move(Biden));
//If the class President only has the constructor without move constructor, the code above is same as : elections.push_back(Biden);
```

**Modified to**

```cpp
elections.emplace_back("Joseph Robinette Biden Jr." , "The USA" , 2020);
```



#### Move semantics







#### Virtual Function

**Key Differences**

| Feature                       | Pure Virtual Function               | Non-Pure Virtual Function               |
| ----------------------------- | ----------------------------------- | --------------------------------------- |
| **Declaration**               | `virtual void func() = 0;`          | `virtual void func();`                  |
| **Abstract Class**            | Makes the class abstract            | Does not make the class abstract        |
| **Instantiation**             | Cannot instantiate the base class   | Can instantiate the base class          |
| **Implementation**            | No implementation in the base class | May have a default implementation       |
| **Derived Class Requirement** | Must override in derived classes    | Optional to override in derived classes |
| **Purpose**                   | Defines an interface                | Provides reusable default behavior      |

==Pure Virtual Function==

1. **Abstract Class** :
   - A class containing at least one pure virtual function becomes an **abstract class** .
   - You cannot instantiate an abstract class directly (i.e., you cannot create objects of the class).
2. **No Implementation** :
   - A pure virtual function does not provide any implementation in the base class.
   - Derived classes **must override** the pure virtual function to provide their own implementation.
3. **Purpose** :
   - Used to define an interface or a contract for derived classes.
   - Forces derived classes to implement specific behavior.

==Non Pure Virtual Function==

**Definition** :

- A non-pure virtual function is declared with the `virtual` keyword but does not include `= 0`.
- It may or may not have a default implementation in the base class.

1. **Default Implementation** :
   - A non-pure virtual function can provide a default implementation in the base class.
   - Derived classes can inherit this implementation or override it if needed.
2. **Instantiation** :
   - A class with non-pure virtual functions is **not abstract** and can be instantiated directly.
3. **Purpose** :
   - Provides a default behavior that derived classes can reuse or customize.

#### Assignment 7

When we operate the raw pointer, it would be better to check whether the raw pointer is `nullptr` or not.

```cpp
if(data){
    return *data;
}
else{
    throw std::runtime_error("cann't access the content of nullptr")
}

if(data){
    delete data;
}
```

For `copy assignment` and `move assignment` in the custom class, it's necessary to check `self-assignment`.

```cpp
unique_ptr<T>& operator=(unique_ptr<T>&& other){

    if(this == &other)  return *this;
    delete data;
    data = other.data;
    other.data = nullptr;
    return *this;
}
```

It's amazing to create the list in reverse order !!!

```cpp
template <typename T> cs106l::unique_ptr<ListNode<T>> create_list(const std::vector<T>& values) {
  /* STUDENT TODO: Implement this method */
  // throw std::runtime_error("Not implemented: createList");

  cs106l::unique_ptr<ListNode<T>> head = nullptr;

    // Iterate over the vector in reverse order
    for (auto it = values.rbegin(); it != values.rend(); ++it) {
        // Create a new node with the current value and the current head as its next pointer
        cs106l::unique_ptr<ListNode<T>> node = cs106l::make_unique<ListNode<T>>(*it);
        node->next = std::move(head);
        head = std::move(node);
    }

    // Return the head of the list
    return head;
}
```

<big>All in all, `assign-7` is worth doing again. :`)</big>



