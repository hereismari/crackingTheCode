#include <stdio.h> 
#include <vector>
#include <string.h>

using namespace std;

# define MAX 10000

bool dfs(int node, int t, bool vis[MAX], vector<int> g[MAX]) {

    vis[node] = true;
    if(node == t) return true;

    bool res = false;
    for(int i = 0; i < g[node].size(); i++) {
        if(!vis[g[node][i]])
            res |= dfs(g[node][i], t, vis, g);
    }
    
    return res;
}


int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    bool vis[MAX];
    memset(vis, sizeof vis, false);

    vector<int> g[MAX];

    int x, y;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
    }

    
    scanf("%d %d", &x, &y);
    printf(dfs(x, y, vis, g) ? "there is a path\n" : "there is no path\n");

    return 0;
}
