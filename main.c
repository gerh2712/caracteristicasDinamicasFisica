/*  Includes    */
#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <ctype.h>
#include    <math.h>
#include    "funciones.h"

//Variables Globales


//Prototipo de funciones

int main()
{
    //Con estos define se puede ampliar la capacidad máxima del arreglo 
    #define vP 250 
    #define vL 250
    int numVP, numVL;
    float matrizValores[vP][vL];
    char datosCorrectos, menu;
    
    //Bienvenida    
    printf("\nPrograma que determina las características dinámicas de un instrumento.");
    printf("\n\tRealizado por la Brigada #4: ");
    printf("\n\t\tBueno Hernández Jorge Gerardo");
    printf("\n\t\tMoreno Peralta Ángel Eduardo");
    printf("\n\t\tBueno Hernández Jorge Gerardo ");
    printf("\n\t\tBueno Hernández Jorge Gerardo ");
    printf("\n\t\tBueno Hernández Jorge Gerardo ");
    printf("\n\nPara comenzar presione enter...\n\n\n");
    system("pause");
    system("cls");

    //Obtiene el número de valores patrón y leídos por patrón (el mismo para todos)
    do
    {
        
        //Obtine el número de patrones y lecturas y verifica que sean mayores a cero
        do
        {
            printf("\n\nNecesitamos saber cuántos valores patrones y cuántos valores introducidos vas introducir, máximo %i de valores patrón y %i de valores leídos por cada valor patrón", vP, vL);
            printf("\n\n\tNOTA: Será el mismo número de valores leídos para TODOS los valores patrones");

            printf("\n\nIntroduce el número de valores PATRÓN que vas a utilizar: ");
            scanf("%i", &numVP);

            printf("\n\nIntroduce el número de valores LEÍDOS que vas a utilizar: ");
            scanf("%i", &numVL);

            system("cls");

            if(numVP<=0 || numVL<=0 || numVP>250 || numVL>250){

                printf("\n\nTus valores son inválidos: ");
                printf("\n\n\t#Patrones: %i", numVP);
                printf("\n\n\t#Leídos: %i", numVL);
                printf("\n\nIntroduce valores en el rango permitido: 0 - %i o %i", vP, vL);

            }

        } while (numVP<=0 || numVL<=0);
                

        //Corrobora si los datos introducidos son los que el usuario desea
        do
        {
            printf("\n\n¿Los datos son correctos?: ");
            printf("\n\n\t#Patrones: %i", numVP);
            printf("\n\n\t#Leídos: %i", numVL);

            printf("\n\nS)Sí \tN)No\n\n");
            printf("\n(Introduce S o N):  "); 

            while(getchar()!='\n');
            scanf("%c", &datosCorrectos);
            datosCorrectos = toupper(datosCorrectos);

            if(datosCorrectos!='S' && datosCorrectos!='N'){
                system("cls");
                printf("\n\nPor favor, introduce una opción válida");
            }

        } while (datosCorrectos!='S' && datosCorrectos!='N');
        
        if(datosCorrectos=='N'){
            system("cls");
            printf("\n\nTe volveremos a preguntar los datos");
        }

    } while (datosCorrectos!='S');

    //Llena la matriz de los datos 
    llenarMatriz(matrizValores, vP, numVP, numVL);

    //Muestra un menú para que el usuario escoga qué quiere obtener
    system("cls");
    do
    {           
        printf("\n\n¿Qué quieres obtener?\n\n");
        printf("\n");
        printf("\n\n\ta) Promedio (Valores leídos) - Porcentaje de Error de Exactitud - Porcentaje de Exactitud");
        printf("\n\n\tb) Promedio (Valores leídos) - Porcentaje de Error de Precisión - Porcentaje de Precisión");
        printf("\n\n\tc) Sensibilidad del instrumento");
        printf("\n\n\td) Error aleatorio - Incertidumbre");
        printf("\n\n");
        
        while(getchar()!='\n');
        scanf("%c", &menu);
        menu = toupper(menu);
        
        switch (menu)
        {
            case 'A':
                //promedio
                //Porcentaje de Error de Exactitud 
                //Porcentaje de Exactitud
                break;

            case 'B':
                //promedio
                //Porcentaje de Error de Precisión
                //Porcentaje de Precisión
                break;

            case 'C':
                //Sensibilidad
                break;

            case 'D':
                //Error Aleatorio
                //Incertidumbre
                break;
        
            default:
                system("cls");
                printf("\n\nPor favor, introduce una opción válida");
                break;
        }
        

    } while (menu!='A' && menu!='B' && menu!='C' && menu!='D');
    


    
    return 0;
}

/*  Funciones   */



