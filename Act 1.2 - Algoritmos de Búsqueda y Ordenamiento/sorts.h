/*
Karina Fernanda Maldonado Murillo 
A01707516
TC1030 Actividades Formativas
*/

#ifndef sorts_h
#define sorts_h

#include <vector>
#include <iostream>
#include <list>

using namespace std;

template < class T >
class Sorts {
  private:
    void swap(vector<T>&v, int, int); 
    void copyArray(vector<T>& , vector<T>& , int , int );
    void mergeArray(vector<T>& A, vector<T>& B, int i, int j, int k);
    void mergeSplit(vector<T>& , vector<T>& , int , int ); 

  public:
    void ordenaSeleccion(vector<T>&);
    void ordenaBurbuja(vector<T>&);
    void ordenaMerge(vector<T>&);
    int busqBinaria(vector<T>&, int);
    int busqSecuencial(vector<T>&, int);
};

template <class T>
void Sorts<T>::swap(vector<T>&v, int i, int j) { //cambia la posición 
    T aux = v[i]; //& puntero
    v[i] = v[j];
    v[j] = aux; //metafora de vaso de agua
}

template <class T>
void Sorts<T>::ordenaSeleccion(vector<T> &v){ 
  int pos; //variable posición

    for (int i = v.size() - 1; i > 0; i--) { //va de izq a derecha
        pos = 0; //posicion inicia en 0
        for (int j = 1; j <= i; j++) { //mientras j sea menor a i (hasta topar con i)
			//j=1 porque necesita diferenciarse con pos
            if (v[j] > v[pos]) {
                pos = j; //j se guarda en pos mientras j sea mayor a pos
            }
        }

        if (pos != i) { //si pos es diferente a i se hace el swap
            swap(v, i, pos);
        }
    }
}

template <class T>
void Sorts<T>::ordenaBurbuja(vector<T> &v) { //mientras menor al tamaño y mayor a 0 

    for (int i = v.size() - 1; i > 0; i--) { //mientras sea menor el tamaño y mayor a 0 
        for (int j = 0; j < i; j++) { 
            if (v[j] > v[j + 1]) {
                swap(v, j, j + 1); 
            }
        }
    }

}

template <class T>
int Sorts<T>::busqSecuencial(vector<T> &v, int val) {
    for (int i = 0; i < v.size(); i++) {
        if (val == v[i])
            return i;
    }
    return -1;
}


template <class T>
int Sorts<T>::busqBinaria(vector<T> &v, int val) {
  ordenaSeleccion(v);
    int mid;
    int low = 0;
    int high = v.size() - 1;

    while (high > low) {
        mid = (high + low) / 2;
        if (val == v[mid]) {
            return mid;
        } else if (val < v[mid]) {
            high = mid - 1;
        } else if (val > v[mid]) {
            low = mid + 1;
        }
    }
    return -1;
}

template <class T>
void Sorts<T>::ordenaMerge(vector<T> &v) {
    vector<T> aux(v.size()); 
    mergeSplit(v, aux, 0, v.size() - 1);
}

template <class T>
void Sorts<T>::mergeSplit(vector<T> &A, vector<T> &B, int low, int high) {
    int mid;

    if ( (high - low) < 1 ) {
        return; //caso base
    }
    mid = (high + low) / 2; //saca el mid 
    mergeSplit(A, B, low, mid);
    mergeSplit(A, B, mid + 1, high);
    mergeArray(A, B, low, mid, high);
    copyArray(A, B, low, high);
}

template <class T>
void Sorts<T>::mergeArray(vector<T> &A, vector<T> &B, int low, int mid, int high) {
    int i, j, k;

    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid &&j <= high) {
        if (A[i] < A[j]) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
        k++;
    }
    if (i > mid) {
        for (; j <= high; j++) {
            B[k++] = A[j];
        }
    } else {
        for (; i <= mid; i++) {
            B[k++] = A[i];
        }
    }
}

template <class T>
void Sorts<T>::copyArray(vector<T> &A, vector<T> &B, int low, int high) {
    for (int i = low; i <= high; i++) {
        A[i] = B[i]; //se hace la copia del arreglo 
    }
}




#endif /* SORTS_H_ */
