#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int magic_index(const vector<int>& v) {

    int b = 0, e = v.size()-1;
    int m;

    while(b <= e) {
        int m = b + (e-b)/2;

        if(v[m] == m)
            return m;
        else if(v[m] > m)
            e = m - 1;
        else
            b = m + 1;
    }

    return -1;
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



    printf("%d\n", magic_index(v));

    return 0;
}
