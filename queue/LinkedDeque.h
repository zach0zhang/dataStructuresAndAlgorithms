#include "Queue.h"
#include "DoublyLinkedList.h"

template <typename E>
class LinkedDeque {
public:
    LinkedDeque();
    int size() const;
    bool empty() const;
    const E& front() const;
    const E& back() const;
    void insertFront(const E& e);
    void insertBack(const E& e);
    void removeFront();
    void removeBack();
private:
    DLinkedList<E> D;
    int n;
};

template <typename E>
LinkedDeque<E>::LinkedDeque() : D(), n(0) { }

template <typename E>
int LinkedDeque<E>::size() const {
    return n;
}

template <typename E>
bool LinkedDeque<E>::empty() const {
    return (n == 0);
}

template <typename E>
const E& LinkedDeque<E>::front() const {
    if (empty())
        throw DequeEmpty("front from empty deque");
    return D.front();
}

template <typename E>
const E& LinkedDeque<E>::back() const {
    if (empty())
        throw DequeEmpty("back from empty deque");

    return D.back();
}

template <typename E>
void LinkedDeque<E>::insertFront(const E& e) {
    D.addFront(e);
    n++;
}

template <typename E>
void LinkedDeque<E>::insertBack(const E& e) {
    D.addBack(e);
    n++;
}

template <typename E>
void LinkedDeque<E>::removeFront() {
    if (empty())
        throw DequeEmpty("removeFront of empty deque");
    D.removeFront();
    n--;
}

template <typename E>
void LinkedDeque<E>::removeBack() {
    if (empty())
        throw DequeEmpty("removeBack of empty deque");
    D.removeBack();
    n--;
}
