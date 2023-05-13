#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SIZE 200

void fillMatrix(float data[MAX_SIZE][3], int *indexes);
float calculateTotal(float data[MAX_SIZE][3], int category, int indexes);

int main()
{
    FILE *output;
    int indexes = 0, x, y;
    float totalSales = 0, totalCat = 0, totalCat_2 = 0, totalCat_3 = 0;
    float data[MAX_SIZE][3];

    fillMatrix(data, &indexes);

    for (x = 0; x < indexes-1; x++)
    {
        for ( y = 0; y < 3; y++)
        {
            printf(" [%.1f] ",data[x][y]);
        }
        printf("\n");
        
    }
    

    totalCat = calculateTotal(data, 1, indexes);
    totalCat_2 = calculateTotal(data, 2, indexes);
    totalCat_3 = calculateTotal(data, 3, indexes);

    totalSales = totalCat + totalCat_2 + totalCat_3;

    printf("\nVentas totales: %.02f\nVentas categoria 1: %.02f\nVentas categoria 2: %.02f\nVentas categoria 3: %.02f", totalSales, totalCat, totalCat_2, totalCat_3);

    output = fopen("ventas_totales.txt", "w");
    
    fprintf(output, "ventas_totales.txt\n\nVentas totales: %.02f\nVentas categoria 1: %.02f\nVentas categoria 2: %.02f\nVentas categoria 3: %.02f", totalSales, totalCat, totalCat_2, totalCat_3);
    
    fclose(output);

    printf("\n\nSe ha generdo un archivo con los datos de ventas.\n\nEl programa se cerrara automaticamente en 5 segundos ");
    sleep(5);

    return 0;

}

void fillMatrix(float data[MAX_SIZE][3], int *indexes)
{
    int category, soldQuantity;
    float unitPrice;
    FILE *file = fopen("ventas.txt","r");

    if (file == NULL)
    {
        printf("There was an error opening the file.\n");
        exit(1);
    }

    while (!feof(file) && *indexes < MAX_SIZE)
    {
        fscanf(file,"%i,%i,%f", &category, &soldQuantity, &unitPrice);

        data[*indexes][0] = category;
        data[*indexes][1] = soldQuantity;
        data[*indexes][2] = unitPrice;

        *indexes = *indexes + 1;
    }
    fclose(file);

}

float calculateTotal(float data[MAX_SIZE][3], int category, int indexes)
{
    int i, j;
    float total;
    for (i = 0; i < indexes; i++)
    {
        if (data[i][0] == category)
        {
            total = total + ((data[i][1]+0.0) * data[i][2]);
        }
    }
    return total;
}