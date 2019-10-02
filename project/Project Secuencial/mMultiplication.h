//mMultiplication es una función que hace la multiplicación componente a componente de dos matrices 3x3 y devuelve la suma de los componentes de la matriz resultante
#include<stdio.h>


float mMultiplication(float M[3][3], float f1[3][3]){
    float resultado=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            resultado=resultado+M[i][j]*f1[i][j];
        }
    }
    return resultado;
}