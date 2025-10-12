#include <bits/stdc++.h>
using namespace std;

/*
  Función para mostrar el contenido de un arreglo de enteros
*/
void show_array(int* A, int n){
    //Se abre un bracket para el arreglo
    cout << "[ ";
    //Se recorre el arreglo
    for(int i = 0; i < n; i++)
        //Se imprime la posición actual seguida de un espacio
        cout << A[i] << " ";
    //Se cierra el bracket del arreglo
    cout << "]\n";
}

/*
  Función para ordenar un arreglo de enteros utilizando el
  Método de la Burbuja
*/
void bubble_sort(int* A, int n){
    /* Recorrido Principal */
    //Se recorre el arreglo de izquierda a derecha desde la
    //primera posición y hasta la penúltima
    for(int j = 0; j < n-1; ++j) {
        /* Recorrido Secundario */
        //Se recorre el arreglo desde la primera posición y
        //hasta la posición previa a las celdas ya ordenadas
        for(int i = 0; i < n-j-1; ++i) {
            //Para la pareja actual, si el dato más grande de
            //los dos está a la izquierda, se hace un swap
            if(A[i] > A[i+1]){
                int temp = A[i];
                A[i] = A[i+1];
                A[i+1] = temp;
            }

            //Alternativa
            //if(A[i] > A[i+1]) swap(A[i], A[i+1]);
        }
    }
}

int* random_array(int n) {
    srand(time(0));

    int* A = new int[n];
    for (int i = 0; i < n; i++) {
        A[i] = rand() % ((n)*5) + 1;
    }

    return A;
}

int main(void){
    int size;

    cout << "Ingrese la longitud del arreglo: ";
    cin >> size;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (size <= 0)
    {
        cout << "Ingrese una longitud valida de arreglo: ";
        cin >> size;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int* A = random_array(size);

    cout << "Arreglo antes de ordenar: ";
    show_array(A,size);

    //Se ejecuta el ordenamiento
    bubble_sort(A,size);
    
    cout << "Arreglo despues de ordenar: ";
    show_array(A,size);

    return 0;
}
