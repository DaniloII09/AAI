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
  Funciones para ordenar un arreglo de enteros utilizando el
  Merge Sort
*/
//Función que combina los resultados de dos mitades
void merge(int* A, int p, int q, int r){
    //Variables auxiliares para los recorridos, y que
    //funcionaran como contadores de las pilas
    int i, j;

    //Se calculan los tamaños de las dos mitades
    int n1 = q - p + 1;
    int n2 = r - q;

    //Se preparan las pilas, ambas con una celda extra
    int L[n1+1], R[n2+1];

    //Se copia la mitad izquierda en la pila L
    for(i = 0; i < n1; i++)
        L[i] = A[p+i];
    //Se copia la mitad derecha en la pila R
    for(j = 0; j < n2; j++)
        R[j] = A[q+j+1];

    //Se coloca un dato enorme al fondo de cada pila
    L[n1] = R[n2] = INT_MAX;
    //Se reinician los contadores de las pilas
    i = j = 0;

    //Se recorre el arreglo de entrada de inicio a fin,
    //el objetivo no es utilizar los datos, si no que 
    //recorrer las posiciones
    for(int k = p; k <= r; k++)
        //Se verifica quién es más pequeño: el tope de L
        //o el tope de R
        if(L[i] < R[j]){ //El tope de L es el más pequeño
            //El tope de L se coloca en la posición actual
            //del recorrido
            A[k] = L[i];
            //Se avanza el contador de L
            i++;
        }else{ //El tope de R es el más pequeño
            //El tope de R se coloca en la posición actual
            //del recorrido
            A[k] = R[j];
            //Se avanza el contador de R
            j++;
        }
}
//Función principal del método
void merge_sort(int* A, int p, int r){
    //Se verifica que el arreglo tenga al menos
    //2 datos para poder proceder.
    //Si p == r, solo hay un dato.
    //Si p > r, es un arreglo no válido.
    if(p < r){
        //Se calcula el punto de corte.
        //El floor es automático por casteo del
        //resultado a tipo int
        int q = (p+r)/2;

        //Se ordena la mitad izquierda
        merge_sort(A, p, q);
        //Se ordena la mitad derecha
        merge_sort(A, q+1, r);

        //Se combinan los resultados de las dos
        //mitades
        merge(A, p, q, r);
    }
}

int depth = 0;
void printIndent() { for (int i=0;i<depth;i++) cout << "  "; }

void merge_sort_trace(int* A, int p, int r){
    printIndent(); cout << "merge_sort("<<p<<","<<r<<")\n";
    if (p < r) {
        int q = (p + r) / 2; // en C++ int ya trunca (floor)
        depth++; merge_sort_trace(A, p, q); depth--;
        depth++; merge_sort_trace(A, q+1, r); depth--;
        printIndent(); cout << "merge("<<p<<","<<q<<","<<r<<")\n";
        merge(A, p, q, r);
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
    while(size <= 0) {
        cout << "Ingrese una longitud valida: ";
        cin >> size;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int* A = random_array(size);

    cout << "Arreglo antes de ordenar:";
    show_array(A,size);

    //Se ejecuta el ordenamiento
    merge_sort_trace(A,0,size-1);
    //merge_sort(A,0,size-1);
    
    cout << "\nArreglo despues de ordenar: ";
    show_array(A,size);

    system("pause");
    return 0;
}
