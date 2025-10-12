#include <iostream>

void show_array(int* A, int size) {
  std::cout << "[ ";
  for (int i = 0; i < size; i++) {
    std::cout << A[i] << " ";
  }
  std::cout << "]\n";
}

void merge(int* A, int p, int q, int r) {
  //Cantidad de datos por array
  int n1 = q - p + 1, L[n1 + 1];
  int n2 = r - q, R[n2 + 1];
  //Variables auxiliares
  int i = 0, j = 0, temp = 0;

  //Llenando arreglos: izquierdo y derecho
  for (i = 0; i < n1; i++) {
    L[i] = A[p + i];
  }
  for (j = 0; j < n2; j++) {
    R[j] = A[q + j + 1];
  }

  //Se llenan los arreglos y se reinician las variables auxiliares
  L[n1] = R[n2] = INT_MAX;
  i = j = 0;

  //Se comparan los dos arreglos y se va ordenando de menor a mayor
  for (int k = p; k < r + 1; k++) {
    if (L[i] < R[j]) {
      A[k] = L[i];
      i++;
    }
    else {
      A[k] = R[j];
      j++;
    }
  }
}

void merge_sort(int* A, int p, int r) {
  if (p < r) {
    int q = (p + r) / 2;

    //Lado izquierdo
    merge_sort(A, p, q);

    //Lado derecho
    merge_sort(A, q + 1, r);

    merge(A, p, q, r);
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
  merge_sort(A, 0, size - 1);
  std::cout << "\nOrdered array: ";
  show_array(A, size);
  std::cout << "\n";

  return 0;
}

