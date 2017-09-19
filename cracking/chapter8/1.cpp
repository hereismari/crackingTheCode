#include <stdio.h>
#include <string.h>

using namespace std;

long long int solve(int n) {

    const int num_steps = 3;
    int steps[] = {1, 2, 3};

    long long int dp[n + 1];
    memset(dp, 0LL, sizeof dp);

    dp[0] = 1; // initially only dp[0] has solution
               // the kid has 1 way to get there
    
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < num_steps; j++) {
            if(i - steps[j] >= 0)
                dp[i] += dp[i - steps[j]];
        }
    }

    return dp[n];
}

int main() {

    int n;
    scanf("%d", &n);

    printf("%lld\n", solve(n));

    return 0;
}
