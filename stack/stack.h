#ifndef __STACK_H__
#define __STACK_H__

#include <stdexcept>
#include <string>

using namespace std;

class StackEmpty : public runtime_error {
public:
    StackEmpty(const string& err) : runtime_error(err) {}
};

class StackFull : public runtime_error {
public:
    StackFull(const string& err) : runtime_error(err) {}
};
/*
template <typename E>
class Stack {
public:
    int size() const;
    bool empty() const;
    const E& top() const throw(StackEmpty);
    void push(const E& e) throw(StackFull);
    void pop() throw(StackEmpty);
};
*/
#endif