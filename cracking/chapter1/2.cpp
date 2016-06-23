#include <stdio.h>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    char a[n];
    scanf(" %s", a);

    for(int i = 0, j = n-1; i <= j; i++, j--) {
        int aux = a[i];
        a[i] = a[j];
        a[j] = aux;
    }

    printf("%s\n", a);

    return 0;
}
