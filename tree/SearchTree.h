#include "LinkedBinaryTree.h"
#include "Entry.h"

#include <stdexcept>
#include <string>

using namespace std;

class NonexistentElement : public runtime_error {
public:
    NonexistentElement(const string& err) : runtime_error(err) { }
};


template <typename E>
class SearchTree {
public:
    typedef typename E::Key K;
    typedef typename E::Value V;
    class Iterator;
public:
    SearchTree(); 
    int size() const;
    bool empty() const;
    Iterator find(const K& k); 
    Iterator insert(const K& k, const V& x); 
    void erase(const K& k); 
    void erase(Iterator& p); 
    Iterator begin(); 
    Iterator end();  
protected:
    typedef LinkedBinaryTree<E> BinaryTree;
    typedef typename BinaryTree::Position TPos;
    TPos root() const; 
    TPos finder(const K& k, const TPos& v); 
    TPos inserter(const K& k, const V& x); 
    TPos eraser(TPos& v); 
    // TPos restructure(const TPos& v);
private:
    BinaryTree T;
    int n;
public:
    class Iterator { //
    private:
        TPos v;
    public:
        Iterator(const TPos& vv) : v(vv) { }
        const E& operator*() const { return *v; }
        E& operator*() { return *v; }
        bool operator==(const Iterator& p) const { return v == p.v; }
        Iterator& operator++();
        friend class SearchTree;
    };
};

template<typename E>
typename SearchTree<E>::Iterator& SearchTree<E>::Iterator::operator++() {
    TPos w = v.right();
    if (w.isInternal()) {
        do {
            v = w;
            w = w.left();
        } while (w.isInternal());
    } else {
        w = v.parent();
        while (v == w.right()) {
            v = w;
            w = w.parent();
        }
        v = w;
    }
    return *this;
} 

template <typename E>
SearchTree<E>::SearchTree() : T(), n(0) {
    T.addRoot();
    T.expendExternal(T.root());
}
template <typename E>
int SearchTree<E>::size() const {
    return n;
}
template <typename E>
bool SearchTree<E>::empty() const {
    return (size() == 0);
}

template <typename E>
typename SearchTree<E>::TPos SearchTree<E>::root() const {
    return T.root().left();
}

template <typename E>
typename SearchTree<E>::Iterator SearchTree<E>::begin() {
    TPos v = root();
    while (v.isInternal())
        v = v.left();
    return Iterator(v.parent());
}

template <typename E>
typename SearchTree<E>::Iterator SearchTree<E>::end() {
    return Iterator(T.root());
}

template <typename E>
typename SearchTree<E>::TPos SearchTree<E>::finder(const K& k, const TPos& v) {
    if (v.isExternal())
        return v;
    if (k < v->key())
        return finder(k, v.left());
    else if (v->key() < k)
        return finder(k, v.right());
    else
        return v;
}

template <typename E>
typename SearchTree<E>::Iterator SearchTree<E>::find(const K& k) {
    TPos v = finder(k, root());
    if (v.isInternal())
        return Iterator(v);
    else
        return end();
}

template <typename E>
typename SearchTree<E>::TPos SearchTree<E>::inserter(const K& k, const V& x) {
    TPos v = finder(k, root());
    while (v.isInternal())
        v = finder(k, v.right());
    T.expendExternal(v);
    v->setKey(k);
    v->setValue(x);
    n++;
    return v;
}

template <typename E>
typename SearchTree<E>::Iterator SearchTree<E>::insert(const K& k, const V& x) {
    TPos v = inserter(k, x);
    return Iterator(v);
}

template <typename E>
typename SearchTree<E>::TPos SearchTree<E>::eraser(TPos& v) {
    TPos w;
    if (v.left().isExternal())
        w = v.left();
    else if (v.right().isExternal())
        w = v.right();
    else {
        w = v.right();
        do {
            w = w.left();
        } while (w.isInternal());
        TPos u = w.parent();
        v->setKey(u->key());
        v->setValue(u->value());
    }
    n--;
    return T.removeAboveExternal(w);
}

template <typename E>
void SearchTree<E>::erase(const K& k) {
    TPos v = finder(k, root());
    if (v.isExternal())
        throw NonexistentElement("Erase of nonexistent");
    eraser(v);
}

template <typename E>
void SearchTree<E>::erase(Iterator& p) {
    eraser(p.v);
}