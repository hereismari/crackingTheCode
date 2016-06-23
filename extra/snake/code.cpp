#include <bits/stdc++.h>

using namespace std;

bool snake(int a, int b) {
    return abs(a-b) <= 1;
}

int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    int mat[n][m], dp[n][m];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &mat[i][j]);

    int ans = 1;
    // DP
    // dp[0][0] = 1 dp[0][i] = snake ? dp[0][i-1]+1 : 1;

    dp[0][0] = 1; //base case, there is no value in the left or above
    for(int j = 1; j < m; j++) { 
        dp[0][j] = snake(mat[0][j-1], mat[0][j]) ? dp[0][j-1] + 1 : 1;
        ans = max(ans, dp[0][j]);
    }


    for(int i = 1; i < n; i++) 
        for(int j = 0; j < m; j++) {
            
            // try to go from the top to the bottom
            dp[i][j] = snake(mat[i-1][j], mat[i][j]) ? dp[i-1][j] + 1 : 1;
        
            // try to go from the left to the right
            if(j != 0)
                dp[i][j] = max(snake(mat[i][j-1], mat[i][j]) ? dp[i][j-1] + 1 : 1, dp[i][j]);
            ans = max(ans, dp[i][j]);
        }

    printf("%d\n", ans);

    return 0;
}
