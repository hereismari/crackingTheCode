#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;


void subset(const vector<int>& v) {

    for(int bitmask = 1; bitmask < (1 << v.size()); bitmask++) {
        for(int i = 0; i < v.size(); i++) {
            if(bitmask & (1 << i)) {
                printf("%d ", v[i]);
            }
        }
        printf("\n");
    }
}


int main() {

    int n;
    scanf("%d", &n);

    vector<int> v;
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        v.push_back(x);
    }

    subset(v);

    return 0;
}
