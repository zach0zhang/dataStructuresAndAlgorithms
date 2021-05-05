#include "Queue.h"
#include "CircularlyLinkedList.h"

template <typename E>
class LinkedQueue {
public:
    LinkedQueue();
    int size() const;
    bool empty() const;
    const E& front() const;
    void enqueue(const E& e);
    void dequeue();
private:
    CircleList<E> C;
    int n;    
};

template <typename E>
LinkedQueue<E>::LinkedQueue() : C(), n(0) { }

template <typename E>
int LinkedQueue<E>::size() const {
    return n;
}

template <typename E>
bool LinkedQueue<E>::empty() const {
    return (n == 0);
}

template <typename E>
const E& LinkedQueue<E>::front() const {
    if (empty())
        throw QueueEmpty("front from empty queue");
    return C.front();
}

template <typename E>
void LinkedQueue<E>::enqueue(const E& e) {
    C.add(e);
    C.advance();
    n++;
}

template <typename E>
void LinkedQueue<E>::dequeue() {
    if (empty())
        throw QueueEmpty("dequeue of empty queue");
    C.remove();
    n--;
}