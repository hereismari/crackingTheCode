#include <stdio.h>
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> create_map(string s[], int n) {

    map<string, int> m;
    for(int i = 0; i < n; i++) {
       if(m.find(s[i]) != m.end()) {
         m[s[i]] += 1;
       } else {
         m[s[i]] = 1;
       }
    }

    return m;
}

int main() {

    int n; // number of words in the book
    int q; // number of queries

    scanf("%d %d", &n, &q);

    string book[n];
    for(int i = 0; i < n; i++) {
        cin >> book[i];
    }

    map<string, int> m = create_map(book, n);

    string str_q;
    for(int i = 0; i < q; i++) {
        cin >> str_q;
        if(m.find(str_q) != m.end()) {
            printf("%d\n", m[str_q]);
        }
        else {
            printf("0\n");
        }
    }

    return 0;
}
