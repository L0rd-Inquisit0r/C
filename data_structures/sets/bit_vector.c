#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

// Wrapping the array in a struct makes pass-by-value and pointer semantics much cleaner
typedef struct {
    bool elem[MAX_SIZE]; 
} BitVector;

// Core API
void initSet(BitVector *S);
void insertElem(BitVector *S, int ndx);
void deleteElem(BitVector *S, int ndx);
void display(const BitVector *S, const char *name);

// Set Operations (Using output parameters to avoid malloc/free overhead)
void setUnion(const BitVector *A, const BitVector *B, BitVector *result);
void setIntersection(const BitVector *A, const BitVector *B, BitVector *result);
void setDifference(const BitVector *A, const BitVector *B, BitVector *result);

int main(void) {
    // Struct initialization allows inline declaration cleanly
    BitVector A = {{true, true, true, true, true, false, false, false, false, false}};
    BitVector B = {{false, true, false, true, false, true, false, true, false, true}};
    
    BitVector U, I, D;
    initSet(&U);
    initSet(&I);
    initSet(&D);

    display(&A, "Set A");
    display(&B, "Set B");

    setUnion(&A, &B, &U);
    display(&U, "Union (A U B)");

    setIntersection(&A, &B, &I);
    display(&I, "Intersection (A n B)");

    setDifference(&A, &B, &D);
    display(&D, "Difference (A - B)");

    return 0;
}

void initSet(BitVector *S) {
    for (int i = 0; i < MAX_SIZE; i++) {
        S->elem[i] = false;
    }
}

void insertElem(BitVector *S, int ndx) {
    if (ndx >= 0 && ndx < MAX_SIZE) {
        S->elem[ndx] = true;
    }
}

void deleteElem(BitVector *S, int ndx) {
    if (ndx >= 0 && ndx < MAX_SIZE) {
        S->elem[ndx] = false;
    }
}

void display(const BitVector *S, const char *name) {
    printf("%-20s: { ", name);
    bool first = true;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (S->elem[i]) {
            if (!first) printf(", ");
            printf("%d", i);
            first = false;
        }
    }
    printf(" }\n");
}

void setUnion(const BitVector *A, const BitVector *B, BitVector *result) {
    for (int i = 0; i < MAX_SIZE; i++) {
        result->elem[i] = A->elem[i] || B->elem[i];
    }
}

void setIntersection(const BitVector *A, const BitVector *B, BitVector *result) {
    for (int i = 0; i < MAX_SIZE; i++) {
        result->elem[i] = A->elem[i] && B->elem[i];
    }
}

void setDifference(const BitVector *A, const BitVector *B, BitVector *result) {
    for (int i = 0; i < MAX_SIZE; i++) {
        result->elem[i] = A->elem[i] && !B->elem[i];
    }
}