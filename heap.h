//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    // Insert an index into the heap and restore the heap property
    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        // insert at the end
        data[size] = idx;
        int pos = size;
        size++;
        upheap(pos, weightArr);


    }
    // Remove and return the index with the smallest weight
    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        if (size == 0)
            return -1;

        int top = data[0];
        size--;

        if (size > 0) {
            data[0] = data[size];
            downheap(0, weightArr);
        }

        return top;
    }
    // Bubble up the element at position 'pos' while it is smaller than its parent
    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
    }
    // Push down the element at position 'pos' while larger than either child
    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
    }
};

#endif