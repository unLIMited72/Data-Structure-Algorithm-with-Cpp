#include <iostream>

template <typename T>
struct Node
{
    T data_;
    Node<T>* link_prev_;
    Node<T>* link_next_;
};

template <typename T>
class DoublyLinkedList
{
private:
    size_t count_;
    Node<T>* head_;
    Node<T>* tail_;
public:
    class iterator
    {
    private:
        Node<T>* ptr;
    public:
        iterator() : ptr(nullptr) {}
        iterator(Node<T>* pos) : ptr(pos) {}
        T& operator*() { return ptr->data_; }
        T* operator->() { return &(ptr->data_); }
        const T& operator*() const { return ptr->data_; }
        const T* operator->() const { return &(ptr->data_); }
        iterator& operator++() {
            ptr = ptr->link_next_;
            return *this;
        }
        iterator operator++(int) {
            iterator past = *this;
            ptr = ptr->link_next_;
            return past;
        }
        iterator& operator--() {
            ptr = ptr->link_prev_;
            return *this;
        }
        iterator operator--(int) {
            iterator past = *this;
            ptr = ptr->link_prev_;
            return past;
        }
        bool operator==(const iterator& other) const {
            return this->ptr == other.ptr;
        }
        bool operator!=(const iterator& other) const {
            return this->ptr != other.ptr;
        }
        friend class DoublyLinkedList<T>;
    };

    DoublyLinkedList() {
        count_ = 0;
        head_ = new Node<T> {T(), nullptr, nullptr};
        tail_ = new Node<T> {T(), nullptr, nullptr};
        head_->link_next_ = tail_;
        tail_->link_prev_ = head_;
    }
    ~DoublyLinkedList() {
        while (!empty())
            pop_front();
        delete head_;
        delete tail_;
    }
    iterator begin() const {
        return iterator(head_->link_next_);
    }
    iterator end() const {
        return iterator(tail_);
    }
    bool empty() const {
        return count_ == 0;
    }
    size_t get_size() const {
        return count_;
    }
    void insert(const iterator& pos, const T& val) {
        Node<T>* p = pos.ptr;
        Node<T>* new_node = new Node<T> {val, p->link_prev_, p};
        new_node->link_prev_->link_next_ = new_node;
        new_node->link_next_->link_prev_ = new_node;
        count_++;
    }
    void push_front(const T& val){
        insert(begin(), val);
    }
    void push_back(const T& val){
        insert(end(), val);
    }
    void erase(const iterator& pos) {
        if (pos == end()) return;
        Node<T>* p = pos.ptr;
        p->link_prev_->link_next_ = p->link_next_;
        p->link_next_->link_prev_ = p->link_prev_;
        delete p;
        count_--;
    }
    void pop_front() {
        if (!empty())
            erase(begin());
    }
    void pop_back() {
        if (!empty())
            erase(--end());
    }
    iterator search(const T& val) {
        for (auto it = begin(); it != end(); ++it)
            if (*it == val)
                return it;
        return end();
    }
    void clear() {
        while (!empty())
            pop_front();
    }
};

int main()
{

}