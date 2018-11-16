//Datos conocidos
/*

ERROR DE EXACTITUD, ERROR DE PRECISION, EXACTITUD Y PRECISION

%EE= |(Vp-Vl)/Vp| * 100
%EP= |(Vl-Vla)/Vl| * 100
%E= 100% - %EE
%P= 100% -$EP
 Donde:
      %EE= Error de exactitud
      %EP= Error de precisión
      %E= Exactitud
      %P= Precision
      Vp = Valor Patrón
      Vl = Valor registrado (promedio)
      Vla = Valor registrado (Del promedio de todos los datos) más a lejado respecto al promedio

SENSIBILIDAD Y ERROR ALEATORIO

S= Vl/Vp ->Para 1 valor patrón y 1 lectura

m=S= dVl/dVp  -> Para varias entradas de datos

      m= S = {n(Pxy) - (Px)(Py)} / {n(XcuadradoP) - (cuadradoX)}

            De la fórmula y = mx + b

            b =  {n(Py) (XcuadradoP) - (Pxy)(Px)} / {n(XcuadradoP) - (cuadradoX)}

Donde:
      S = Sensibilidad
      d(prefijo) = Delta (diferencia)
      n = Número de lecturas
      b = Error aleatorio

Calcular la regresión lineal para la sensibilidad (Cuando hay más de 1 valor patron y más de y valor registrado , los valores registrados son el promedio si se hicieron varias comprobaciones):
      Valores patron = Variable Dependiente y
      Valores ingresado = Variable dependiente x

      Obetener:
            Px = Promedio de x
            Py = Promedio de y
            Pxy = Promedio de x*y (donde se multiplica cada valor registrado por su respectivo valor patrón, y la suma de todos los resultados es el promedio buscado)
            cuadradoX = Px^2 , Primero se obtiene el promedio de x y luego el promedio se elva al cuadrado
            XcuadradoP = Donde primero se eleva el valor de x al cuadrado y luego se obtiene el promedio
                  Donde:
                        El prefijo P = Promedio


TODO: Es necesario terminar de plantear esta fórmula
INCERTIDUMBRE

      dm = +- Sn / raiz de (n)

      Donde:

            d (prefijo): Delta o diferencia
            m =
            Sn = Desviación estándar
            n = numero de lecturas

*/
#define cleanScreen "cls"

/*    Prototipo de funciones  */
void bienvenida();
void llenarArreglo(float arreglo[], int arregloSize);
void mostrarArreglo(float arreglo[], int arregloSize, char variosV, char tipoValor[50], char lecturaValor[50]);

/*    Funciones   */

//Bienvenida
void bienvenida(){
    /*  Da el nombre de las personas que realizaron el programa */
    system("cls"); 
    printf("\n\nPrograma que determina las características dinámicas de un instrumento.");
    printf("\n\n\tRealizado por la Brigada #4: ");
    printf("\n\n\t\tBueno Hernández Jorge Gerardo");
    printf("\n\n\t\tMoreno Peralta Ángel Eduardo");
    printf("\n\n\t\tBueno Hernández Jorge Gerardo ");
    printf("\n\n\t\tBueno Hernández Jorge Gerardo ");
    printf("\n\n\t\tBueno Hernández Jorge Gerardo \n\n");
    system("pause");
    system(cleanScreen);
}

//Llena un arreglo de patrones
void llenarArreglo(float arreglo[], int arregloSize){
      int i;

      for(i=0; i<arregloSize; i++){
            printf("\n\nIntroduce el valor [%i]:     ", i+1);
            scanf("%f", &arreglo[i]);
      }

}

//Obtiene el promedio de varias lecturas
float promedio(float arregloLecturas[],int lecturasSize){
      int i,cntCal=0;
	float promedio;
	for(i=0;i<lecturasSize;i++){
		cntCal+=cntCal+arregloLecturas[i];
	}
	promedio = cntCal/lecturasSize +.0;
	return promedio;
}

//Obtiene el valor más alejado
float valorAlejado(float arregloLecturas[],int lecturasSize){
      float diferencia[100],diferen=0,valorA=0;
      int i;
      for(i=0;i<lecturasSize;i++){
            diferen=arregloLecturas[i]-promedio(arregloLecturas,lecturasSize);
            if(diferen<0){
                  diferen = diferen*-1;
            }
            diferencia[i]=diferen;
      }
      
      for(i=0;i<lecturasSize;i++){
            if(diferencia[i]>valorA){
                valorA = diferencia[i];  
            }

      }
      return valorA;
      
}
//Calcula el error de exactitud
//%EE= |(Vp-Vl)/Vp| * 100
//%EP= |(Vl-Vla)/Vl| * 100
//%E= 100% - %EE
//%P= 100% -$EP

void Exactitud(float arregloPatron[],int patronSize, float arregloLecturas[],int lecturasSize){
      float errorExactitud[100],exactitud[100];
      int i;
      for(i=0;i<patronSize;i++){          
            errorExactitud[i]=((arregloPatron[i]-(promedio( arregloLecturas, lecturasSize)))/arregloPatron[i]);
            if(errorExactitud[i]<0){
                  errorExactitud[i]= errorExactitud[i]*(-100);
            }else{
                  errorExactitud[i] = errorExactitud[i]*(100);
            }
            exactitud[i]= 100 - errorExactitud[i];
            printf("\nEl Porcentaje de Exactitud del Valor Patron %.2f es %.2f",arregloPatron[i],exactitud[i]);
      }
      
} 

void Precision(float arregloPatron[],int patronSize,float arregloLecturas[],int lecturasSize){
      float errorPrecision[100],precision[100];
      int i;
      for(i=0;i<patronSize;i++){
            errorPrecision[i]=((arregloLecturas[i]-valorAlejado(arregloLecturas, lecturasSize))/arregloLecturas[i]);
            if(errorPrecision[i]<0){
                  errorPrecision[i]=errorPrecision[i]*-100;
            }else{
                  errorPrecision[i]=errorPrecision[i]*100;
            }
            precision[i]= 100 - errorPrecision[i];
            printf("\nEl porcentaje de Precision del Valor Patron %.2f es %.2f. ",arregloPatron[i],precision[i]);
      }
}