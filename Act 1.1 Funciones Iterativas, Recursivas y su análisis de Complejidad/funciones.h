

#include <iostream>

class Funciones{
  public:
    int sumaIterativa(int var);
    int sumaRecursiva(int var);
    int sumaDirecta(int var);
};

int Funciones::sumaIterativa(int var){
  int acum=0;
  for (int i=1;i<=var; i++){
    acum=acum+i; //llamada recursiva
  }
  return acum; //caso base
}

int Funciones::sumaRecursiva(int var){
  if (var==0){
    return 0; //caso base
  }
  else {
    return var+sumaRecursiva(var-1); //llamada recursiva
} }

int Funciones::sumaDirecta(int var){
  int suma=((var*(var+1))/2);
  return suma;
}

