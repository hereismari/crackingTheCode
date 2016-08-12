#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAX_ASC_II 257

bool solve1(string s, string t) {
    
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    
    return s == t;
}

bool solve2(string s, string t) {

    int aux_s[MAX_ASC_II], aux_t[MAX_ASC_II];

    fill(aux_s, aux_s + MAX_ASC_II, 0);
    fill(aux_t, aux_t + MAX_ASC_II, 0);

    for(int i = 0; i < s.size(); i++) aux_s[(int)s[i]]++;
    for(int i = 0; i < t.size(); i++) aux_t[(int)t[i]]++;

    for(int i = 0; i < MAX_ASC_II; i++) 
        if(aux_s[i] != aux_t[i]) 
            return false;
    
    return true;
}

int main() {


    string s1, s2;

    cin >> s1 >> s2;

    printf("%s\n", solve1(s1, s2) ? "YES" : "NO");
    printf("%s\n", solve2(s1, s2) ? "YES" : "NO");

    return 0;
}
