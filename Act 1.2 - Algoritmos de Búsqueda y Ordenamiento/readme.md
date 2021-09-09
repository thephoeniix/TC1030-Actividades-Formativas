


# Actividad 1.2 
## Ordena Selección 
**Analisis de complejidad temporal**
El algoritmo utiliza dos ciclos para ordenar el arreglo, se va acomodando si el elemento es menor del que se va a recorrer.
- Complejidad en el peor de los casos es **O(n^2)**
## Ordena Burbuja
**Analisis de complejidad tempora**
El algoritmo recorre ciclos anidados hace el cambio cada que cuentra el valor mayor y lo mueve al final.  
- Complejidad en el peor de los casos es **O(n^2)**
## Ordena Merge
**Analisis de complejidad temporal**
Se divide el arreglo por mitades (1/2, 1/4, 1/8, etc...) usando recursividad para poder ordenarlo y junatarlo al final con el orden correcto. 
- Complejidad en el peor de los casos es **O(nlog(n))**

## Busqueda Secuencial
**Analisis de complejidad temporal**
EL algoritmo utiliza un ciclo que compara el valor ingresado en el arreglo hasta encontrarlo. Si se encuentra se imprime la posicion del valor, sino se imprime -1. 
- Complejidad en el peor de los casos es **O(n)**

## Busqueda Binaria
**Analisis de complejidad temporal**
El algoritmo se divide a la mitad y compara los elementos del mid hasta el high/low, sino contiua hasta encontrarlo . 
- Complejidad en el peor de los casos es **O(log(n))**
