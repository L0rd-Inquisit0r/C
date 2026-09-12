#include<stdio.h>

// 1 byte = 8 bits. This set can hold elements from 0 to 7.
typedef unsigned char CompWordSet;

// Core API
void initSet(CompWordSet *S);
void insertElem(CompWordSet *S, int ndx);
void deleteElem(CompWordSet *S, int ndx);
void display(CompWordSet S, const char *name);

// Set Operations (Pass/Return by value is ideal because the struct is only 1 byte)
CompWordSet setUnion(CompWordSet A, CompWordSet B);
CompWordSet setIntersection(CompWordSet A, CompWordSet B);
CompWordSet setDifference(CompWordSet A, CompWordSet B);

int main(void) {
    CompWordSet A = 69;   // Binary: 0100 0101 (Elements: 0, 2, 6)
    CompWordSet B = 42;   // Binary: 0010 1010 (Elements: 1, 3, 5)
    CompWordSet C = 240;  // Binary: 1111 0000 (Elements: 4, 5, 6, 7)

    display(C, "Initial Set C (240)");
    
    // Test Bit manipulation
    deleteElem(&C, 5);
    insertElem(&C, 0);
    display(C, "Set C (Modded)");

    printf("\n");
    display(A, "Set A (69)");
    display(B, "Set B (42)");

    display(setUnion(A, B), "Union (A U B)");
    display(setIntersection(A, B), "Intersection (A n B)");
    display(setDifference(A, B), "Difference (A - B)");

    return 0;
}

void initSet(CompWordSet *S) {
    *S = 0;
}

void insertElem(CompWordSet *S, int ndx) {
    if (ndx >= 0 && ndx < 8) {
        // Shift a 1 to the target index, then OR it to force that bit to 1
        *S |= (1 << ndx);
    } else {
        printf("ERROR: Index %d out of bounds (0-7).\n", ndx);
    }
}

void deleteElem(CompWordSet *S, int ndx) {
    if (ndx >= 0 && ndx < 8) {
        // Shift a 1, invert it to 0 (and all others to 1s), then AND to clear the target bit
        *S &= ~(1 << ndx);
    } else {
        printf("ERROR: Index %d out of bounds (0-7).\n", ndx);
    }
}

void display(CompWordSet S, const char *name) {
    printf("%-20s: [ ", name);

    // Print binary representation (MSB to LSB)
    for(int i = 7; i >= 0; i--) {
        printf("%d", (S & (1 << i)) ? 1 : 0);
    }

    printf(" ] -> { ");

    // Print mathematical set notation
    int first = 1;
    for (int i = 0; i < 8; i++) {
        if (S & (1 << i)) {
            if (!first) printf(", ");
            printf("%d", i);
            first = 0;
        }
    }
    printf(" }\n");
}

CompWordSet setUnion(CompWordSet A, CompWordSet B) {
    return A | B;
}

CompWordSet setIntersection(CompWordSet A, CompWordSet B) {
    return A & B;
}

CompWordSet setDifference(CompWordSet A, CompWordSet B) {
    // Elements in A, but NOT in B
    return A & ~B;
}