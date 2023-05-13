#include <stdio.h>

#define rounds 2
int main()
{
    /* DECLARACION DE VARIABLES */

    float sd_bonus = 1.05, ud_bonus = 1.10, md_bonus = 1.15, loser_penalty = 0.40;

    int i, votes_b1 = 0, points_r_b1 = 0, wins_b1 = 0, loses_b1 = 0, votes_b2 = 0, points_r_b2 = 0, wins_b2 = 0, loses_b2 = 0, votes_draw = 0;

    int vote_j1, vote_j2, vote_j3, points_j1_b1 = 0, points_j1_b2 = 0, points_j2_b1 = 0, points_j2_b2 = 0, points_j3_b1 = 0, points_j3_b2 = 0, aux, round_winner;

    int highest_card = 0;

    float init_prize = 100000;

    float gains_b1 = 0, gains_b2 = 0;

    /* FIN DECLARACION DE VARIABLES */

    /* ROUNDS  */
    for (i = 1; i <= rounds; i++)
    {

        printf("Ingrese la decision del jurado:\n");
        printf("0 para empate\n1 para Mayweather\n2 para Canelo\n\n");

        /* DECISION DEL PRIMER JUEZ */
        do
        {
            printf("Ingrese la decision del primer juez (0/1/2): ");
            scanf(" %i", &vote_j1);

            if (vote_j1 < 0 || vote_j1 > 2)
                printf("Opcion invalida, intentelo nuevamente\n");

        } while (vote_j1 < 0 || vote_j1 > 2);

        switch (vote_j1)
        {
        case 0:
            printf("Empate, voto imparcial.\n");
            votes_draw++;
            break;
        case 1:
            printf("Voto para Mayweather.\n");
            points_j1_b1 = points_j1_b1 + 10;
            points_j1_b2 = points_j1_b2 + 9;
            votes_b1++;

            points_r_b1 += 10;
            points_r_b2 += 9;
            break;
        case 2:
            printf("Voto para Canelo.\n");
            points_j1_b2 = points_j1_b2 + 10;
            points_j1_b1 = points_j1_b1 + 9;
            votes_b2++;

            points_r_b2 += 10;
            points_r_b1 += 9;
            break;
        }
        /* FIN DECISION DEL PRIMER JUEZ */

        /* DECISION DEL SEGUNDO JUEZ */

        do
        {
            printf("Ingrese la decision del segundo juez (0/1/2): ");
            scanf(" %i", &vote_j2);

            if (vote_j2 < 0 || vote_j2 > 2)
                printf("Opcion invalida, intentelo nuevamente\n");

        } while (vote_j2 < 0 || vote_j2 > 2);

        switch (vote_j2)
        {
        case 0:
            printf("Empate, voto imparcial.\n");
            votes_draw++;
            break;
        case 1:
            printf("Voto para Mayweather.\n");
            points_j2_b1 = points_j2_b1 + 10;
            points_j2_b2 = points_j2_b2 + 9;
            votes_b1++;

            points_r_b1 += 10;
            points_r_b2 += 9;
            break;
        case 2:
            printf("Voto para Canelo.\n");
            points_j2_b2 = points_j2_b2 + 10;
            points_j2_b1 = points_j2_b1 + 9;
            votes_b2++;

            points_r_b2 += 10;
            points_r_b1 += 9;
            break;
        }

        /* FIN DECISION DEL SEGUNDO JUEZ */

        /* DECISION DEL TERCER JUEZ */

        do
        {
            printf("Ingrese la decision del tercer juez (0/1/2): ");
            scanf(" %i", &vote_j3);

            if (vote_j3 < 0 || vote_j3 > 2)
                printf("Opcion invalida, intentelo nuevamente\n");

        } while (vote_j3 < 0 || vote_j3 > 2);

        switch (vote_j3)
        {
        case 0:
            printf("Empate, voto imparcial.\n\n");
            votes_draw++;
            break;
        case 1:
            printf("Voto para Mayweather.\n\n");
            points_j3_b1 = points_j3_b1 + 10;
            points_j3_b2 = points_j3_b2 + 9;
            votes_b1++;

            points_r_b1 += 10;
            points_r_b2 += 9;
            break;
        case 2:
            printf("Voto para Canelo.\n\n");
            points_j3_b2 = points_j3_b2 + 10;
            points_j3_b1 = points_j3_b1 + 9;
            votes_b2++;

            points_r_b2 += 10;
            points_r_b1 += 9;
            break;
        }

        /* FIN DECISION DEL TERCER JUEZ */

        /* DECISION DEL ROUND */

        /* UNANIME */
        if ((votes_b1 == 3))
        {
            printf("Victoria por decision unanime: Mayweather\n\n");

            round_winner = 1;
            wins_b1++;
            loses_b2++;

            gains_b1 = gains_b1 + (init_prize * ud_bonus);
            gains_b2 = gains_b2 + (init_prize * loser_penalty);
        }

        if (votes_b2 == 3)
        {
            printf("Victoria por decision unanime: Canelo\n\n");
            round_winner = 2;
            wins_b2++;
            loses_b1++;

            gains_b2 = gains_b2 + (init_prize * ud_bonus);
            gains_b1 = gains_b1 + (init_prize * loser_penalty);
        }
        /* FIN UNANIME */

        /* DECISION DIVIDIDA */
        if ((votes_b1 == 2) && (votes_b2 == 1))
        {
            printf("Victoria por decision dividida: Mayweather\n\n");
            round_winner = 1;
            wins_b1++;
            loses_b2++;

            gains_b1 = gains_b1 + (init_prize * sd_bonus);
            gains_b2 = gains_b2 + (init_prize * loser_penalty);
        }

        if ((votes_b2 == 2) && (votes_b1 == 1))
        {
            printf("Victoria por decision dividida: Canelo\n\n");

            round_winner = 2;
            wins_b2++;
            loses_b1++;

            gains_b2 = gains_b2 + (init_prize * sd_bonus);
            gains_b1 = gains_b1 + (init_prize * loser_penalty);
        }
        /* FIN DECISION DIVIDIDA */

        /* DECISION POR MAYORIA */
        if ((votes_b1 == 2) && (votes_draw == 1))
        {
            printf("Victoria por mayoria: Mayweather\n\n");
            round_winner = 1;
            wins_b1++;
            loses_b2++;

            gains_b1 = gains_b1 + (init_prize * md_bonus);
            gains_b2 = gains_b2 + (init_prize * loser_penalty);
        }

        if ((votes_b2 == 2) && (votes_draw == 1))
        {
            printf("Victoria por mayoria: Canelo\n\n");
            round_winner = 2;
            wins_b2++;
            loses_b1++;

            gains_b2 = gains_b2 + (init_prize * md_bonus);
            gains_b1 = gains_b1 + (init_prize * loser_penalty);
        }
        /* FIN DECISION POR MAYORIA */

        /* FIN DECISION DEL ROUND */

        /* PENALIZACION POR CAER A LA LONA */
        printf("Alguno de los peleadores cayo a la lona?\n");
        printf("0 para ninguno\n1 para Mayweather\n2 para Canelo\n3 para ambos\n");

        do
        {
            printf("Ingrese una opcion (0/1/2/3): ");
            scanf(" %i", &aux);

            if (aux < 0 || aux > 3)
                printf("Opcion invalida, intentelo nuevamente\n");

        } while (aux < 0 || aux > 3);

        switch (aux)
        {
        case 0:
            printf("Ninguno de los peleadores cayo a la lona, sin penalizacion.\n\n");
            break;
        case 1:
            printf("Mayweather cayo a la lona, penalizacion de 2 puntos.\n\n");
            points_j1_b1 = points_j1_b1 - 2;
            points_j2_b1 = points_j2_b1 - 2;
            points_j3_b1 = points_j3_b1 - 2;
            break;
        case 2:
            printf("Canelo cayo a la lona, penalizacion de 2 puntos.\n\n");
            points_j1_b2 = points_j1_b2 - 2;
            points_j2_b2 = points_j2_b2 - 2;
            points_j3_b2 = points_j3_b2 - 2;
            break;
        case 3:
            printf("Ambos cayeron a la lona, penalizacion de 2 puntos.\n\n");
            points_j1_b1 = points_j1_b1 - 2;
            points_j2_b1 = points_j2_b1 - 2;
            points_j3_b1 = points_j3_b1 - 2;

            points_j1_b2 = points_j1_b2 - 2;
            points_j2_b2 = points_j2_b2 - 2;
            points_j3_b2 = points_j3_b2 - 2;

            break;
        }
        /* FIN PENALIZACION POR CAER A LA LONA */

        /* PUNTUACION DEL GANADOR Y PERDEDOR  DEL ROUND */

        if (round_winner == 1)
        {
            printf("GANADOR: MAYWEATHER, PUNTUACION TOTAL DEL ROUND: %i\n", points_r_b1);
            printf("PERDEDOR: CANELO, PUNTUACION TOTAL DEL ROUND: %i\n", points_r_b2);
        }
        else
        {
            printf("GANADOR: CANELO, PUNTUACION TOTAL DEL ROUND: %i\n", points_r_b2);
            printf("PERDEDOR: MAYWEATHER, PUNTUACION TOTAL DEL ROUND: %i\n\n", points_r_b1);
        }

        /* FIN PUNTUACION DEL GANADOR Y PERDEDOR  DEL ROUND */

        /* GANANCIA DE CADA BOXEADOR POR ROUND */
        printf("Mayweather ganara: %.2f$\n", gains_b1);
        printf("Canelo ganara: %.2f$\n\n", gains_b2);
        /* FIN GANANCIA DE CADA BOXEADOR POR ROUND */

        /* RESETEAR OPCIONES */
        round_winner = 0;
        points_r_b1 = 0;
        points_r_b2 = 0;
        votes_b1 = 0;
        votes_b2 = 0;
        votes_draw = 0;
        /* FIN RESETEAR OPCIONES */
    }

    printf("Rounds disputados: %i\n\n", rounds);
    printf("Mayweather\nRounds ganados: %i\nRounds perdidos: %i\n", wins_b1, loses_b1);
    printf("\nCanelo\nRounds ganados: %i\nRounds perdidos: %i\n\n", wins_b2, loses_b2);

    highest_card = ((points_j1_b1 + points_j1_b2) > (points_j2_b1 + points_j2_b2)) ? 1 : 2;

    if (highest_card == 1)
    {
        highest_card = ((points_j1_b1 + points_j1_b2) > (points_j3_b1 + points_j3_b2)) ? 1 : 3;
    }
    else
    {
        highest_card = ((points_j2_b1 + points_j2_b2) > (points_j3_b1 + points_j3_b2)) ? 2 : 3;
    }

    switch (highest_card)
    {
    case 1:
        printf("Carta de mayor valor: Juez 1\n Mayweather:%i, Canelo:%i\n\n", points_j1_b1, points_j1_b2);
        break;
    case 2:
         printf("Carta de mayor valor: Juez 2 \n Mayweather:%i, Canelo:%i\n\n", points_j2_b1, points_j2_b2);
        break;
    case 3:
        printf("Carta de mayor valor: Juez 3 \n Mayweather:%i, Canelo:%i\n\n", points_j3_b1, points_j3_b2);
        break;

    default:
        break;
    }

    if (wins_b1 > wins_b2)
    {
        printf("Ganador de la pelea: Mayweather");
    }
    else
    {
        printf("Ganador de la pelea: Canelo");
    }
}