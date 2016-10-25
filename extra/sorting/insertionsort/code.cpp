#include <stdio.h>
#include <vector>

using namespace std;

void printVector(vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void insertionsort(vector<int> v) {
    
    for(int i = 1; i < v.size(); i++) {
        int key = v[i];
        int j = i-1;
        while(j >= 0 && v[j] > key) {    
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
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

    insertionsort(v);
    
    return 0;
}
