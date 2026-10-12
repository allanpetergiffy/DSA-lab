#include <stdio.h>
#define MAX 20
void sparseRepresentation(int a[][MAX], int rows, int cols, int b[][3]);
void display(int b[][3]);
void sparseAddition(int a[][3], int b[][3], int c[][3]);
void sparseTranspose(int a[][3], int b[][3]);
int main()
{
int rows, cols;
int mat1[MAX][MAX], mat2[MAX][MAX];
int s1[401][3], s2[401][3], result[401][3], trans[401][3];
int i, j;
printf("Enter number of rows and columns: ");
scanf("%d%d", &rows, &cols);
// Reading first matrix
printf("Enter First Matrix elements:\n");
for(i = 0; i < rows; i++)
{
for(j = 0; j < cols; j++)
{
scanf("%d", &mat1[i][j]);
}
}
// Reading second matrix
printf("\nEnter Second Matrix elements:\n");
for(i = 0; i < rows; i++)
{
for(j = 0; j < cols; j++)
{
scanf("%d", &mat2[i][j]);
}
}
// Sparse representation of First Matrix
sparseRepresentation(mat1, rows, cols, s1);
printf("\nSparse Matrix Representation of First Matrix (S1):\n");
display(s1);
// Sparse representation of Second Matrix
sparseRepresentation(mat2, rows, cols, s2);
printf("\nSparse Matrix Representation of Second Matrix (S2):\n");
display(s2);
// Sparse Addition S1 + S2
sparseAddition(s1, s2, result);
printf("\nSparse Matrix Addition Result (S1 + S2):\n");
display(result);
// Transpose of Resultant Matrix
sparseTranspose(result, trans);
printf("\nTranspose of Resultant Sparse Matrix:\n");
display(trans);
return 0;
}
void sparseRepresentation(int a[][MAX], int rows, int cols, int b[][3])
{
int i, j, k = 1;
b[0][0] = rows;
b[0][1] = cols;
for(i = 0; i < rows; i++)
{
for(j = 0; j < cols; j++)
{
if(a[i][j] != 0)
{
b[k][0] = i;
b[k][1] = j;
b[k][2] = a[i][j];
k++;
}
}
}
b[0][2] = k - 1;
}
void display(int b[][3])
{
int i;
printf("Row\tCol\tValue\n");
for(i = 0; i <= b[0][2]; i++)
{
printf("%d\t%d\t%d\n",
b[i][0],
b[i][1],
b[i][2]);
}
}
void sparseAddition(int a[][3], int b[][3], int c[][3])
{
int i = 1, j = 1, k = 1;
c[0][0] = a[0][0];
c[0][1] = a[0][1];
while(i <= a[0][2] && j <= b[0][2])
{
if(a[i][0] == b[j][0] && a[i][1] == b[j][1])
{
c[k][0] = a[i][0];
c[k][1] = a[i][1];
c[k][2] = a[i][2] + b[j][2];
i++;
j++;
k++;
}
else if(a[i][0] < b[j][0] ||
(a[i][0] == b[j][0] && a[i][1] < b[j][1]))
{
c[k][0] = a[i][0];
c[k][1] = a[i][1];
c[k][2] = a[i][2];
i++;
k++;
}
else
{
c[k][0] = b[j][0];
c[k][1] = b[j][1];
c[k][2] = b[j][2];
j++;
k++;
}
}
while(i <= a[0][2])
{
c[k][0] = a[i][0];
c[k][1] = a[i][1];
c[k][2] = a[i][2];
i++;
k++;
}
while(j <= b[0][2])
{
c[k][0] = b[j][0];
c[k][1] = b[j][1];
c[k][2] = b[j][2];
j++;
k++;
}
c[0][2] = k - 1;
}
void sparseTranspose(int a[][3], int b[][3])
{
int i, j, k = 1;
b[0][0] = a[0][1];
b[0][1] = a[0][0];
b[0][2] = a[0][2];
for(i = 0; i < a[0][1]; i++)
{
for(j = 1; j <= a[0][2]; j++)
{
if(a[j][1] == i)
{
b[k][0] = a[j][1];
b[k][1] = a[j][0];
b[k][2] = a[j][2];
k++;
}
}
}
}
