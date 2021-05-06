#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdexcept>

using namespace std;

class IndexOutOfBounds : public runtime_error {
public:
    IndexOutOfBounds(const string& err) : runtime_error(err) { }
};


#endif