#include <stdio.h>

#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

/* Initialize hash table */
void initialize()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = -1;
    }
}

/* Hash function */
int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

/* Insert an element */
void insert(int key)
{
    int index = hashFunction(key);
    int originalIndex = index;

    /* Linear probing */
    while (hashTable[index] != -1)
    {
        index = (index + 1) % TABLE_SIZE;

        /* Check whether the table is full */
        if (index == originalIndex)
        {
            printf("Hash table is full. Cannot insert %d.\n", key);
            return;
        }
    }

    hashTable[index] = key;
    printf("Element %d inserted at index %d.\n", key, index);
}

/* Search an element */
int search(int key)
{
    int index = hashFunction(key);
    int originalIndex = index;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
        {
            return index;
        }

        index = (index + 1) % TABLE_SIZE;

        /* Completed one full cycle */
        if (index == originalIndex)
        {
            break;
        }
    }

    return -1;
}

/* Display hash table */
void display()
{
    printf("\nHash Table Contents:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable[i] == -1)
        {
            printf("Index %d: Empty\n", i);
        }
        else
        {
            printf("Index %d: %d\n", i, hashTable[i]);
        }
    }
}

/* Main function */
int main()
{
    int choice, key, result;

    initialize();

    while (1)
    {
        printf("\n--- Hash Table Menu ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter integer to insert: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter integer to search: ");
                scanf("%d", &key);
                result = search(key);

                if (result != -1)
                {
                    printf("Element %d found at index %d.\n", key, result);
                }
                else
                {
                    printf("Element %d not found in the hash table.\n", key);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Please enter 1-4.\n");
        }
    }

    return 0;
}