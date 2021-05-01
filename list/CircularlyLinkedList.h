template <typename E>
class CircleList;

template <typename E>
class CNode {
private:
    E elem;
    CNode<E>* next;

    friend class CircleList<E>;
};

template <typename E>
class CircleList {
public:
    CircleList();
    ~CircleList();
    bool empty() const;
    const E& front() const;
    const E& back() const;
    void advance();
    void add(const E& e);
    void remove();
private:
    CNode<E>* cursor;
};

template <typename E>
CircleList<E>::CircleList() : cursor(NULL) { }

template <typename E>
CircleList<E>::~CircleList() {
    while (!empty())
        remove();
}

template <typename E>
bool CircleList<E>::empty() const {
    return cursor == NULL;
}

template <typename E>
const E& CircleList<E>::front() const {
    return cursor->next->elem;
}

template <typename E>
const E& CircleList<E>::back() const {
    return cursor->elem;
}

template <typename E>
void CircleList<E>::advance() {
    cursor = cursor->next;
}

template <typename E>
void CircleList<E>::add(const E& e) {
    CNode<E>* v = new CNode<E>;
    v->elem = e;
    if (cursor == NULL) {
        v->next = v;
        cursor = v;
    } else {
        v->next = cursor->next;
        cursor->next = v;
    }
}

template <typename E>
void CircleList<E>::remove() {
    CNode<E>* old = cursor->next;
    if (old == cursor)
        cursor = NULL;
    else
        cursor->next = old->next;

    delete old;
}

