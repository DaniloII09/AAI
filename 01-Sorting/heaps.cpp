#include <bits/stdc++.h>

using namespace std;

int parent(int i) {
    return (i - 1) / 2;
}

int left(int i) {
    return (2 * i) + 1;
}

int right(int i) {
    return (2 * i) + 2;
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

    if (heap_size > r && A[r] > A[i]) {
        largest = r;
    }

    if (largest != i) {
        swap(A[largest], A[i]);
        max_heapify(A, largest, heap_size);
    }
}

void build_max_heap(int A[], int heap_size) {
    for (int i = (heap_size / 2) - 1; i >= 0; i--) {
        max_heapify(A, i, heap_size);
    }
}

int pop_max(int A[], int* heap_size) {
    swap(A[0], A[*heap_size - 1]);

    int ans = A[*heap_size - 1];

    (*heap_size--);

    max_heapify(A, 0, *heap_size);

    return ans;
}

void patch_max_heap(int A[], int index) {
    if (index == 0) return;

    int p = parent(index);

    if(A[index] > A[p]) {
        swap(A[index], A[p]);

        patch_max_heap(A, p);
    }
}

void push_max(int A[], int* heap_size, int value) {
    A[*heap_size] = value;

    (*heap_size)++;

    patch_max_heap(A, *heap_size - 1);
}
