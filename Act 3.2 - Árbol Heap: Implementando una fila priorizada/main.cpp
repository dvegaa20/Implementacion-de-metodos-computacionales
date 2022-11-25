// =========================================================
// File: main.cpp
// Author: Diego Vega Camacho
// Date: 11/11/22
// =========================================================

#include <iostream>
#include "maxheap.h"

int main()
{
    MaxHeap<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    std::cout << q.toString() << std::endl;

    std::cout << q.top() << std::endl;

    q.pop();
    q.pop();

    std::cout << q.top() << std::endl;

    std::cout << q.toString() << std::endl;
}