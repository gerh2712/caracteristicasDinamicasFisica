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
    //El n�mero de vP y vL debe de coincidir
    #define vP 100
    #define vL 100
    #define lPP 100

    float mVP[vP], mVL[vL], mlPP[lPP],  mP[vP], prom , pres;
    int numVP, numlPP, i, j, contaConsultas=0, contaMenu=0; 
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
        printf("\n\n�Qu� quieres hacer?");
        printf("\n\n\ta)Mostrar datos de la Brigada #4");
        printf("\n\n\tb)Realizar una nueva consulta");
        printf("\n\n\tc)Mostrar los �ltimos datos");
        printf("\n\n\td)Salir del programa");
        printf("\n\n\tIntroduce una opci�n: ");
        scanf("%c", &menu);
        menu = toupper(menu);

        switch(menu){

        case 'A':
            bienvenida();
            return(main());
            break;
        
        case 'B':            
            nuevaConsulta();
            contaConsultas++;
            return(main());
            break;

        case 'C':   

            system(cleanScreen);

            if(contaConsultas>0){

                //Te mostraremos los valores patrones y sus promedios
                printf("\n\nTe mostraremos los �ltimo resultados");

                //Muestra las matrices relacionadas VP y VLP
                    printf("\n\nIntroduciste los siguientes valores:    ");
                    printf("\n\n\t| Valor Patr�n | Lectura Promedio | Porcentaje Exactitud | Porcentaje Presici�n  | Error Exactitud | Error Precision |");
                    float patron, pPromedio, presci;
                for(i=0; i<numVP; i++){
                    patron = mVP[i];
                    pPromedio = mVL[i];
                    presci = mP[i];
                    printf("\n\n\t| %.2f | %.2f | %.2f | %.2f | %.2f | %.2f |", patron, pPromedio, Exactitud(patron, pPromedio), presci, 100 - Exactitud(patron, pPromedio), 100 - presci);
                    
                }
                printf("\n\n");
                
                //Modelo Matem�tico
			    printf("\n\nA continuaci�n te mostraremos un modelo matem�tico como el siguiente: ");
			    printf("\n\n\ty = mx + b");
			    printf("\n\n\t\tDonde m = pendiente = sensibilidad");
			    printf("\n\n\t\tDonde b = ordenada al origen = error aleatorio o experimental (+ -) ");
			
			    printf("\n\n\t La ecuacion es: y = (%.2f)x + (%.2f)",pendiente(mVP,mVL,numVP),ordenada(mVP,mVL,numVP));
			
			    system("pause");

            }else {
                printf("\n\nParece que no has hecho ninguna consulta anteriormente, intenta a realizar una consulta antes\n\n");
                system("pause");
                return(main());
            }
            break;

        case 'D':    
            printf("\n\n");
            exit(0);
            break;

        default:
            system(cleanScreen);
            printf("\n\nEscoge una opci�n v�lida (a - b - c - d)");
            return(main());
            break;

        }

    } while (menu!='A' && menu!='B');
    

    

    
    


    
    return 0;
}


/*  Funciones   */

