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
                printf("\n\nTe mostraremos los último resultados");

                //Muestra las matrices relacionadas VP y VLP
                    printf("\n\nIntroduciste los siguientes valores:    ");
                    printf("\n\n\t| Valor Patrón | Lectura Promedio | Porcentaje Exactitud | Porcentaje Presición  | Error Exactitud | Error Precision |");
                    float patron, pPromedio, presci;
                for(i=0; i<numVP; i++){
                    patron = mVP[i];
                    pPromedio = mVL[i];
                    presci = mP[i];
                    printf("\n\n\t| %.2f | %.2f | %.2f | %.2f | %.2f | %.2f |", patron, pPromedio, Exactitud(patron, pPromedio), presci, 100 - Exactitud(patron, pPromedio), 100 - presci);
                    
                }
                printf("\n\n");

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
            printf("\n\nEscoge una opción válida (a - b - c - d)");
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


    //Pide la cantidad de lecturas por valor  patrón
    system(cleanScreen);
    do
    {
        printf("\n\n\tIntroduce cuántas lecturas vas a utilizar por valor patrón(0-50)\n\n\tIMPORTANTE: Se realizará el mismo número de lecturas para todos los valores patrón\n\nIntroduce un valor:    ");
        scanf("%i", &numlPP);
        
        if (numlPP<=0 || numlPP>vL) {
            system(cleanScreen);
            printf("\n\nERROR:  Debes introducir un mínimo de 1 valor patrón y un máximo de %i lecturas para cada valor patrón", vP);
            printf("\n\nIntenta de nuevo...");
        }
        
    } while (numlPP<=0 || numlPP>vL);


    //Obtiene los valores leídos (Saca promedios)
    system(cleanScreen);
    printf("\n\nAhora te vamos a pedir que introduzcas las lecturas para cada valor patrón.\n\n\tIMPORTANTE: Te pediremos todas las lecturas de un valor patrón antes de pasar a las lecturas del siguiente valor patrón\n\n\tIMPORTANTE: Debes de tener cuidado, ya que aceptaremos valores positivos y negativos decimales\n\n");
    system("pause");    
    system(cleanScreen);


    for( j = 0; j < numVP; j++)
    {
        //Llena el arreglo de lecturas por  patrón y verifica que sean los valores deseados 
        do
        {
            printf("\n\nPor favor, introduce las lecturas para el valor patrón %.2f\n\n", mVP[j]);

            //Llena el arreglo de lecturas por patrón
            llenarArreglo(mlPP, numlPP);        
            system(cleanScreen);   
            
            do
            {

                //Muestra el arreglo
                    printf("\n\nIntroduciste los siguientes valores:    ");
                    printf("\n\n\t_____________________________________");
                    printf("\n\n\t|   Valor Patrón [%.2f] es igual a: |", mVP[j]);
                for(i=0; i<numlPP; i++){
                    printf("\n\n\t_____________________________________");
                    printf("\n\n\t|               %.2f                |", mlPP[i]);
                }
                    printf("\n\n\t_____________________________________");
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

        prom = promedio(mlPP, numlPP);
        pres = Precision(mlPP, numlPP, prom);

        //Llena el arreglo de lecturas promedio  por patrón
        mVL[j] = prom;   
        mP[j] = pres;     

        system(cleanScreen);
    }
    //TODO: AQUÍ SE ROMPE
    //Como si hiciera un return(main);


    //Te mostraremos los valores patrones y sus promedios
    printf("\n\nTe mostraremos los resultados");

    //Muestra las matrices relacionadas VP y VLP
        printf("\n\nIntroduciste los siguientes valores:    ");
        printf("\n\n\t|\tValor Patrón\t|\tLectura Promedio\t|\tPorcentaje Exactitud\t|\tPorcentaje Presición\t|\tError Exactitud\t|\tError Precision\t|");
        float patron, pPromedio, presci, exact;
    for(i=0; i<numVP; i++){
        patron = mVP[i];
        pPromedio = mVL[i];
        presci = mP[i];
        exact = Exactitud(patron, pPromedio);
        printf("\n\n\t|\t%.2f\t|\t%.2f\t|\t%.2f\t|\t%.2f\t|\t%.2f\t|\t%.2f\t|", patron, pPromedio, exact, presci, (100 - exact), (100 - presci));
    }
    printf("\n\n");

    system("pause");



}

