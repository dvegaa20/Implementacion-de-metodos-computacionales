#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <vector>
#include <climits>
#include <sstream>

typedef unsigned int uint;

template <class T>
class MaxHeap
{
private:
    std::vector<T> hvec;

    uint parent(uint child) const { return (child - 1) / 2; }
    uint left(uint parent) const { return (parent * 2) + 1; }
    uint right(uint parent) const { return (parent * 2) + 2; }

    void swap(uint, uint);

public:
    MaxHeap() {}

    uint size() const;
    bool empty() const;

    void heapify(uint);

    T top() const;
    void push(T);
    void pop();

    std::string toString() const;
};

template <class T>
/**
 * @brief Swaps elements at i and j
 * Complexity O(1)
 * @param i
 * @param j
 */
void MaxHeap<T>::swap(uint i, uint j)
{
    T temp = hvec[i];
    hvec[i] = hvec[j];
    hvec[j] = temp;
}

template <class T>
/**
 * @brief Size of the heap
 * Complexity O(1)
 * @return uint
 */
uint MaxHeap<T>::size() const
{
    return hvec.size();
}

template <class T>
/**
 * @brief Returns True if the heap is empty
 * Complexity O(1)
 * @return true
 * @return false
 */
bool MaxHeap<T>::empty() const
{
    return hvec.empty();
}

template <class T>
/**
 * @brief Pushes the i element down the heap into its correct place
 * Complexity O(log N)
 * @param i
 */
void MaxHeap<T>::heapify(uint i)
{
    uint le = left(i);
    uint ri = right(i);
    uint max = i;

    if (le < hvec.size() && hvec[le] > hvec[max])
        max = le;

    if (ri < hvec.size() && hvec[ri] > hvec[max])
        max = ri;

    if (i != max)
    {
        swap(i, max);
        heapify(max);
    }
}

template <class T>
/**
 * @brief Returns the top element in the heap
 * Complexity O(1)
 * @return T
 */
T MaxHeap<T>::top() const
{
    if (empty())
        return INT_MAX;

    else
        return hvec[0];
}

template <class T>
/**
 * @brief Inserts val into the heap
 * Complexity O(log N)
 * @param val
 */
void MaxHeap<T>::push(T val)
{
    hvec.push_back(val);
    uint pos = hvec.size() - 1;
    while (pos > 0 && val > hvec[parent(pos)])
    {
        swap(pos, parent(pos));
        pos = parent(pos);
    }
}

template <class T>
/**
 * @brief Removes the top element
 * Complexity O(log N)
 */
void MaxHeap<T>::pop()
{
    if (empty())
        return;

    hvec[0] = hvec[hvec.size() - 1];
    hvec.pop_back();
    heapify(0);
}

template <class T>
/**
 * @brief Transforms heap to string
 * Complexity O(N)
 * @return std::string
 */
std::string MaxHeap<T>::toString() const
{
    std::stringstream aux;
    for (auto element : hvec)
    {
        aux << element << " ";
    }
    return aux.str();
}

#endif