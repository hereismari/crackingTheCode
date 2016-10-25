#include <bits/stdc++.h>

using namespace std;

int get_pivot_pos(int a[], int begin, int end) {
    
    int pivot = a[begin];

    int i = begin + 1, j = end;
    while(i <= j) {
        if(a[i] < pivot) i++;
        else if(a[j] > pivot) j--;
        else {
            int aux = a[i];
            a[i] = a[j];
            a[j] = aux;
            i++; j--;
        }
    }

    int aux = a[begin];
    a[begin] = a[j];
    a[j] = aux;

    return j;
}

void quicksort(int a[], int begin, int end) {
    if(begin < end) {
        int pivot_pos = get_pivot_pos(a, begin, end);
        quicksort(a, begin, pivot_pos - 1);
        quicksort(a, pivot_pos + 1, end);
    }
}

int main() {

    int n;
    scanf("%d", &n);

    if(n >= 1) {

        int a[n];
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        quicksort(a, 0, n-1);
    
        printf("----------Printing sorted array----------\n");
        printf("%d", a[0]);
        for(int i = 1; i < n; i++) {
            printf(" %d", a[i]);
        }
        printf("\n");
    }

    return 0;
}
