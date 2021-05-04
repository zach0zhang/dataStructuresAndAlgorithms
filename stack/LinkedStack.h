#include "SinglyLinkedList.h"
#include "stack.h"

template <typename E>
class LinkedStack {
public:
    LinkedStack();
    int size() const;
    bool empty() const;
    const E& top() const;
    void push(const E& e);
    void pop();
private:
    SLinkedList<E> S;
    int n;
};

template <typename E>
LinkedStack<E>::LinkedStack() : S(), n(0) { }

template <typename E>
int LinkedStack<E>::size() const {
    return n;
}

template <typename E>
bool LinkedStack<E>::empty() const {
    return (n == 0);
}

template <typename E>
const E& LinkedStack<E>::top() const {
    if (empty())
        throw StackEmpty("Top of empty stack");

    return S.front();
}

template <typename E>
void LinkedStack<E>::push(const E& e) {
    ++n;
    S.addFront(e);
}

template <typename E>
void LinkedStack<E>::pop() {
    if (empty())
        throw StackEmpty("Pop from empty stack");
    --n;
    S.removeFront();
}