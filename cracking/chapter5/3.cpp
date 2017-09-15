#include <stdio.h>

using namespace std;

void print(int n) {
    for(int i = 31; i >= 0; i--) {
        printf("%d", ((n & (1 << i)) != 0) ? 1 : 0); 
    }
    printf("\n");
}

int flib_bit_win(int n) {

    if(n == -1) return sizeof(n) * 8;

    int res = 0, previous_ones = 0;
    int num_ones = 0;
    for(int i = 0; i < 32; i++) {
        if((n & (1 << i)) != 0) {
            num_ones++;
        }
        else {
            previous_ones = num_ones + 1;
            num_ones = 0;
        }
    
        if(num_ones + previous_ones > res) {
            res = num_ones + previous_ones;
        }
    }

   return res;
}

int main() {

    int n = 1775; // 11011101111
    print(n);
    printf("%d\n", flib_bit_win(n));

    return 0;
}
