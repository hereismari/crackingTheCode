#include <bits/stdc++.h>

using namespace std;

void mergeI(int a[], int begin, int middle, int end) {

    int aux[end - begin];

    int i = begin, j = middle + 1;
    int cont = 0;

    while(i <= middle && j <= end) {
        if(a[i] < a[j]) {
            aux[cont] = a[i];
            i++;
        }
        else {
            aux[cont] = a[j];
            j++;
        }
        cont++;
    }

    while(i <= middle) {
        aux[cont] = a[i];
        i++;
        cont++;
    }

    while(j <= end) {
        aux[cont] = a[j];
        j++;
        cont++;
    }

    for(int it = begin, it2 = 0; it <= end; it++, it2++)
        a[it] = aux[it2];

}

void mergesort(int a[], int begin, int end) {
    if(begin < end) {
        int middle = (end + begin)/2;
        
        mergesort(a, begin, middle);
        mergesort(a, middle + 1, end);
        
        mergeI(a, begin, middle, end);
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

        mergesort(a, 0, n-1);
    
        printf("----------Printing sorted array----------\n");
        printf("%d", a[0]);
        for(int i = 1; i < n; i++) {
            printf(" %d", a[i]);
        }
        printf("\n");
    }

    return 0;
}
