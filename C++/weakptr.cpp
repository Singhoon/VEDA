#include <iostream>
#include <memory>

using namespace std;

class Node {
public:
    std::weak_ptr<Node> next;
    Node() { std::cout << "Node created\n"; }
    ~Node() { std::cout << "Node destroyed\n"; }
};
int main() {

    shared_ptr<int> ptr1 = make_shared<int>(1);
    weak_ptr<int> ptr2 = ptr1;

    cout << "ptr1.use_count = " << ptr1.use_count() << endl;
    cout << "ptr2.use_count = " << ptr2.use_count() << endl;

    *ptr1 = 100;
    cout << "*ptr : " << *ptr1 << endl;
    cout << "*ptr2 : " << *(ptr2.lock()) << endl;


    /*
    // 둘 다 shared_ptr이면 서로 참조를 하기 때문에 소멸자가 생성이 안됨
    std::shared_ptr<Node> node1 = std::make_shared<Node>();
    std::shared_ptr<Node> node2 = std::make_shared<Node>();

    node1->next = node2;
    node2->next = node1; // 순환 참조
    */
    return 0;
}