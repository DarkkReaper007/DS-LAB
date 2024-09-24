#include <stdio.h>
#include <stdlib.h>

// Node structure representing a term in the polynomial
struct Node {
    int coeff;     // Coefficient of the term
    int exp;       // Exponent of the term
    struct Node* next;
};

// Function to create a new node for the polynomial
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term in the result polynomial
void appendTerm(struct Node** result, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*result == NULL) {
        *result = newNode;
    } else {
        struct Node* temp = *result;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to add two polynomials represented as linked lists
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp == poly2->exp) {
            // Add coefficients when exponents are equal
            int sumCoeff = poly1->coeff + poly2->coeff;
            appendTerm(&result, sumCoeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exp > poly2->exp) {
            // Take term from the first polynomial
            appendTerm(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else {
            // Take term from the second polynomial
            appendTerm(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
    }

    // If any terms remain in the first polynomial, append them
    while (poly1 != NULL) {
        appendTerm(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    // If any terms remain in the second polynomial, append them
    while (poly2 != NULL) {
        appendTerm(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

// Function to print a polynomial
void printPolynomial(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    // Create the first polynomial 5x^2 + 4x + 2
    struct Node* poly1 = createNode(5, 2);
    poly1->next = createNode(4, 1);
    poly1->next->next = createNode(2, 0);

    // Create the second polynomial 3x^3 + 2x + 1
    struct Node* poly2 = createNode(3, 3);
    poly2->next = createNode(2, 1);
    poly2->next->next = createNode(1, 0);

    printf("Polynomial 1: ");
    printPolynomial(poly1);

    printf("Polynomial 2: ");
    printPolynomial(poly2);

    // Add the polynomials
    struct Node* result = addPolynomials(poly1, poly2);

    printf("Resultant Polynomial: ");
    printPolynomial(result);

    return 0;
}
