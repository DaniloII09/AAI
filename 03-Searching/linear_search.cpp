#include "test_array.hpp"

using namespace std;

bool linear_search(int A[], int v, int size) {
    bool ans = false;

    for (int i = 0; i < size; i++) {
        if(A[i] == v) {
            ans = true;
            break;
        }
    }

    return ans;
}

int main(int argc, char** argv){
    //Se verifica que se haya invocado el programa proporcionando el dato a buscar
    if( argc != 2 ){
        cout << "El programa debe ejecutarse colocando el dato a buscar. >:|\n";
        exit(EXIT_FAILURE);
    }

    //Se extrae el dato a buscar del segundo argumento
    int v = atoi(argv[1]);
    
    //Se busca el dato utilizando búsqueda lineal
    if(linear_search(A, v, n)) cout << "El dato fue encontrado! :)\n";
    else cout << "El dato NO fue encontrado! :(\n";

    return 0;
}

