#include <iostream>
#include <math.h>

void show_array(int* A, int size) {
  std::cout << "[ ";
  for (int i = 0; i < size; i++) {
    std::cout << A[i] << " ";
  }
  std::cout << "]\n";
}

int partition(int* A, int p, int r) {
  int temp = 0;
  int pivot = A[p], i = p + 1;

  for (int j = p + 1; j < r; j++) {
    //Los valores menores al pivote, se mueven a la izquierda
    if (A[j] < pivot) {
      temp = A[j];
      A[j] = A[i];
      A[i] = temp;
      i++;
    }
  }

  //El pivote queda con los valores menores a el a su izquierda y los mayores a su derecha
  //El pivote ya queda en su posición final
  temp = A[i - 1];
  A[i - 1] = A[p];
  A[p] = temp;

  //Se regresa el pivote en su nuevo sitio
  return i - 1;
}

void quick_sort(int* A, int p, int r) {
  if (p < r) {
    //Se obtiene el pivote
    int q = partition(A, p, r);

    //No se pasa el pivote como parametro porque es un dato ya ordenado

    //Mitad izquierda
    quick_sort(A, p, q - 1);
    //Mitad derecha
    quick_sort(A, q + 1, r);
  }
}

int* random_array(int size) {
  int* A = new int[size];
  srand(time(0));

  for (int i = 0; i < size; i++) {
    A[i] = rand() % (size * 5) + 1;
  }

  return A;
}

int main(void) {
  int size = 0;

  std::cout << "\nEnter the array size: ";
  std::cin >> size;
  std::cin.clear();
  while (size <= 1) {
    std::cout << "\nNot a valid number, please enter a valid array size: ";
    std::cin >> size;
    std::cin.clear();
  }

  int* A = random_array(size);

  std::cout << "\nUnordered array: ";
  show_array(A, size);
  quick_sort(A, 0, size - 1);
  std::cout << "\nOrdered array: ";
  show_array(A, size);
  std::cout << "\n";

  return 0;
}

