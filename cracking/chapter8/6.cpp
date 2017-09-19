#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

long long int mult(long long int s, long long int b) {

    if(s == 0) {
        return 0;
    }
    else if(s == 1) {
        return b;
    }
    else {
        
        long long int s_2 = (s >> 1); // s/2
        long long int mult_s_2 = mult(s_2, b);

        if(s_2 % 2)
            return mult_s_2 + mult_s_2 + b;
        else
            return mult_s_2 + mult_s_2; 
    
    }

}

int main() {

    long long int x, y;
    scanf("%lld %lld", &x, &y);

    
    long long int res;
    if(y > x)
        res = mult(x, y);
    else
        res = mult(y, x);

    printf("%lld\n", res);

    return 0;
}
