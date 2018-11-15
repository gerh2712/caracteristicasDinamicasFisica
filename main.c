/*  Includes    */
#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <ctype.h>
#include    <math.h>
#include    <locale.h>
#include    "funciones.h"

//Variables Globales
    #define cleanScreen "cls"
    //El número de vP y vL debe de coincidir
    #define vP 100
    #define vL 100
    #define lPP 100

    float mVP[vP], mVL[vL], mlPP[lPP];
    int numVP, numlPP, i, contaConsultas=0, contaMenu=0; 
    char vCorrectos;


//Prototipo de funciones
void nuevaConsulta(void);


int main()
{
    setlocale(LC_CTYPE, "Spanish");

    char menu;

    system(cleanScreen);
    
    if(contaMenu>0){
        ;
    }else {
        bienvenida();
    }

    
    do
    {
        contaMenu++;
        printf("\n\n¿Qué quieres hacer?");
        printf("\n\n\ta)Mostrar datos de la Brigada #4");
        printf("\n\n\tb)Realizar una nueva consulta");
        printf("\n\n\tc)Mostrar los últimos datos");
        printf("\n\n\td)Salir del programa");
        printf("\n\n\tIntroduce una opción: ");
        scanf("%c", &menu);
        menu = toupper(menu);

        switch(menu){

        case 'A':
            bienvenida();
            break;
        
        case 'B':            
            nuevaConsulta();
            contaConsultas++;
            break;

        case 'C':       
            system(cleanScreen);
            if(contaConsultas>0){

            }else {
                printf("\n\nParece que no has hecho ninguna consulta anteriormente, intenta a realizar una consulta antes\n\n");
                system("pause");
                return(main());
            }
            break;

        case 'D':            
            exit(0);
            break;

        default:
            system(cleanScreen);
            printf("\n\nEscoge una opción válida (a - b - c - d)");
            break;

        }

    } while (menu!='A' && menu!='B');
    

    

    
    


    
    return 0;
}


/*  Funciones   */

//Ejecuta el programa completo
void nuevaConsulta(void){

    //Bienvenida   
    bienvenida();

    //Instrucciones
    printf("\n\nNecesitamos saber cuántos valores patrón vas a utilizar, así como si tienes el promedio de las lecturas por valor patrón, o si vas a introducir las lecturas.\n\n\tNOTA: El número de lecturas por valor patrón debe de ser el mismo para todos los valores patrón.\n\n\tNOTA: Puedes introducir un máximo de %i VALORES PATRÓN y de %i LECTURAS POR PATRÓN", vP, lPP);
    printf("\n\n\t|   Valores Patrón (x)  |   Valores Leídos Promedio (y) |\n\n");
    system("pause");
    system(cleanScreen);

    //Pide la cantidad de valores patrón
    do
    {
        printf("\n\n\tIntroduce cuántos valores patrón vas a utilizar (0-50): ");
        scanf("%i", &numVP);
        
        if (numVP<=0 || numVP>vP) {
            system(cleanScreen);
            printf("\n\nERROR:  Debes introducir un mínimo de 1 valor patrón y un máximo de %i valores patrón", vP);
            printf("\n\nIntenta de nuevo...");
        }
        
    } while (numVP<=0 || numVP>vP);

    
    //Llena el arreglo de valores patrón y verifica que sean los valores deseados 
    do
    {
        system(cleanScreen);
        printf("\n\nAhora te vamos a pedir que introduzcas los valores patrón.\n\n\tIMPORTANTE: Debes de tener cuidado, ya que aceptaremos valores positivos y negativos decimales");
        llenarArreglo(mVP, numVP);
        system(cleanScreen);        
        
        do
        {
            //Muestra el arreglo
                printf("\n\nIntroduciste los siguientes valores:    ");
                printf("\n\n\t_________________________________________________");
                printf("\n\n\t|   Valor Patrón          |     Es igual a      |");
            for(i=0; i<numVP; i++){
                printf("\n\n\t_________________________________________________");
                printf("\n\n\t|   Valor Patrón [%i]     |     %.2f            |", i+1, mVP[i]);
            }
                printf("\n\n\t_________________________________________________");
                printf("\n\n");
            
            //Pregunta si los valores son correctos
            printf("\n\n't¿Los valores que instroduciste son correctos?");
            printf("\n\nS)Sí    N)No   : ");
            while(getchar()!='\n');
            scanf("%c", &vCorrectos);
            vCorrectos = toupper(vCorrectos);
            printf("\n\n");

            if(vCorrectos!='S' && vCorrectos!='N'){
                system(cleanScreen);
                printf("\n\nEscoge una opción válida...");
            }

        } while (vCorrectos!='S' && vCorrectos!='N');
        

    } while (vCorrectos=='N');
    vCorrectos = 'N';


}

