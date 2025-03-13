//Actually, you isn't allowed to write something like `new`&`delete`, `open`&`close`
// and `lock`&`unlock` :'(

#include<iostream>
#include<memory>
struct Node{
    int data;
    std::unique_ptr<Node> next;
    Node(int _data): data(_data), next(nullptr){}
};
int main(){
    // Node* N1 = new Node(6);
    std::unique_ptr<Node> N1 = std::make_unique<Node>(6);
    std::cout << N1->data << std::endl;

    // delete N1;
    // N1 is deleted out of scope by its destructor.

    std::shared_ptr<Node> N2 = std::make_shared<Node>(8);
    {
        //shared_ptr is implemented by reference count
        //reference count of shared_ptr = 1
        std::shared_ptr<Node> N3(N2);//shallow copy
        //reference count of shared_ptr = 2
        
        N3->data = 14;
    }
    //reference count = 1
    // N3 won't deleted here, as the reference count isn't equal to 0

    std::cout << N2->data << std::endl;
    //std::weak_ptr can share the memory but won't increase the reference count.
    return 0;

    //N2 is deleted out the scope of main func
}     