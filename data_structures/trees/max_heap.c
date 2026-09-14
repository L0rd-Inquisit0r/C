#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CAPACITY 10

typedef int ElementType;

typedef struct {
    ElementType elem[MAX_CAPACITY];
    int last; // Index of the last element in the heap (-1 when empty)
} MaxHeap;

// Core API
void initHeap(MaxHeap *H);
void insert(MaxHeap *H, ElementType key);
ElementType deleteMax(MaxHeap *H);
ElementType getMax(const MaxHeap *H);
void heapify(MaxHeap *H);

// Internal Maintenance Helpers
static void siftDown(MaxHeap *H, int index);
static void siftUp(MaxHeap *H, int index);
static void swap(ElementType *a, ElementType *b);

// Utility
bool isEmpty(const MaxHeap *H);
bool isFull(const MaxHeap *H);
void displayHeap(const MaxHeap *H);

int main(void) {
    MaxHeap H;
    initHeap(&H);

    printf("--- Insertion & Heap Operation ---\n");
    insert(&H, 15);
    insert(&H, 30);
    insert(&H, 20);
    insert(&H, 8);
    insert(&H, 10);
    insert(&H, 50);

    displayHeap(&H);

    printf("\nMax element (Peek): %d\n", getMax(&H));

    printf("Extracted Max: %d\n", deleteMax(&H));
    printf("Extracted Max: %d\n", deleteMax(&H));

    printf("\n--- Heap After Extractions ---\n");
    displayHeap(&H);

    return 0;
}

void initHeap(MaxHeap *H) {
    H->last = -1;
}

void insert(MaxHeap *H, ElementType key) {
    if (isFull(H)) {
        printf("ERROR: Heap Overflow. Cannot insert %d.\n", key);
        return;
    }

    H->last++;
    H->elem[H->last] = key;
    siftUp(H, H->last);
}

ElementType deleteMax(MaxHeap *H) {
    if (isEmpty(H)) {
        printf("ERROR: Heap Underflow.\n");
        return -1;
    }

    ElementType maxVal = H->elem[0];
    
    // Move last element to root and sift down
    H->elem[0] = H->elem[H->last];
    H->last--;

    if (!isEmpty(H)) {
        siftDown(H, 0);
    }

    return maxVal;
}

ElementType getMax(const MaxHeap *H) {
    if (isEmpty(H)) {
        printf("ERROR: Heap is empty.\n");
        return -1;
    }
    return H->elem[0];
}

// O(N) Bottom-Up Heap Construction
void heapify(MaxHeap *H) {
    for (int i = (H->last - 1) / 2; i >= 0; i--) {
        siftDown(H, i);
    }
}

static void siftDown(MaxHeap *H, int index) {
    int maxIndex = index;
    int left = (2 * index) + 1;
    int right = (2 * index) + 2;

    if (left <= H->last && H->elem[left] > H->elem[maxIndex]) {
        maxIndex = left;
    }

    if (right <= H->last && H->elem[right] > H->elem[maxIndex]) {
        maxIndex = right;
    }

    if (index != maxIndex) {
        swap(&H->elem[index], &H->elem[maxIndex]);
        siftDown(H, maxIndex);
    }
}

static void siftUp(MaxHeap *H, int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && H->elem[index] > H->elem[parent]) {
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

bool isEmpty(const MaxHeap *H) {
    return H->last == -1;
}

bool isFull(const MaxHeap *H) {
    return H->last == MAX_CAPACITY - 1;
}

void displayHeap(const MaxHeap *H) {
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