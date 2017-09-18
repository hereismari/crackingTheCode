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


int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    int order[MAX];
    memset(order, sizeof order, 0);

    vector<int> g[MAX];

    int x, y;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        g[x].push_back(y); 
        order[y]++;
    }

    scanf("%d %d", &x, &y);
    vector<int> res = topo_sort(n, order, g);

    for(int i = 0; i < res.size()-1; i++) {
        printf("%d ", res[i]);
    }
    printf("%d\n", res[res.size()-1]);

    return 0;
}
