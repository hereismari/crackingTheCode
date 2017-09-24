#include <stdio.h>

using namespace std;

void number_swap(int &i, int &j) {

    i = i - j;
    j = i + j;
    i = j - i;

}

int main() {

    int a, b;
    scanf("%d %d", &a, &b);

    number_swap(a, b);

    printf("%d %d\n", a, b);

    return 0;
}
