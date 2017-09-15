#include <stdio.h>


using namespace std;

void print(int n) {
    for(int i = 31; i >= 0; i--) {
        printf("%d", ((n & (1 << i)) != 0) ? 1 : 0); 
    }
    printf("\n");
}

string double_to_bin(double f) {

    if(f <= 0 || f >= 1) return "ERROR";

    string res = "";
    while(f > 0) {

        if(res.size() >= 32) return "ERROR";

        double num = 2 * f;
        if(num >= 1) {
            res += "1";
            f = num - 1;
        }
        else {
            res += "0";
            f = num;
        }
    }

    return res;
}


int main() {

    return 0;
}
