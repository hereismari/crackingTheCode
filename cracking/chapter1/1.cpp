#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;


bool solve1(int n, int a[]) {
    
    int aux[300];
    memset(aux, 0, sizeof aux);

    for(int i = 0; i < n; i++) {
        aux[a[i]]++;
        if(aux[a[i]] > 1) return true;
    }

    return false;
}

bool solve2(int n, int a[]) {

    sort(a, a + n);
    
    for(int i = 1; i < n; i++)
        if(a[i] == a[i-1]) return true;
 
    return false;
}

bool solve3(int n, int a[]) {
    
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            if(a[i] == a[j]) return true;

    return false;
}

int main() {

    int n;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("1: %d\n", solve1(n, a));   // O(n) with memory complexity of ~ O(300)
    printf("2: %d\n", solve2(n, a));  // O(nlogn) with no auxiliary data structure
    printf("3: %d\n", solve3(n, a)); // O(n²)

    return 0;
}
