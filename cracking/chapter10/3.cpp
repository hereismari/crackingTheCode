#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int find_rotated_pos(int a[], int n) {

    int b = 0, e = n-1;
    int m, answer = -1;

    while(b <= e) {
        m = b + (e-b)/2;
        if(a[m] >= a[0] && a[m] <= a[n-1]) {
            answer = m;
            b = m + 1;
        }
        else
            e = m - 1;
    }

    return answer;
}

int bin_search(int a[], int b, int e, int element) {
    int m;
    while(b <= e) {
        m = b + (e-b)/2;
        if(a[m] < element) 
            b = m + 1;
        else if(a[m] > element)
            e = m - 1;
        else return m;
    }
    return -1;
}

int find(int a[], int n, int element) {
    
    int rotated_pos = find_rotated_pos(a, n);
    
    int answer1 = bin_search(a, 0, rotated_pos, element);
    int answer2 = bin_search(a, rotated_pos + 1, n-1, element);

    if(answer1 != -1) return answer1;
    else if(answer2 != -1) return answer2 + rotated_pos + 1;

    return -1;
}

int main() {
    
    int n;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    printf("%d %d\n", 3, find(a, n, 3));
    printf("%d %d\n", 1, find(a, n, 1));
    printf("%d %d\n", 5, find(a, n, 5));
    
    return 0;
}
