#include <stdio.h>


using namespace std;

void print(int n) {
    for(int i = 31; i >= 0; i--) {
        printf("%d", ((n & (1 << i)) != 0) ? 1 : 0); 
    }
    printf("\n");
}

int clear(int n, int j, int i) {
    
    // set 1 the first i bits
    int mask = ~(-1 << i);
    printf("mask: ");
    print(mask);

    // set 1 from j to the last bit
    mask = (mask | ((-1 << (j+1))));
    printf("mask: ");
    print(mask);

    return n & mask;
}

int merge(int m, int n, int j, int i) {

    int res = n;
    res = clear(n, j, i);

    return res | (m << i);
}


int main() {

    int n = 1024; // 1000000000
    int m = 19; // 10011
    print(merge(m, n, 6, 2));

    return 0;
}
