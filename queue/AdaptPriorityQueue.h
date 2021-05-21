#include <list>

template <typename E, typename C>
class AdaptPriorityQueue {
protected:
    typedef std::list<E> ElementList;
public:
    class Position {
    private:
        typename ElementList::iterator q;
    public:
        const E& operator*() { return *q; }
        friend class AdaptPriorityQueue;
    };
public:
    int size() const;
    bool empty() const;
    const E& min() const;
    Position insert(const E& e);
    void removeMin();
    void remove(const Position& p);
    Position replace(const Position& p, const E& e);

private:
    ElementList L;
    C isLess;
};

template <typename E, typename C>
int AdaptPriorityQueue<E,C>::size() const {
    return L.size();
}

template <typename E, typename C>
bool AdaptPriorityQueue<E,C>::empty() const {
    return L.empty();
}

template <typename E, typename C>
const E& AdaptPriorityQueue<E,C>::min() const {
    return L.front();
}

template <typename E, typename C>
typename AdaptPriorityQueue<E,C>::Position AdaptPriorityQueue<E,C>::insert(const E& e) {
    typename ElementList::iterator p = L.begin();
    while (p != L.end() && !isLess(e, *p))
        ++p;
    L.insert(p, e);
    Position pos;
    pos.q = --p;
    return pos;
}

template <typename E, typename C>
void AdaptPriorityQueue<E,C>::removeMin() {
    L.pop_front();
}

template <typename E, typename C>
void AdaptPriorityQueue<E,C>::remove(const Position& p) {
    L.erase(p.q);
}

template <typename E, typename C>
typename AdaptPriorityQueue<E,C>::Position AdaptPriorityQueue<E,C>::replace(const Position& p, const E& e) {
    L.erase(p.q);
    return insert(e);
}

