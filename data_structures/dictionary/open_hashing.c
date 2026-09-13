#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 10

typedef char ElementType;

typedef struct node {
    ElementType data;
    struct node *link;
} Node, *NodePtr;

typedef struct {
    NodePtr buckets[SIZE];
} Dictionary;

// Core API
void initDictionary(Dictionary *D);
void freeDictionary(Dictionary *D);
int hash(ElementType elem);
void insertElem(Dictionary *D, ElementType elem);
void deleteElem(Dictionary *D, ElementType elem);
bool search(const Dictionary *D, ElementType elem);

// Utility
void displayBucket(const Dictionary *D, int key);
void displayDictionary(const Dictionary *D);

int main(void) {
    Dictionary D;
    initDictionary(&D);

    // 'A' (65) % 10 = 5
    // 'K' (75) % 10 = 5  -> Collision!
    // 'U' (85) % 10 = 5  -> Collision!
    insertElem(&D, 'A');
    insertElem(&D, 'K');
    insertElem(&D, 'U');

    // 'B' (66) % 10 = 6
    insertElem(&D, 'B');

    printf("--- Initial Dictionary ---\n");
    displayDictionary(&D);

    printf("\nSearching for 'K': %s\n", search(&D, 'K') ? "FOUND" : "NOT FOUND");
    printf("Searching for 'Z': %s\n", search(&D, 'Z') ? "FOUND" : "NOT FOUND");

    printf("\n--- Dictionary after deleting 'K' ---\n");
    deleteElem(&D, 'K');
    displayDictionary(&D);

    freeDictionary(&D);
    return 0;
}

int hash(ElementType elem) {
    // Simple modulo hasing
    return elem % SIZE;
}

void initDictionary(Dictionary *D) {
    for(int i = 0; i < SIZE; i++) {
        D->buckets[i] = NULL;
    }
}

void freeDictionary(Dictionary *D) {
    for (int i = 0; i < SIZE; i++) {
        NodePtr curr = D->buckets[i];
        while (curr != NULL) {
            NodePtr temp = curr;
            curr = curr->link;
            free(temp);
        }
        D->buckets[i] = NULL;
    }
}

void insertElem(Dictionary *D, ElementType elem) {
    int index = hash(elem);
    
    NodePtr newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("CRITICAL ERROR: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = elem;
    // O(1) Head Insertion: New node points to current head, bucket points to new node
    newNode->link = D->buckets[index];
    D->buckets[index] = newNode;
}

void deleteElem(Dictionary *D, ElementType elem) {
    int index = hash(elem);
    
    // Using pointer2pointer makes head deletion and mid-list deletion identical
    NodePtr *trav = &(D->buckets[index]);

    while (*trav != NULL && (*trav)->data != elem) {
        trav = &(*trav)->link;
    }

    // If *trav is not NULL, we found the element
    if (*trav != NULL) {
        NodePtr del = *trav;
        *trav = del->link; // Bypass the node
        free(del);
    }
}

bool search(const Dictionary *D, ElementType elem) {
    int index = hash(elem);

    for (NodePtr trav = D->buckets[index]; trav != NULL; trav = trav->link) {
        if (trav->data == elem) {
            return true;
        }
    }
    return false;
}

void displayBucket(const Dictionary *D, int key){
    if (key < 0 || key >= SIZE) return;

    printf("Bucket [%d]: ", key);
    for (NodePtr trav = D->buckets[key]; trav != NULL; trav = trav->link) {
        printf("[%c] -> ", trav->data);
    }
    printf("NULL\n");
}

void displayDictionary(const Dictionary *D) {
    for (int i = 0; i < SIZE; i++) {
        displayBucket(D, i);
    }
}