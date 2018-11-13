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

/*    Prototipo de funciones  */
void llenarArreglo(float arreglo[], int arregloSize);
void mostrarArreglo(float arreglo[],int arregloSize);

/*    Funciones   */

//Llena un arreglo de patrones
void llenarArreglo(float arreglo[], int arregloSize){
      int i;

      for(i=0; i<arregloSize; i++){
            printf("\n\nIntroduce el valor patron [%i]", i+1);
            scanf("%f", &arreglo[i]);
      }

}

//Muestra el arreglo
void mostrarArreglo(float arreglo[], int arregloSize){
      int i;
      
      for(i=0; i<arregloSize; i++){
            printf("\n\nEl valor patrón [%i] es: %.2f", i+1, arreglo[i]);
      }
}
