#include "stack.h"
#include "LinkedDeque.h"

template <typename E>
class DequeStack {
public:
    DequeStack();
    int size() const;
    bool empty() const;
    const E& top() const;
    void push(const E& e);
    void pop();
private:
    LinkedDeque<E> D;
};

template <typename E>
DequeStack<E>::DequeStack() : D() { }

template <typename E>
int DequeStack<E>::size() const {
    return D.size();
}

template <typename E>
bool DequeStack<E>::empty() const {
    return D.empty();
}

template <typename E>
const E& DequeStack<E>::top() const {
    if (empty())
        throw StackEmpty("top from empty stack");

    return D.front();
}

template <typename E>
void DequeStack<E>::push(const E& e) {
    D.insertFront(e);
}

template <typename E>
void DequeStack<E>::pop() {
    if (empty())
        throw StackEmpty("pop of empty stack");

    D.removeFront();
}