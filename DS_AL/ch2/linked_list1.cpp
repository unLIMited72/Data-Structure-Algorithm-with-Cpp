#include <iostream>

struct Node
{
    int data;
    Node* next;
};

class LinkedList
{
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() { while( !empty() ){ pop_front(); }; }
    void push_front(int val);
    void pop_front();
    void print_all();
    bool empty();
};

void LinkedList::push_front(int val) {
    Node* new_node = new Node {val, nullptr};
    if (head != nullptr)
        new_node->next = head;
    head = new_node;
}

void LinkedList::pop_front() {
    if (head == nullptr)
        return;
    Node* pop = head;
    head = head->next;
    delete pop;
    pop = nullptr;
}

void LinkedList::print_all() {
    Node* curr = head;
    while (curr != nullptr)
    {
        std::cout << curr->data << ", ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

bool LinkedList::empty() {
    return head == nullptr;
}


int main()
{
    LinkedList ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.print_all();

    ll.pop_front();
    ll.print_all();

    ll.push_front(40);
    ll.print_all();
}

/*
    Linked List Note : 
        Good point : It's comfortable to insert/remove the elements O(1)
                     It doesn't have capacity of list
        Bad point : Not efficient (difficult) to access some element (searching)
                    Need some essential space for getting next node address
*/