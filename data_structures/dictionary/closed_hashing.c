#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define PRIMARY_SIZE 10
#define TABLE_CAPACITY 12 // (PRIMARY_SIZE * 1.2) - Provides a synonym area

#define EMPTY '\0'
#define DELETED '\1'

typedef char ElementType;

typedef struct {
    ElementType *data;
    int capapity;
} Dictionary;

// Core API
int hash(ElementType elem);
void initDictionary(Dictionary *D);
void freeDictionary(Dictionary *D);
void insertElem(Dictionary *D, ElementType elem);
void deleteElem(Dictionary *D, ElementType elem);
bool search(const Dictionary *D, ElementType elem);

// Utility
void displayCluster(const Dictionary *D, ElementType key);
void displayDictionary(const Dictionary *D);

int main(void) {
    Dictionary D;
    initDictionary(&D);

    insertElem(&D, 'A'); // Hash('A') = 65 % 10 = 5
    insertElem(&D, 'K'); // Hash('K') = 75 % 10 = 5 (Collision!)
    insertElem(&D, 'U'); // Hash('U') = 85 % 10 = 5 (Collision!)
    
    printf("--- Initial Dictionary ---\n");
    displayDictionary(&D);

    printf("\nSynonyms for 'A' (Cluster 5): ");
    displayCluster(&D, 'A');

    printf("\nDeleting 'A'...\n");
    deleteElem(&D, 'A');
    
    printf("Searching for 'A': %s\n", search(&D, 'A') ? "FOUND" : "NOT FOUND");
    printf("Searching for 'K': %s\n", search(&D, 'K') ? "FOUND" : "NOT FOUND"); // Should still find 'K' past the DELETED 'A'

    printf("\n--- Dictionary After Deletion ---\n");
    displayDictionary(&D);

    freeDictionary(&D);
    return 0;
}

int hash(ElementType elem) {
    // Primary hashing targets only the first PRIMARY_SIZE indices (0-9)
    // Indices 10 and 11 act as the initial overflow/synonym area
    return elem % PRIMARY_SIZE;
}

void initDictionary(Dictionary *D) {
    D->capapity = TABLE_CAPACITY;
    D->data = malloc(sizeof(ElementType) * D->capapity);

    if (D->data == NULL) {
        printf("CRITICAL ERROR: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < D->capapity; i++) {
        D->data[i] = EMPTY;
    }
}

void freeDictionary(Dictionary *D) {
    free(D->data);
    D->data = NULL;
    D->capapity = 0;
}

void insertElem(Dictionary *D, ElementType elem) {
    int index = hash(elem);
    int ctr = 0;

    // Probe until we find an EMPTY or DELETED slot, or check the whole table
    while (ctr < D->capapity && D->data[index] != EMPTY && D->data[index] != DELETED) {
        index = (index + 1) % D->capapity;
        ctr++;
    }

    if(ctr < D->capapity) {
        D->data[index] = elem;
    } else {
        printf("ERROR: Dictionary is full. Cannot insert '%c'.\n", elem);
    }
}

void deleteElem(Dictionary *D, ElementType elem) {
    int index = hash(elem);
    int ctr = 0;

    // Probe until we find the element, hit an EMPTY slot, or check the whole table
    while (ctr < D->capapity && D->data[index] != EMPTY){
        if (D->data[index] == elem) {
            D->data[index] = DELETED; // Tombstone marker
            return;
        }
        index = (index + 1) % D->capapity;
        ctr++;
    }

    printf("WARNING: Element '%c' not found for deletion.\n", elem);
}

bool search(const Dictionary *D, ElementType elem) {
    int index = hash(elem);
    int ctr = 0;

    // Crucial: Stop probing if hit EMPTY. The element cannot be past an EMPTY slot.
    while (ctr < D->capapity && D->data[index] != EMPTY) {
        if (D->data[index] == elem) {
            return true;
        }
        index = (index + 1) % D->capapity;
        ctr++;
    }
    
    return false;
}

void displayCluster(const Dictionary *D, ElementType key) {
    int start_index = hash(key);
    int index = start_index;
    int ctr = 0;

    // Display all elements in this specific probe sequence cluster
    while (ctr < D->capapity && D->data[index] != EMPTY) {
        // Only print elements that hash to cluster origin
        if (D->data[index] != DELETED && hash(D->data[index]) == start_index) {
            printf("[%c] ", D->data[index]);
        }
        index = (index + 1) % D->capapity;
        ctr++;
    }
    printf("\n");
}

void displayDictionary(const Dictionary *D) {
    for (int i = 0; i < D->capapity; i++) {
        printf("Slot %2d: ", i);
        if (D->data[i] == EMPTY) {
            printf("EMPTY\n");
        }else if (D->data[i] == DELETED) {
            printf("DELETED\n");
        } else {
            printf("%c (Hash: %d)\n", D->data[i], hash(D->data[i]));
        }
    }
}