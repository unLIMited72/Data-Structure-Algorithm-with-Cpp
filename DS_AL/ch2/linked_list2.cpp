// Doubly Linked List Examplesd

#include <iostream>

struct Node
{
    int data_;
    Node* prev_;
    Node* next_;
};

class LinkedList2
{
private:
    int count_;
    Node* begin_;
    Node* end_;
public:
    LinkedList2() {
        count_ = 0;
        begin_ = new Node {0, nullptr, nullptr};
        end_ = new Node {0, nullptr, nullptr};
        begin_->next_ = end_;
        end_->prev_ = begin_;
    };
    ~LinkedList2() {
        while ( !empty() )
            pop_back();
        delete begin_, end_;
    };

    bool empty() {
        return begin_->next_ == end_ && end_->prev_ == begin_;
    }

    int size() {
        return count_;
    }

    void insert(Node* p, int val) {
        Node* new_node = new Node {val, p->prev_, p};
        new_node->prev_->next_ = new_node;
        new_node->next_->prev_ = new_node;
        count_++;
    }
    void push_front(int val) {
        insert(begin_->next_, val);
    }
    void push_back(int val) {
        insert(end_, val);
    }

    void erase(Node* p) {
        p->prev_->next_ = p->next_;
        p->next_->prev_ = p->prev_;
        delete p;
        count_--;
    }
    void pop_front() {
        if ( !(empty()) )
            erase(begin_->next_);
    }
    void pop_back() {
        if ( !(empty()) )
            erase(end_->prev_);
    }

    void print_all() {
        Node* curr = begin_->next_;
        while (curr != end_)
        {
            std::cout << curr->data_ << ", ";
            curr = curr->next_;
        }
        std::cout << std::endl;
    }
    void print_reverse() {
        Node* curr = end_->prev_;
        while (curr != begin_)
        {
            std::cout << curr->data_ << ", ";
            curr = curr->prev_;
        }
        std::cout << std::endl;
    }
};

int main()
{
    LinkedList2 ll;
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.print_all();
    ll.print_reverse();

    ll.pop_front();
    ll.pop_back();
    ll.print_all();

    ll.push_front(100);
    ll.push_back(400);
    ll.print_all();
}