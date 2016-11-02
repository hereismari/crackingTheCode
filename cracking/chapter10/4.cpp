#include <stdio.h>
#include <vector>

using namespace std;

// sorted
struct Listy {

    vector<int>v;
    
    Listy() {}
    void add(int x) { v.push_back(x); }
    int elementAt(int i) { return i < v.size() ? v[i] : -1; }
};

int aproxSizeListy(Listy l) {
    int res = 1;
    while(l.elementAt(res) != -1) res *= 2;
    return res;
}

int binSearchListy(int value, Listy l) {
    
    int b = 0, e = aproxSizeListy(l);
    
    while(b <= e) {
        int m = b + (e-b)/2;
        if(l.elementAt(m) == -1 || l.elementAt(m) > value) e = m - 1;
        else if(l.elementAt(m) < value) b = m + 1;
        else return m;
    }

    return -1;
}

int main() {

    int n, x;
    scanf("%d", &n);

    Listy l;
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        l.add(x);
    }

    printf("1: %d\n", binSearchListy(1, l));
    printf("3: %d\n", binSearchListy(3, l));
    printf("10: %d\n", binSearchListy(10, l));
    printf("2: %d\n", binSearchListy(2, l));
    printf("100: %d\n", binSearchListy(100, l));

    return 0;
}
