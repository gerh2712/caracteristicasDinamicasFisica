/*  Includes    */
#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <ctype.h>
#include    <math.h>
#include    "funciones.h"

int main(void)
{
    int numVP, numVL;
    float matrizValores[numVP][numVL];
    char datosCorrectos;
    
    //Bienvenida
    system("cls");
    printf("\nPrograma que determina las características dinámicas de un instrumento.");
    printf("\n\tRealizado por: ");
    printf("\n\t\tBueno Hernández Jorge Gerardo");
    printf("\n\t\tMoreno Peralta Ángel Eduardo");
    printf("\n\t\tBueno Hernández Jorge Gerardo ");
    printf("\n\t\tBueno Hernández Jorge Gerardo ");
    printf("\n\t\tBueno Hernández Jorge Gerardo ");
    printf("\n\nPara comenzar presione enter...\n\n\n");
    system("pause");

    //Obtiene el número de valores patrón y leídos por patrón (el mismo para todos)
    do
    {
        
        //Obtine el número de patrones y lecturas y verifica que sean mayores a cero
        do
        {
            printf("\n\nNecesitamos saber cuántos valores patrones y cuántos valores introducidos vas introducir");
            printf("\n\n\tNOTA: Será el mismo número de valores leídos para TODOS los valores patrones");

            printf("\n\nIntroduce el número de valores PATRÓN que vas a utilizar: ");
            scanf("%i", &numVP);

            printf("\n\nIntroduce el número de valores LEÍDOS que vas a utilizar: ");
            scanf("%i", &numVL);

            system("cls");

            if(numVP<=0 || numVL<=0){

                printf("\n\nTus valores son inválidos: ");
                printf("\n\n\t#Patrones: %i", numVP);
                printf("\n\n\t#Leídos: %i", numVL);
                printf("\n\nIntroduce valores mayores a cero");

            }

        } while (numVP<=0 || numVL<=0);
                



        //Corrobora si los datos introducidos son los que el usuario desea
        do
        {
            printf("\n\n¿Los datos son correctos?: ");
            printf("\n\n\t#Patrones: %i", numVP);
            printf("\n\n\t#Leídos: %i", numVL);

            printf("\n\nS)Sí \tN)No");
            printf("\n(Introduce S o N)");
            fflush(stdin);
            scanf("%c", &datosCorrectos);
            datosCorrectos= toupper(datosCorrectos);

            if(datosCorrectos!='S' || datosCorrectos!='N'){
                system("cls");
                printf("\n\nPor favor, introduce una opción válida\n\n");
            }

        } while (datosCorrectos!='S' || datosCorrectos!='N');
        
        if(datosCorrectos=='N'){
            system("cls");
            printf("\n\nTe volveremos a preguntar los datos");
        }

    } while (datosCorrectos!='S');
    


    
    return 0;
}
