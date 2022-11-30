// =================================================================
//
// File: activity.h
// Author: Diego Vega Camacho
// Date: 25/08/22
//
// =================================================================
#ifndef ACTIVITY_H
#define ACTIVITY_H

// =================================================================
// sumaIterativa. Calculate the sum from 1 to n with an iterative
// method.
//
// @param n	The maximum limit of the sum.
// @return	The result of the addition from 1 to n.
// @Complexity	??
// =================================================================
unsigned int sumaIterativa(unsigned int n) {
  int sum = 0; // Se define la variable para l ausma
  for(int i=1 ; i<=n; i++){ // Se crea un for para generar la suma Iterativa
    sum+=i; // Se va iterando en la variables
  }
	return sum; // Regresa la suma
}

// =================================================================
// sumaRecursiva. Calculate the sum from 1 to n with an recursive
// method.
//
// @param n	The maximum limit of the sum.
// @return	The result of the addition from 1 to n.
// @Complexity	??
// =================================================================
unsigned int sumaRecursiva(unsigned int n) {
  int sum; // Se define la variable para la suma
  if(n == 1){ // Condición de suma recursiva
    sum = 1; // Si n es 1 la función regresará 1
  }
  else{ 
    sum = n + sumaRecursiva(n-1); // Suma recursiva en variable sum que va sumando los numeros anteriores a n
  }
	return sum; // Retorna la suma
}

// =================================================================
// sumaDirecta. Calculate the sum from 1 to n with a mathematical
// method.
//
// @param n	The maximum limit of the sum.
// @return	The result of the addition from 1 to n.
// @Complexity	??
// =================================================================
unsigned int sumaDirecta(unsigned int n) {
  int sum = (n*(n+1))/2; // Metodo matematico 
	return sum; // Retorna la suma
}

#endif /* ACTIVITY_H */
