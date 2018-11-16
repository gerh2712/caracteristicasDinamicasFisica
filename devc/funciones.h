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
#include    <locale.h>
#define cleanScreen "cls"

/*    Prototipo de funciones  */
void bienvenida();
void llenarArreglo(float arreglo[], int arregloSize);
float pendiente(float arregloX[],float arregloY[],int sumatoriaSize);
float ordenada(float arregloX[],float arregloY[],int sumatoriaSize);
float sumatoria(float arregloSumatoria[],int sumatoriaSize);
float producto(float arregloX[],float arregloY[],int sumatoriaSize);
float cuadrado(float arregloSumatoria[],int sumatoriaSize);
float Precision(float arregloLecturas[],int lecturasSize, float promedio);
float Exactitud(float patron, float promedio);

/*    Funciones   */

//Bienvenida
void bienvenida(){
    /*  Da el nombre de las personas que realizaron el programa */
    system("cls"); 
    printf("\n\nPrograma que determina las características dinámicas de un instrumento.");
    printf("\n\n\tRealizado por la Brigada #4: ");
    printf("\n\n\t\tBueno Hernández Jorge Gerardo");
    printf("\n\n\t\tGarcía Figueroa Mungía Alberto");
    printf("\n\n\t\tMartinez Olivarez Ángel");
    printf("\n\n\t\tMoreno Peralta Ángel Eduardo");
    printf("\n\n\t\tRendón Organis Homero\n\n");
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
//Obtiene la pendiente
float pendiente(float arregloX[],float arregloY[],int sumatoriaSize){
      float sumatoriaX,sumatoriaY,sumatoriaXY,sumatoriaX2,pendiente=0;
      sumatoriaX= sumatoria(arregloX, sumatoriaSize);
      sumatoriaY= sumatoria(arregloY,sumatoriaSize);
      sumatoriaXY= producto(arregloX,arregloY,sumatoriaSize);
      sumatoriaX2= cuadrado(arregloX,sumatoriaSize);
      pendiente=(((sumatoriaSize*sumatoriaXY)-(sumatoriaX*sumatoriaY))/((sumatoriaSize*sumatoriaX2)-(pow(sumatoriaX,2))));
      return pendiente;
}
//Obtiene la ordenada
float ordenada(float arregloX[],float arregloY[],int sumatoriaSize){
      float sumatoriaX,sumatoriaY,sumatoriaXY,sumatoriaX2,ordenada=0.0,m=0.0;
      sumatoriaX= sumatoria(arregloX, sumatoriaSize);
      sumatoriaY= sumatoria(arregloY,sumatoriaSize);
      sumatoriaXY= producto(arregloX,arregloY,sumatoriaSize);
      sumatoriaX2= cuadrado(arregloX,sumatoriaSize);
      m= pendiente(arregloX,arregloY,sumatoriaSize);
      ordenada=(((sumatoriaY)-(m*sumatoriaX))/(sumatoriaSize));
      return ordenada;
}
//Obtiene la sumatoria
float sumatoria(float arregloSumatoria[],int sumatoriaSize){
      int i;
      float cntSumatoria=0.0;
      for(i=0;i<sumatoriaSize;i++){
            cntSumatoria+=arregloSumatoria[i];
      }
}
//Obtiene el producto de xy
float producto(float arregloX[],float arregloY[],int sumatoriaSize){
      int i;
      float cntSumatoria=0.0;
      for(i=0;i<sumatoriaSize;i++){
            cntSumatoria+= arregloX[i]*arregloY[i];
      }
}
//Obtiene la sumatoria de valores al cuadrado
float cuadrado(float arregloSumatoria[],int sumatoriaSize){
      int i;
      float cntSumatoria=0.0;
      for(i=0;i<sumatoriaSize;i++){
            cntSumatoria+= pow(arregloSumatoria[i],2);
      }
}


//Obtiene el promedio de varias lecturas
float promedio(float arregloLecturas[],int lecturasSize){
      int i;
	float promedio,cntCal=0.0;
	for(i=0;i<lecturasSize;i++){
		cntCal+=arregloLecturas[i];
	}
	promedio = cntCal/lecturasSize +.0;
	return promedio;
}

//Obtiene el valor más alejado
float valorAlejado(float arregloLecturas[],int lecturasSize){
      float diferencia[100],diferen=0,valorA=0;
      int i;
      
      for(i=0;i<lecturasSize;i++){
      
            diferen = fabs(arregloLecturas[i] - promedio(arregloLecturas,lecturasSize));
      
            diferencia[i]=diferen;
      }

      valorA= diferencia[0];

      for(i=0; i<lecturasSize; i++){

            if(diferencia[i]>=valorA){
                  valorA = arregloLecturas[i];
            }

      }
      
    
      return valorA;
      
}
//Calcula el error de exactitud
//%EE= |(Vp-Vl)/Vp| * 100
//%EP= |(Vl-Vla)/Vl| * 100
//%E= 100% - %EE
//%P= 100% -$EP

float Exactitud(float patron, float promedio){
     float exactitud;

     exactitud = fabs((patron-promedio)/patron)*100;

     exactitud = 100 - exactitud; 

     return exactitud;
      
} 

float Precision(float arregloLecturas[],int lecturasSize, float promedio){
      
      float precision;

      precision = fabs(((promedio-valorAlejado(arregloLecturas, lecturasSize))/promedio))*100;

      precision = 100-precision;

      return precision;

}
