#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdexcept>
#include <string>

using namespace std;

class QueueEmpty : public runtime_error {
public:
    QueueEmpty(const string& err) : runtime_error(err) { }
};

class DequeEmpty : public runtime_error {
public:
    DequeEmpty(const string& err) : runtime_error(err) { }
};
/*
template <typename E>
class Queue {
public:
    int size() const;
    bool empty() const;
    const E& front() const;
    void enqueue(const E& e);
    void dequeue();
};
*/

#endif