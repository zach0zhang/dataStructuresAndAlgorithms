#ifndef __MAP_ENTRY_H__
#define __MAP_ENTRY_H__

#include <stdexcept>
#include <string>

using namespace std;

class NonexistentElement : public runtime_error {
public:
    NonexistentElement(const string& err) : runtime_error(err) { }
};


template <typename K, typename V>
class Entry {
public:
    typedef K Key;
    typedef V Value;
public:
    Entry(const K& k = K(), const V& v = V()) : _key(k), _value(v) { }
    const K& key() const { return _key; }
    const V& value() const { return _value; }
    void setKey(const K& k) { _key = k; }
    void setValue(const V& v) { _value = v; }
private:
    K _key;
    V _value;
};

#endif