#include <list>
#include <vector>
#include "Entry.h"

template <typename K, typename V, typename H>
class HashMap {
public:
    typedef Entry<const K, V> Entry;
    class Iterator;
public:
    HashMap(int capacity = 100);
    int size() const;
    bool empty() const;
    Iterator find(const K& k);
    Iterator put(const K& k, const V& v);
    void erase(const K& k);
    void erase(const Iterator& p);
    Iterator begin();
    Iterator end();
protected:
    typedef std::list<Entry> Bucket;
    typedef std::vector<Bucket> BktArray;
    Iterator finder(const K& k);
    Iterator inserter(const Iterator& p, const Entry& e);
    void eraser(const Iterator& p);
    typedef typename BktArray::iterator BItor;
    typedef typename Bucket::iterator EItor;
    static void nextEntry(Iterator& p) { ++p.ent; }
    static bool endOfBkt(const Iterator& p) { return p.ent == p.bkt->end(); }

private:
    int n;
    H hash;
    BktArray B;
public:
    class Iterator {
    private:
        EItor ent;
        BItor bkt;
        const BktArray* ba;
    public:
        Iterator(const BktArray& a, const BItor& b, const EItor& q = EItor())
            : ent(q), bkt(b), ba(&a) { }
        Entry& operator*() const;
        bool operator==(const Iterator& p) const;
        Iterator& operator++();
        friend class HashMap;
    };
};

template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Entry& HashMap<K,V,H>::Iterator::operator*() const {
    return *ent;
}

template <typename K, typename V, typename H>
bool HashMap<K,V,H>::Iterator::operator==(const Iterator& p) const {
    if (ba != p.ba || bkt != p.bkt)
        return false;
    else if (bkt == ba->end())
        return true;
    else
        return (ent == p.ent);
}

template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator& HashMap<K,V,H>::Iterator::operator++() {
    ++ent;
    if (endOfBkt(*this)) {
        ++bkt;
        while (bkt != ba->end() && bkt->empty())
            ++bkt;
        if (bkt == ba->end())
            return *this;
        ent = bkt->begin();
    }
    return *this;
}

template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::end() {
    return Iterator(B, B.end());
}

template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::begin() {
    if (empty())
        return end();
    BItor bkt = B.begin();
    while (bkt->empty())
        ++bkt;
    return Iterator(B, bkt, bkt->begin());
}

template <typename K, typename V, typename H>
HashMap<K,V,H>::HashMap(int capacity) : n(0), B(capacity) { }

template <typename K, typename V, typename H>
int HashMap<K,V,H>::size() const {
    return n;
}

template <typename K, typename V, typename H>
bool HashMap<K,V,H>::empty() const {
    return size() == 0;
}

template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::finder(const K& k) {
    int i = hash(k) % B.size();
    BItor bkt = B.begin() + i;
    Iterator p(B, bkt, bkt->begin());
    while (!endOfBkt(p) && (*p).key() != k)
        nextEntry(p);
    return p;
}

template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::find(const K& k) {
    Iterator p = finder(k);
    if (endOfBkt(p))
        return end();
    else
        return p;
}

template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::inserter(const Iterator& p, const Entry& e) {
    EItor ins = p.bkt->insert(p.ent, e);
    n++;
    return Iterator(B, p.bkt, ins);
}

template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::put(const K& k, const V& v) {
    Iterator p = finder(k);
    if (endOfBkt(p)) {
        return inserter(p, Entry(k, v));
    } else {
        p.ent->setValue(v);
        return p;
    }
}

template <typename K, typename V, typename H>
void HashMap<K,V,H>::eraser(const Iterator& p) {
    p.bkt->erase(p.ent);
    n--;
}

template <typename K, typename V, typename H>
void HashMap<K,V,H>::erase(const Iterator& p) {
    eraser(p);
}

template <typename K, typename V, typename H>
void HashMap<K,V,H>::erase(const K& k) {
    Iterator p = finder(k);
    if (endOfBkt(p))
        throw NonexistentElement("Erase of nonexistent");
    eraser(p);
}