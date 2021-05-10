#include <list>
#include "Queue.h"

/*
struct C {
    bool operator() (const E& p, const E& q) {
        return p < q; 
    }
};
*/

template <typename E, typename C>
class ListPriorityQueue {
public:
    int size() const;
    bool empty() const;
    void insert(const E& e);
    const E& min() const;
    void removeMin();
private:
    std::list<E> L;
    C isLess;
};

template <typename E, typename C>
int ListPriorityQueue<E,C>::size() const {
    return L.size();
}

template <typename E, typename C>
bool ListPriorityQueue<E,C>::empty() const {
    return L.empty();
}

template <typename E, typename C>
void ListPriorityQueue<E,C>::insert(const E& e) {
    typename std::list<E>::iterator p;
    p = L.begin();
    while (p != L.end() && !isLess(e, *p))
        ++p;
    L.insert(p, e);
}

template <typename E, typename C>
const E& ListPriorityQueue<E,C>::min() const {
    return L.front();
}

template <typename E, typename C>
void ListPriorityQueue<E,C>::removeMin() {
    L.pop_front();
}
