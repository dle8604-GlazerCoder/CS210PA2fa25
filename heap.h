//
// Created by Manju Muralidharan on 10/19/25.
// Working on by Duc Le on 10/20/2025
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
        while (pos > 0) {
            int parent = (pos - 1) / 2;

            // compare weights
            if (weightArr[data[pos]] < weightArr[data[parent]]) {
                int tmp = data[pos];
                data[pos] = data[parent];
                data[parent] = tmp;
                pos = parent;
            } else {
                break;
            }
        }
    }
    // Push down the element at position 'pos' while larger than either child
    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while (true) {
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;
            int smallest = pos;

            if (left < size && weightArr[data[left]] < weightArr[data[smallest]])
                smallest = left;
            if (right < size && weightArr[data[right]] < weightArr[data[smallest]])
                smallest = right;

            if (smallest != pos) {
                int tmp = data[pos];
                data[pos] = data[smallest];
                data[smallest] = tmp;
                pos = smallest;
            } else {
                break;
            }
        }
    }
};

#endif