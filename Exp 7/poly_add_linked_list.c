#include <stdio.h>
#include <stdlib.h>

struct poly
{
    int coeff;
    int exp;
    struct poly *link;
};

/* Create a new node */
struct poly *createNode(int coeff, int exp)
{
    struct poly *newNode = (struct poly *)malloc(sizeof(struct poly));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->link = NULL;
    return newNode;
}

/* Insert a node at the end */
void insertNode(struct poly **head, int coeff, int exp)
{
    struct poly *newNode = createNode(coeff, exp);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct poly *temp = *head;
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = newNode;
    }
}

/* Display polynomial */
void display(struct poly *head)
{
    struct poly *temp = head;
    while (temp != NULL)
    {
        printf("%d(x^%d)", temp->coeff, temp->exp);
        if (temp->link != NULL)
            printf(" + ");
        temp = temp->link;
    }
    printf("\n");
}

/* Add two polynomials */
struct poly *addPoly(struct poly *poly1, struct poly *poly2)
{
    struct poly *poly3 = NULL;
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->exp == poly2->exp)
        {
            int sum = poly1->coeff + poly2->coeff;
            if (sum != 0)
                insertNode(&poly3, sum, poly1->exp);

            poly1 = poly1->link;
            poly2 = poly2->link;
        }
        else if (poly1->exp > poly2->exp)
        {
            insertNode(&poly3, poly1->coeff, poly1->exp);
            poly1 = poly1->link;
        }
        else
        {
            insertNode(&poly3, poly2->coeff, poly2->exp);
            poly2 = poly2->link;
        }
    }

    /* Copy remaining terms of polynomial 1 */
    while (poly1 != NULL)
    {
        insertNode(&poly3, poly1->coeff, poly1->exp);
        poly1 = poly1->link;
    }
    /* Copy remaining terms of polynomial 2 */
    while (poly2 != NULL)
    {
        insertNode(&poly3, poly2->coeff, poly2->exp);
        poly2 = poly2->link;
    }

    return poly3;
}

int main()
{
    struct poly *poly1 = NULL;
    struct poly *poly2 = NULL;
    struct poly *poly3 = NULL;
    int n1, n2, coeff, exp;

    /* Input polynomial 1 */
    printf("Enter number of terms for polynomial 1: ");
    scanf("%d", &n1);

    for (int i = 0; i < n1; i++)
    {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertNode(&poly1, coeff, exp);
    }

    /* Input polynomial 2 */
    printf("Enter number of terms for polynomial 2: ");
    scanf("%d", &n2);

    for (int i = 0; i < n2; i++)
    {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertNode(&poly2, coeff, exp);
    }

    /* Display polynomials */
    printf("\nPolynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    /* Add polynomials */
    poly3 = addPoly(poly1, poly2);

    printf("Sum of the polynomials: ");
    display(poly3);

    return 0;
}