//Ejecuta el programa completo
void nuevaConsulta(void){

    system(cleanScreen);
    //Instrucciones
    printf("\n\nNecesitamos saber cu�ntos valores patr�n vas a utilizar, as� como si tienes el promedio de las lecturas por valor patr�n, o si vas a introducir las lecturas.\n\n\tNOTA: El n�mero de lecturas por valor patr�n debe de ser el mismo para todos los valores patr�n.\n\n\tNOTA: Puedes introducir un m�ximo de %i VALORES PATR�N y de %i LECTURAS POR PATR�N", vP, lPP);
    printf("\n\n\t|   Valores Patr�n (x)  |   Valores Le�dos Promedio (y) |\n\n");
    system("pause");
    system(cleanScreen);

    //Pide la cantidad de valores patr�n
    do
    {
        printf("\n\n\tIntroduce cu�ntos valores patr�n vas a utilizar (0-50): ");
        scanf("%i", &numVP);
        
        if (numVP<=0 || numVP>vP) {
            system(cleanScreen);
            printf("\n\nERROR:  Debes introducir un m�nimo de 1 valor patr�n y un m�ximo de %i valores patr�n", vP);
            printf("\n\nIntenta de nuevo...");
        }
        
    } while (numVP<=0 || numVP>vP);

    
    //Llena el arreglo de valores patr�n y verifica que sean los valores deseados 
    do
    {
        system(cleanScreen);
        printf("\n\nAhora te vamos a pedir que introduzcas los valores patr�n.\n\n\tIMPORTANTE: Debes de tener cuidado, ya que aceptaremos valores positivos y negativos decimales");
        llenarArreglo(mVP, numVP);
        system(cleanScreen);        
        
        do
        {
            //Muestra el arreglo
                printf("\n\nIntroduciste los siguientes valores:    ");
                printf("\n\n\t_________________________________________________");
                printf("\n\n\t|   Valor Patr�n          |     Es igual a      |");
            for(i=0; i<numVP; i++){
                printf("\n\n\t_________________________________________________");
                printf("\n\n\t|   Valor Patr�n [%i]     |     %.2f            |", i+1, mVP[i]);
            }
                printf("\n\n\t_________________________________________________");
                printf("\n\n");
            
            //Pregunta si los valores son correctos
            printf("\n\n't�Los valores que instroduciste son correctos?");
            printf("\n\nS)S�    N)No   : ");
            while(getchar()!='\n');
            scanf("%c", &vCorrectos);
            vCorrectos = toupper(vCorrectos);
            printf("\n\n");

            if(vCorrectos!='S' && vCorrectos!='N'){
                system(cleanScreen);
                printf("\n\nEscoge una opci�n v�lida...");
            }

        } while (vCorrectos!='S' && vCorrectos!='N');
        

    } while (vCorrectos=='N');
    vCorrectos = 'N';


    //Pide la cantidad de lecturas por valor  patr�n
    system(cleanScreen);
    do
    {
        printf("\n\n\tIntroduce cu�ntas lecturas vas a utilizar por valor patr�n(0-50)\n\n\tIMPORTANTE: Se realizar� el mismo n�mero de lecturas para todos los valores patr�n\n\nIntroduce un valor:    ");
        scanf("%i", &numlPP);
        
        if (numlPP<=0 || numlPP>vL) {
            system(cleanScreen);
            printf("\n\nERROR:  Debes introducir un m�nimo de 1 valor patr�n y un m�ximo de %i lecturas para cada valor patr�n", vP);
            printf("\n\nIntenta de nuevo...");
        }
        
    } while (numlPP<=0 || numlPP>vL);


    //Obtiene los valores le�dos (Saca promedios)
    system(cleanScreen);
    printf("\n\nAhora te vamos a pedir que introduzcas las lecturas para cada valor patr�n.\n\n\tIMPORTANTE: Te pediremos todas las lecturas de un valor patr�n antes de pasar a las lecturas del siguiente valor patr�n\n\n\tIMPORTANTE: Debes de tener cuidado, ya que aceptaremos valores positivos y negativos decimales\n\n");
    system("pause");    
    system(cleanScreen);


    for( j = 0; j < numVP; j++)
    {
        //Llena el arreglo de lecturas por  patr�n y verifica que sean los valores deseados 
        do
        {
            printf("\n\nPor favor, introduce las lecturas para el valor patr�n %.2f\n\n", mVP[j]);

            //Llena el arreglo de lecturas por patr�n
            llenarArreglo(mlPP, numlPP);        
            system(cleanScreen);   
            
            do
            {

                //Muestra el arreglo
                    printf("\n\nIntroduciste los siguientes valores:    ");
                    printf("\n\n\t_____________________________________");
                    printf("\n\n\t|   Valor Patr�n [%.2f] es igual a: |", mVP[j]);
                for(i=0; i<numlPP; i++){
                    printf("\n\n\t_____________________________________");
                    printf("\n\n\t|               %.2f                |", mlPP[i]);
                }
                    printf("\n\n\t_____________________________________");
                    printf("\n\n");
                
                //Pregunta si los valores son correctos
                printf("\n\n't�Los valores que instroduciste son correctos?");
                printf("\n\nS)S�    N)No   : ");
                while(getchar()!='\n');
                scanf("%c", &vCorrectos);
                vCorrectos = toupper(vCorrectos);
                printf("\n\n");

                if(vCorrectos!='S' && vCorrectos!='N'){
                    system(cleanScreen);
                    printf("\n\nEscoge una opci�n v�lida...");
                }

            } while (vCorrectos!='S' && vCorrectos!='N');
            

        } while (vCorrectos=='N');

        prom = promedio(mlPP, numlPP);
        pres = Precision(mlPP, numlPP, prom);

        //Llena el arreglo de lecturas promedio  por patr�n
        mVL[j] = prom;   
        mP[j] = pres;     

        system(cleanScreen);
    }



    //Te mostraremos los valores patrones y sus promedios
    printf("\n\nTe mostraremos los �ltimo resultados");

    //Muestra las matrices relacionadas VP y VLP
        printf("\n\nIntroduciste los siguientes valores:    ");
        printf("\n\n\t| Valor Patr�n | Lectura Promedio | Porcentaje Exactitud | Porcentaje Presici�n  | Error Exactitud | Error Precision |");
        float patron, pPromedio, presci;
    for(i=0; i<numVP; i++){
        patron = mVP[i];
        pPromedio = mVL[i];
        presci = mP[i];
        printf("\n\n\t| %.2f | %.2f | %.2f | %.2f | %.2f | %.2f |", patron, pPromedio, Exactitud(patron, pPromedio), presci, 100 - Exactitud(patron, pPromedio), 100 - presci);
        
    }
    printf("\n\n");


    //Modelo Matem�tico
    printf("\n\nA continuaci�n te mostraremos un modelo matem�tico como el siguiente: ");
    printf("\n\n\ty = mx + b");
    printf("\n\n\t\tDonde m = pendiente = sensibilidad");
    printf("\n\n\t\tDonde b = ordenada al origen = erro aleatorio o experimental (+ -) ");

    printf("\n\n\t La ecuacion es: y = (%.2f)x + (%.2f)",pendiente(mVP,mVL,numVP),ordenada(mVP,mVL,numVP));

    system("pause");



}


