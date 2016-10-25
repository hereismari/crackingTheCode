#include <stdio.h>
#include <queue>

using namespace std;

#define MAX 1000

int partial_swap(int mat[MAX][MAX], int new_value, int i, int j) {
    int aux = mat[i][j];
    mat[i][j] = new_value;
    return aux;
}

void printMatrix(int mat[MAX][MAX], int n, int m) {
    printf("MATRIX\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
    printf("\n");
}

void rotate(int mat[MAX][MAX], int i, int j, int limit) {
    
    int value = mat[i][j];

    value = partial_swap(mat, value, j, limit);
    value = partial_swap(mat, value, limit, limit-j+i);
    value = partial_swap(mat, value, limit-j+i, i);
    value = partial_swap(mat, value, i, j);
}

void rotateMatrix(int mat[MAX][MAX], int n) {

    int limit = n-1;
    for(int i = 0; i < limit; i++) {
        for(int j = i; j < limit; j++) {
            rotate(mat, i, j, limit);
            printMatrix(mat, n, n);
        }
        limit--;
    }
}

int main() {

    int n;
    scanf("%d", &n);

    int mat[MAX][MAX];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    rotateMatrix(mat, n);
    printMatrix(mat, n, n);

    return 0;
}
