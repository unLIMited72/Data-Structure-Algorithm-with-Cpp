#include <iostream>

template <typename T>
struct Node
{
    T data_;
    Node* prev_;
    Node* next_;
};

template <typename T>
class LinkedList3
{
private:
    int count_;
    Node<T>* begin_;
    Node<T>* end_;
public:
    class iterator
    {
    private:
        Node<T>* ptr;
    public:
        iterator() : ptr(nullptr) {}
        iterator(Node<T>* p) : ptr(p) {}

        T& operator*() { return ptr->data_; }
        iterator& operator++() {
            ptr = ptr->next_;
            return *this;
        }
        iterator& operator--() {
            ptr = ptr->prev_;
            return *this;
        }
        bool operator==(const iterator& other) const {
            return this->ptr == other.ptr;
        }
        bool operator!=(const iterator& other) const {
            return this->ptr != other.ptr;
        }
        friend class LinkedList3;
    };

    LinkedList3() {
        count_ = 0;
        begin_ = new Node<T> {T(), nullptr, nullptr};
        end_ = new Node<T> {T(), nullptr, nullptr};
        begin_->next_ = end_;
        end_->prev_ = begin_;
    }
    ~LinkedList3() {
        while ( !empty() )
            pop_back();
        delete begin_;
        delete end_;
    }

    iterator begin() const {
        return iterator( begin_->next_ );
    }
    iterator end() const {
        return iterator( end_ );
    }

    bool empty() {
        return begin() == end() ;
    }

    int size() {
        return count_;
    }

    void insert(const iterator& pos , const T val) {
        Node<T>* p = pos.ptr;
        Node<T>* new_node = new Node<T> {val, p->prev_, p};
        new_node->prev_->next_ = new_node;
        new_node->next_->prev_ = new_node;
        count_++;
    }
    void push_front(const T val) {
        insert(begin(), val);
    }
    void push_back(const T val) {
        insert(end(), val);
    }

    void erase(const iterator& pos) {
        Node<T>* p = pos.ptr;
        p->prev_->next_ = p->next_;
        p->next_->prev_ = p->prev_;
        delete p;
        count_--;
    }
    void pop_front() {
        if ( !(empty()) )
            erase(begin());
    }
    void pop_back() {
        if ( !(empty()) )
            erase(--end());
    }

    iterator find (const T val) {
        for (auto it = begin(); it != end(); ++it) {
            if ( *it == val )
                return it;
        }
        return end();
    }

};

int main()
{
    LinkedList3<int> ll;
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);

    if( ll.find(20) != ll.end() )
        ll.insert(ll.find(20), 50);
    
    for (const auto& x : ll)
        std::cout << x << ", ";
    std::cout << std::endl;

    LinkedList3<double> ll_d;
    ll_d.push_back(0.1);
    ll_d.push_back(0.2);
    ll_d.push_back(0.3);

    if( ll_d.find(0.2) != ll_d.end() )
        ll_d.insert(ll_d.find(0.2), 0.5);
    
    for (const auto& x : ll_d)
        std::cout << x << ", ";
    std::cout << std::endl;
}