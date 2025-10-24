#include <bits/stdc++.h>

using namespace std;

void show_array(int A[], int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    cout << "]\n";
}

int parent(int i) {
    return (i - 1) / 2;
}

int left(int i) {
    return (i * 2) + 1;
}

int right(int i) {
    return (i * 2) + 2;
}

void max_heapify(int A[], int i, int heap_size) {
    int largest;

    int l = left(i);
    int r = right(i);

    if (heap_size > l && A[l] > A[i]) {
        largest = l;
    }
    else {
        largest = i;
    }

    if (heap_size > r && A[r] > A[largest]) {
        largest = r;
    }

    if (i != largest) {
        swap(A[i], A[largest]);
        max_heapify(A, largest, heap_size);
    }

}

void build_max_heap(int A[], int heap_size) {
    for (int i = (heap_size / 2) - 1; i >= 0; i--) {
        max_heapify(A, i, heap_size);
    }
}

void heap_sort(int A[], int n) {
    int heap_size = n;

    build_max_heap(A, heap_size);

    for (int i = (n - 1); i >= 0; i--) {
        swap(A[i], A[0]);

        heap_size--;

        max_heapify(A, 0, heap_size);
    }
}

int main(void) {
    int n = 10, A[n] = { 5, 1, 2, 4, 8, 9, 3, 7, 6, 0 };

    cout << "Arreglo A antes de ordenar: ";
    show_array(A, n);
    heap_sort(A, n);
    cout << "Arreglo ordenado: ";
    show_array(A, n);

    return 0;
}
