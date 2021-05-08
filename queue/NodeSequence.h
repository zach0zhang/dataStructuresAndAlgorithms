#include "NodeList.h"

template <typename E>
class NodeSequence : public NodeList<E> {
public:
    typename NodeSequence<E>::Iterator atIndex(int i) const;
    int indexOf(const typename NodeSequence<E>::Iterator& p) const;
    void intBubbleSort1();
};

template <typename E>
typename NodeSequence<E>::Iterator NodeSequence<E>::atIndex(int i) const {
    typename NodeSequence<E>::Iterator p = this->begin();
    for (int j = 0; j < i; j++)
        ++p;
    return p;
}

template <typename E>
int NodeSequence<E>::indexOf(const typename NodeSequence<E>::Iterator& p) const {
    typename NodeSequence<E>::Iterator q = this->begin();
    int j = 0;
    while (q != p) {
        ++q;
        ++j;
    }
    return j;
}

template <typename E>
void NodeSequence<E>::intBubbleSort1() {
    int n = this->size();
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - i; j++) {
            typename NodeSequence<E>::Iterator prec = this->atIndex(j - 1);
            typename NodeSequence<E>::Iterator succ = this->atIndex(j);
            if (*prec > *succ) {
                E tmp = *prec;
                *prec = *succ;
                *succ = tmp;
            }
        }
    }
}