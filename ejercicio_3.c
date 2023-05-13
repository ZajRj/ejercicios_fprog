#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

float sum(float a, float b, float *res);
float subs(float a, float b, float *res);
float mult(float a, float b, float *res);
float divide(float a, float b, float *res);

int main()
{
    char operation,option;
    float operand_1, operand_2;
    float result;
    int exit = 0;

    while (!exit)
    {
        printf("Ingrese la operacion a realizar ( + , - , * , / ): ");
        scanf(" %c",&operation);

        printf("Ingrese el primer operando: ");
        scanf(" %f",&operand_1);

        printf("Ingrese el segundo operando: ");
        scanf(" %f",&operand_2);

        switch (operation)
        {
        case '+':
            sum(operand_1, operand_2,&result);
            break;
        case '-':
            subs(operand_1, operand_2,&result);
            break;
        case '*':
            mult(operand_1, operand_2,&result);
            break;
        case '/':
            divide(operand_1, operand_2,&result);
            break;

        default:
            printf("Operando invalido,intente nuevamente.\n");
            break;
        }

        printf("Resultado: %.02f \n",result);

        printf("Quieres realizar otra operacion? (Y/N): ");
        option = getch();

        if(option == 'n' || option == 'N'){
            exit = 1;
        }else{
            system("cls");
        }

    }
}

float sum(float a, float b, float *res)
{
    *res = a + b;
}
float subs(float a, float b, float *res)
{
    *res = a - b;
}
float mult(float a, float b, float *res)
{
    *res = a * b;
}
float divide(float a, float b, float *res)
{
    *res = a / b;
}