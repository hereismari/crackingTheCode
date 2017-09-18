#include <stdio.h> 
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

# define MAX 1000

vector<int> topo_sort(int n, int order[MAX], vector<int> g[MAX]) {

    queue<int> q;

    for(int i = 1; i <= n; i++) {
        if(order[i] == 0)
            q.push(i);
    }

    vector<int> res;
    while(!q.empty()) { 
        int top = q.front(); q.pop();
        res.push_back(top);

        for(int i = 0; i < g[top].size(); i++) {
            int v = g[top][i];
            order[v]--;
            if(order[v] == 0) {
                q.push(v);
            }
        }
    
    }


    if(res.size() != n) {
        throw "error";
    }
    else {
        return res;
    }
}

int h[MAX];

int lca(int n, int x, int y, vector<int> g[MAX]) {


    return 0;
}


void dfs(int x, vector<int> g[MAX], int par=-1, int height=0) {

    h[x] = height;

    for(int i = 0; i < g[x].size(); i++) {
        if(g[x][i] != par) {
            dfs(g[x][i], g, x, height + 1); 
        }
    }
}

int main() {

    int n;
    scanf("%d", &n);

    vector<int> g[MAX];

    int x, y;
    for(int i = 0; i < n-1; i++) {
        scanf("%d %d", &x, &y);
        g[x].push_back(y); 
    }

    dfs(1, g);
    for(int i = 1; i <= n; i++) {
        printf("%d ", h[i]);
    }
    printf("\n");

    scanf("%d %d", &x, &y);
    printf("lca: %d\n", lca(n, x, y, g));

    return 0;
}
