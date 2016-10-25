#include <stdio.h>
#include <vector>

using namespace std;

void printVector(vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void bubblesort(vector<int> v) {
    
    for(int i = 0; i < v.size(); i++) {
        for(int j = 1; j < v.size()-i; j++) {
            if(v[j] < v[j-1]) {
                int aux = v[j-1];
                v[j-1] = v[j];
                v[j] = aux;
            }
        }
    }

    printVector(v);
}


int main() {
    
    int n, x;
    scanf("%d", &n);

    vector<int> v;
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        v.push_back(x);
    }

    bubblesort(v);
    
    return 0;
}
