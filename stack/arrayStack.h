#include "stack.h"

template <typename E>
class arrayStack {
    enum { DEF_CAPACITY = 100};
public:
    arrayStack(int cap = DEF_CAPACITY);
    int size() const;
    bool empty() const;
    const E& top() const throw();
    void push(const E& e) throw();
    void pop() throw();
private:
    E* S;
    int capacity;
    int t;
};

template <typename E>
arrayStack<E>::arrayStack(int cap)
{
    S = new E[cap];
    capacity = cap;
    t = -1;
}

template <typename E>
int arrayStack<E>::size() const
{
    return (t + 1);
}

template <typename E>
bool arrayStack<E>::empty() const
{
    return (t < 0);
}

template <typename E>
const E& arrayStack<E>::top() const throw() {
    if (empty())
        throw StackEmpty("Top of empty statck");
    return S[t];
}

template <typename E>
void arrayStack<E>::push(const E& e) throw() {
    if (size() == capacity)
        throw StackFull("Push to full stack");
    S[++t] = e;
}

template <typename E>
void arrayStack<E>::pop() throw() {
    if (empty())
        throw StackEmpty("Pop from empty stack");
    --t;
}