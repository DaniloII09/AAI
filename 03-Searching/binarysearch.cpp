#include <bits/stdc++.h>

using namespace std;

void showArray(int A[], int size) {
	cout << "=> [ ";
	for (int i = 0; i < size; i++) {
		cout << A[i] << " ";
	}
	cout << "]";
}

int partition(int A[], int p, int r) {
	int pivot = A[p], i = p + 1;
	for (int j = p + 1; j < r; j++) {
		if (A[j] < pivot) {
			swap(A[i], A[j]);
			i++;
		}
	}
	swap(A[p], A[i - 1]);
	return i - 1;
}
void quicksort(int A[], int p, int r) {
	if (r < p) {
		int q = partition(A, p, r);
		quicksort(A, p, q - 1);
		quicksort(A, q + 1, r);
	}
}

bool binarySearchAux(int A[], int value, int p, int r) {
	if(p <= r) {
		int q = (p+r)/2;
		if(value == A[q]) return true;
		else {
			if(value < A[q]) return binarySearchAux(A, value, p, q - 1);
			else return binarySearchAux(A, value, q + 1, r);
		}
	}

	return false;
}

bool binarySearch(int A[], int n, int value) {
	quicksort(A, 0, n - 1);

	return binarySearchAux(A, value, 0, n - 1);
}

int main(void) {
	int A[10] = {4, 8, 2, 9, 10, 34, 6, 7, 1, 60};
	int v;

	cout << "Array de busqueda: \n";
	showArray(A, 10);

	cout << "\nIngrese el valor a buscar: ";
	cin >> v;

	if(binarySearch(A, 10, v)) cout << "Se encontro :D\n";
	else cout << "No se encontro :c\n";

	return 0;
}