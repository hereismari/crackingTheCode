#include <stdio.h>
#include <set>

using namespace std;

#define MAX 100

void updateRow(int mat[MAX][MAX], int n, int m, int value, int row) {
    for(int j = 0; j < m; j++)
        mat[row][j] = value;
}

void updateColumn(int mat[MAX][MAX], int n, int m, int value, int column) {
    for(int i = 0; i < n; i++)
        mat[i][column] = value;
}

void printMatrix(int mat[MAX][MAX], int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void solve(int mat[MAX][MAX], int n, int m) {
    
    set<int> rows, columns;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 0) {
                rows.insert(i);
                columns.insert(j);
            }
        }
    }

    for(set<int>::iterator it = rows.begin(); it != rows.end(); it++) {
        updateRow(mat, n, m, 0, *it);
    }

    for(set<int>::iterator it = columns.begin(); it != columns.end(); it++) {
        updateColumn(mat, n, m, 0, *it);
    }

    printMatrix(mat, n, m);
}

int main() {

    int mat[MAX][MAX], n, m;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &mat[i][j]);

    solve(mat, n, m);
    return 0;
}

