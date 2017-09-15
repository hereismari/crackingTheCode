#include <stdio.h>


using namespace std;

bool get_bit(int n, int i) {
    return ((n & (1 << i)) != 0);
}

int set_bit(int n, int i) {
    return  (n | (1 << i));
}

int clear_bit(int n, int i) {
    return (n & ~(1 << i));
}

int clear_sign(int n, int i) {
    return n & ((1 << i) - 1);
}

int main() {

    printf("%d\n", get_bit(8, 3));
    printf("%d\n", get_bit(42, 5));
    printf("%d\n", get_bit(4, 2));
    printf("%d\n", get_bit(9, 1));

    return 0;
}
