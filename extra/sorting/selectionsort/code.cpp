#include <stdio.h>
#include <vector>

using namespace std;

void printVector(vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void selectionsort(vector<int> v) {
    
    for(int i = 0; i < v.size(); i++) {
        
        int minimum_index = i;
        for(int j = i+1; j < v.size(); j++) {
            if(v[j] < v[minimum_index]) {
                minimum_index = j;
            }
        }
   
        int aux = v[i];
        v[i] = v[minimum_index];
        v[minimum_index] = aux;
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

    selectionsort(v);
    
    return 0;
}
