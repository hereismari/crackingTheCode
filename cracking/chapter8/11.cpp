#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

long long int coins(int c[], int v[], int m, int n) {

    long long int dp[n+1];
    memset(dp, 0LL, sizeof dp);

    dp[0] = 1;

    for(int i = 0; i < m; i++) {
        for(int k = n; k >= 0; k--) {
            for(int j = v[i]; j >= 1; j--) {
                int value = j * c[i];
                if(value > k) continue;
                dp[k] += dp[k - value];
            }
        }
    }

    return dp[n];
}



int main() {

    int n;
    scanf("%d", &n);

    int c[] = {25, 10, 5, 1};

    int v[4];
    for(int i = 0; i < 4; i++) {
        scanf("%d", &v[i]); 
    }

    printf("%lld\n", coins(c, v, 4, n));

    return 0;
}
