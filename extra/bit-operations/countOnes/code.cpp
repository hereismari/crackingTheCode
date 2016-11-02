#include <bits/stdc++.h>

using namespace std;

/*
 *  This function counts the number of 1's from
 *  from the represetation of 0 as a binary number to the 
 *  representation of N as a binary number.
 */

long long int countOnes(int n) {
    
    int k = int(floor(log2(n))) + 1;
    printf("k: %d\n", k);

    long long int ans = 0;
    for(int i = 1; i <= k; i++) {
        long long int exp = 1LL << (i);
        ans += max(n % exp - (exp/2 - 1), 0LL) + (n/exp) * exp/2;
    }

    return ans;
}

int main() {
   
    int n;
    scanf("%d", &n);
    printf("%lld\n", countOnes(n));

    return 0;
}
