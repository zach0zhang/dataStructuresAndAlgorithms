#include "Vector.h"

template <typename E>
class ArrayVector {
public:
    ArrayVector();
    int size() const;
    bool empty() const;
    E& operator[](int i);
    E& at(int i);
    void erase(int i);
    void insert(int i, const E& e);
    void push_back(const E& e);
    void pop_back();
    void reserve(int N);
private:
    int capacity;
    int n;
    E* A;
};

template <typename E>
ArrayVector<E>::ArrayVector() : capacity(0), n(0), A(NULL) { }

template <typename E>
int ArrayVector<E>::size() const {
    return n;
}

template <typename E>
bool ArrayVector<E>::empty() const {
    return (size() == 0);
}

template <typename E>
E& ArrayVector<E>::operator[](int i) {
    return A[i];
}

template <typename E>
E& ArrayVector<E>::at(int i) {
    if (i < 0 || i >= n)
        throw IndexOutOfBounds("illegal index in function at()");
    return A[i];
}

template <typename E>
void ArrayVector<E>::erase(int i) {
    for (int j = i + 1; j < n; j++)
        A[j - 1] = A[j];
    n--;
}

template <typename E>
void ArrayVector<E>::reserve(int N) {
    if (capacity >= N)
        return;

    E* B = new E[N];
    for (int j = 0; j < n; j++)
        B[j] = A[j];
    if (A != NULL)
        delete []A;
    A = B;
    capacity = N;
}

template <typename E>
void ArrayVector<E>::insert(int i, const E& e) {
    if (n >= capacity)
        reserve(max(1, 2 * capacity));
    
    for (int j = n - 1; j >= i; j--)
        A[j+1] = A[j];
    
    A[i] = e;
    n++;
}

template <typename E>
void ArrayVector<E>::push_back(const E& e) {
    insert(n, e);
}

template <typename E>
void ArrayVector<E>::pop_back() {
    erase(n - 1);
}

