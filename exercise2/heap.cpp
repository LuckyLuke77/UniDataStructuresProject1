#include <iostream>

using namespace std;

const int static HEAP_SIZE_LIMIT = 100000000; // 100 million
float heap[HEAP_SIZE_LIMIT + 1];
int heap_size = 0;

// Add an item inside the heap to the appropriate place, depending on the type of the heap
void TurnToHeap(int k, string type) {
    float v = heap[k];
    bool flag = false;
    if (type == "heapMax") {
        while (!flag && 2 *k <= heap_size) {
            int j = 2 *k;
            if (j < heap_size) {
                if (heap[j] < heap[j + 1]) {
                    j++;
                }
            }
            if (v >= heap[j]) {
                flag = true;
            } else {
                heap[k] = heap[j];
                k = j;
            }
        }
    } else if (type == "heapMin") {
        while (!flag && 2 *k <= heap_size) {
            int j = 2 *k;
            if (j < heap_size) {
                if (heap[j] > heap[j + 1]) {
                    j++;
                }
            }
            if (v <= heap[j]) {
                flag = true;
            } else {
                heap[k] = heap[j];
                k = j;
            }
        }
    }
    heap[k] = v;
}

// Turn the list a into a heap
void Initialize(float *a, int N, string type) {
    heap_size = N;
    for (int i = 0; i < N; i++) {
        heap[i + 1] = a[i];
    }
    for (int i = heap_size / 2; i >= 1; i--) {
        TurnToHeap(i, type);
    }
}

// Returns the root node
int top() { 
    return heap[1]; 
}

// Changes the value of the root node
void ChangeTop(float key) {
    heap[1] = key;
}

// remover the top item of the heap
void pop(string type) {
    swap(heap[1], heap[heap_size]);
    heap_size--;
    TurnToHeap(1, type);
}
