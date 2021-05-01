#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H
template <typename E>
class SLinkedList;

template <typename E>
class SNode {
private:
    E elem;
    SNode<E>* next;
    friend class SLinkedList<E>;
};

template <typename E>
class SLinkedList {
public:
    SLinkedList();
    ~SLinkedList();
    bool empty() const;
    const E& front() const;
    void addFront(const E& e);
    void removeFront();

    void reverse();

private:
    SNode<E>* head;
};

template <typename E>
SLinkedList<E>::SLinkedList() : head(NULL) {}

template <typename E>
SLinkedList<E>::~SLinkedList() {
    while (!empty())
        removeFront();
}

template <typename E>
bool SLinkedList<E>::empty() const {
    return head == NULL;
}

template <typename E>
const E& SLinkedList<E>::front() const {
    return head->elem;
}

template <typename E>
void SLinkedList<E>::addFront(const E& e) {
    SNode<E>* v = new SNode<E>;
    v->elem = e;
    v->next = head;
    head = v;
}

template <typename E>
void SLinkedList<E>::removeFront() {
    SNode<E>* old = head;
    head = old->next;
    delete old;
}

template <typename E>
void SLinkedList<E>::reverse()
{
    SLinkedList<E> tmp;
    E tmpElem;

    SNode<E>* firstHead = NULL;
    SNode<E>* oldNode = NULL;
    bool firstHeadFlag = false;
    
    while (!empty()) {
        tmpElem = front();
        removeFront();
        tmp.addFront(tmpElem);
    }

    while (!tmp.empty()) {

        tmpElem = tmp.front();
        tmp.removeFront();
        
        SNode<E>* node = new SNode<E>;
        node->elem = tmpElem;
        node->next = NULL;
        if (!firstHeadFlag) {
            firstHead = node;
            firstHeadFlag = true;
        } else
            oldNode->next = node;
        oldNode = node;
    }

    head = firstHead;
}

#endif