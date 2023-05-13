#include <stdio.h>

#define n 3

int mat[n][n], mat_2[n][n], mat_sum[n][n];
int i, j;

void read();
void sum();
void print(int mat[n][n]);

int main()
{
    read();
    sum();

    printf("MATRIZ 1----------------------------------------------------\n");
    print(mat);
    
    printf("\nMATRIZ 2----------------------------------------------------\n");
    print(mat_2);

    printf("\nMATRIZ SUMA----------------------------------------------------\n");
    print(mat_sum);

    return 0;
}

void read()
{

    printf("MATRIZ 1----------------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Ingrese el valor de la casilla %d,%d: ", i + 1, j + 1);
            scanf("%d",&mat[i][j]);
        }
    }

    printf("\nMATRIZ 2----------------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Ingrese el valor de la casilla %d,%d:  ", i + 1, j + 1);
            scanf("%d",&mat_2[i][j]);
        }
    }
}

void sum()
{
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            mat_sum[i][j] = mat[i][j] + mat_2[i][j];
        }
    }
}

void print(int mat[n][n]){
     for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d, ",mat[i][j] );
        }
        printf("\n");
    }
}
