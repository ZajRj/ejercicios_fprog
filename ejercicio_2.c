/*
    Desarrolle un programa en C que permita registrar la citas medicas de la clinica ABC
    de N cantidad de pacientes permitiendo mostrar por pantalla lo siguiente:

    1) Cantidad de pacientes masculinos y femeninos
    2) Cantidad de pacientes mayores y menores de edad
    3) Validar las fechas de nacimiento de cada paciente
    4) Aquellos pacientes cuya cedula termine en numero par y sean de sexo femenino tendran un descuento de 15%
    5) Aquellos pacientes que sean del sexo masculino y mayores de 60 años tendran un descuento del 30%
    */
#include <stdio.h>

#define currentYear 2023
#define currentMonth 5
#define currentDay 12

void genderInput(char *gender);
void dateInput(int *dd, int *mm, int *year);
int calcAge(int mm, int year);
void count(int age, char gender, int dni, int *mayores, int *menores, int *males, int *females, int *discountT, int *discountF);

int main()
{
    int n, i, dni = 0, age = 0, mayores = 0, menores = 0, males = 0, females = 0, discountF = 0, discountT = 0, dd = 0, mm = 0, year = 0;
    char gender;

    printf("Ingrese el # de pacientes a procesar: ");
    scanf("%i", &n);
    printf("\n\n");

    for (i = 1; i <= n; i++)
    {
        printf("Ingrese la cedula del paciente #%d: ",i);
        scanf("%d",&dni);

        genderInput(&gender);
        dateInput(&dd, &mm, &year);
        age = calcAge(mm, year);

        printf("\nEdad del paciente: %i a%cos.\n", age,164);

        count(age,gender,dni,&mayores,&menores,&males,&females,&discountT,&discountF);
    }
    printf("\nPacientes masculinos: %i\nPacientes femeninos: %i\n\nPacientes mayores de edad: %i\nPacientes menores de edad: %i \n\nPacientes femeninos con descuento (15): %i \nPacientes masculinos con descuento (30): %i \n", males, females, mayores, menores, discountF, discountT);

}

void genderInput(char *gender)
{
    do
    {
        printf("Ingrese el genero del paciente (F/M): ");
        scanf(" %c", &*gender);

        if (*gender != 'f' && *gender != 'F' && *gender != 'm' && *gender != 'M')
        {
            printf("Entrada invalida. Intente nuevamente.\n");
        }

    } while (*gender != 'f' && *gender != 'F' && *gender != 'm' && *gender != 'M');
}

void dateInput(int *dd, int *mm, int *year)
{

    int last_day;
    int validation = 0;

    printf("Fecha de nacimiento: \n");

    while (!validation)
    {
        printf("\nIngrese el a%co: ", 164);
        scanf(" %d", &*year);

        if (*year > 1900 && *year <= currentYear)
        {
            validation = 1;
        }
        else
        {
            printf("A%co invalido intente nuevamente.\n", 164);
        }
    }

    validation = 0;

    while (!validation)
    {
        printf("\nIngrese el mes : ");
        scanf(" %d", &*mm);

        if (*mm > 0 && *mm <= 12)
        {
            if (*mm >= 4 && *mm <= 11 && (*mm != 5 && *mm != 7 && *mm != 8))
            {
                last_day = 30;
            }

            if (*mm != 2 && (*mm >= 1 && *mm <= 12))
            {
                last_day = 31;
            }

            if (*mm == 2 && *year % 4 == 0)
            {
                last_day = 29;
            }
            else if (*mm == 2 && *year % 4 != 0)
            {

                last_day = 28;
            }

            validation = 1;
        }
        else
        {
            printf("Mes invalido, intente nuevamente\n");
        }
    }
    validation = 0;

    while (!validation)
    {
        printf("\nIngrese el dia: ");
        scanf(" %d", &*dd);

        if (*dd > 0 && *dd <= last_day)
        {
            validation = 1;
        }
        else
        {
            printf("Dia invalido, intente nuevamente.\n");
        }
    }
}

int calcAge(int mm, int year)
{

    int age = 0;

    age = currentYear - year;

    if (currentMonth < mm)
    {
        age = age - 1;
    }

    return age;
}

void count(int age, char gender, int dni, int *mayores, int *menores, int *males, int *females, int *discountT, int *discountF)
{
    if (age >= 18)
    {
        printf("mayor");
        *mayores = *mayores + 1;
    }
    else
    {
        *menores = *menores + 1 ;
    }

    if (gender == 'm' || gender == 'M')
    {
        *males = *males + 1 ;
        if (age > 60)
        {
            *discountT= *discountT + 1;
        }
    }
    else
    {
        *females =  *females + 1;

        if ((dni % 10) % 2 == 0)
        {
            *discountF = *discountF + 1;
        }
    }

    printf("\n\n");
}