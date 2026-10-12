#include <stdio.h>

int main()
{
    int n, data;
    int A[100];
    int l, r, mid;
    int flag = 0;
    int count = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements in ascending order:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("Enter the item to be searched: ");
    scanf("%d", &data);

    l = 0;
    r = n - 1;

    while (l <= r)
    {
        count++;

        mid = (l + r) / 2;

        if (A[mid] == data)
        {
            printf("Item found at index %d\n", mid);
            flag = 1;
            break;
        }
        else if (data < A[mid])
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    if (flag == 0)
    {
        printf("Item not found\n");
    }

    /* Space calculation */
    int space = 7 * 4 + n * 4;

    printf("\nTime units = %d\n", count);
    printf("Space used = %d bytes\n", space);

    printf("\nTime Complexity:\n");
    printf("Best Case = O(1)\n");
    printf("Average Case = O(log n)\n");
    printf("Worst Case = O(log n)\n");

    printf("Space Complexity = O(n)\n");

    return 0;
}
