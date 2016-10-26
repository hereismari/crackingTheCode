#include <stdio.h>

using namespace std;

void merge(int a[], int len_a, int b[], int len_b) {
    
    for(int i = len_a, j = 0; j < len_b; i++, j++)
        a[i] = b[j];

    int i = 0, j = len_a;
    int new_len = len_a + len_b;
    for(i = 0; i < new_len && j < new_len; i++) {
        if(a[j] < a[i]) {
            int aux = a[i];
            a[i] = a[j];
            a[j] = aux;
            if(j+1 < new_len && a[j+1] < a[j]) j++;
        }
    }
}

int main() {

    int a[10] = {-1, -2, 10, 10, 50};
    int b[] = {4, 5, 8, 8, 10};

    merge(a, 5, b, 5);

    for(int i = 0; i < 10; i++)
        printf("%d ", a[i]);

    return 0;
}
