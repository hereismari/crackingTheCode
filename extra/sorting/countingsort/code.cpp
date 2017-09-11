#include <stdio.h>
#include <vector>

using namespace std;

void printVector(vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void countingsort(vector<int> v) {
    
    int max_v = 0;
    for(int i = 0; i < v.size(); i++) {
        max_v = max(v[i], max_v);
    }

    int aux[max_v + 1];
    for(int i = 0; i <= max_v; i++) aux[i] = 0;

    for(int i = 0; i < v.size(); i++) {
        aux[v[i]]++;
    }

    for(int i = 1; i <= max_v; i++) aux[i] += aux[i-1];

    // not stable, but less add memory
    /*
    for(int i = 0, j = 0; i <= max_v && j < v.size(); i++) {
        while(aux[i] > j) {
            v[j] = i;
            j++;
        }
    }
    */

    // stable, uses more memory
    vector<int> output(v.size());
    for(int i = v.size()-1; i >= 0; i--) {
        output[aux[v[i]]-1] = v[i];
        aux[v[i]]--;
    }
    
    printVector(output);
}


int main() {
    
    int n, x;
    scanf("%d", &n);

    vector<int> v;
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        v.push_back(x);
    }

    countingsort(v);
    
    return 0;
}
