#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_CAPACITY 10

typedef int ElementType;

typedef struct {
    ElementType elem[MAX_CAPACITY];
    int last; // Index of the last element in the heap (-1 when empty)
} MinHeap;

// Core API
void initHeap(MinHeap *H);
void insert(MinHeap *H, ElementType key);
ElementType deleteMin(MinHeap *H);
ElementType getMin(const MinHeap *H);
void heapify(MinHeap *H);

// Internal Maintenance Helpers
static void siftDown(MinHeap *H, int index);
static void siftUp(MinHeap *H, int index);
static void swap(ElementType *a, ElementType *b);

// Utility
bool isEmpty(const MinHeap *H);
bool isFull(const MinHeap *H);
void displayHeap(const MinHeap *H);

int main(void) {
    MinHeap H;
    initHeap(&H);

    printf("--- Insertion & Heap Operation ---\n");
    insert(&H, 15);
    insert(&H, 30);
    insert(&H, 20);
    insert(&H, 8);
    insert(&H, 10);
    insert(&H, 50);

    displayHeap(&H);

    printf("\nMin element (Peek): %d\n", getMin(&H));

    printf("Extracted Min: %d\n", deleteMin(&H));
    printf("Extracted Min: %d\n", deleteMin(&H));

    printf("\n--- Heap After Extractions ---\n");
    displayHeap(&H);

    return 0;
}

void initHeap(MinHeap *H) {
    H->last = -1;
}

void insert(MinHeap *H, ElementType key) {
    if (isFull(H)) {
        printf("ERROR: Heap Overflow. Cannot insert %d.\n", key);
        return;
    }

    H->last++;
    H->elem[H->last] = key;
    siftUp(H, H->last);
}

ElementType deleteMin(MinHeap *H) {
    if (isEmpty(H)) {
        printf("ERROR: Heap Underflow.\n");
        return -1;
    }

    ElementType minVal = H->elem[0];
    
    // Move last element to root and sift down
    H->elem[0] = H->elem[H->last];
    H->last--;

    if (!isEmpty(H)) {
        siftDown(H, 0);
    }

    return minVal;
}

ElementType getMin(const MinHeap *H) {
    if (isEmpty(H)) {
        printf("ERROR: Heap is empty.\n");
        return INT_MAX;
    }
    return H->elem[0];
}

// O(N) Bottom-Up Heap Construction
void heapify(MinHeap *H) {
    for (int i = (H->last - 1) / 2; i >= 0; i--) {
        siftDown(H, i);
    }
}

static void siftDown(MinHeap *H, int index) {
    int maxIndex = index;
    int left = (2 * index) + 1;
    int right = (2 * index) + 2;

    // Find the smallest element among parent and left/right children
    if (left <= H->last && H->elem[left] < H->elem[maxIndex]) {
        maxIndex = left;
    }

    if (right <= H->last && H->elem[right] < H->elem[maxIndex]) {
        maxIndex = right;
    }

    if (index != maxIndex) {
        swap(&H->elem[index], &H->elem[maxIndex]);
        siftDown(H, maxIndex);
    }
}

static void siftUp(MinHeap *H, int index) {
    int parent = (index - 1) / 2;
    // Swap as long as child is SMALLER than parent
    while (index > 0 && H->elem[index] < H->elem[parent]) {
        swap(&H->elem[index], &H->elem[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

static void swap(ElementType *a, ElementType *b) {
    ElementType temp = *a;
    *a = *b;
    *b = temp;
}

bool isEmpty(const MinHeap *H) {
    return H->last == -1;
}

bool isFull(const MinHeap *H) {
    return H->last == MAX_CAPACITY - 1;
}

void displayHeap(const MinHeap *H) {
    if (isEmpty(H)) {
        printf("HEAP IS EMPTY\n");
        return;
    }

    printf("Heap Array: [ ");
    for (int i = 0; i <= H->last; i++) {
        printf("%d ", H->elem[i]);
    }
    printf("]\n");
}