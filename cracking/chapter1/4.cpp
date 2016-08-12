#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX 1000 // supposing this is the maximum size of the string
#define MAX_ASC_II 300

bool solve1(char s[]) {
    
    int aux[MAX_ASC_II];
    fill(aux, aux + MAX_ASC_II, 0);

    for(int i = 0 ; s[i] != '\0'; i++) {
        aux[(int)s[i]]++;
    }

    bool flag = false;
    for(int i = 0; i < MAX_ASC_II; i++) {
        if(i == (int)' ') continue;
        if(aux[i] % 2 && !flag) flag = true;
        else if(aux[i] % 2) return false;
    }

    return true;
}

bool solve2(char s[]) {
    
    int n = 0;
    for(int i = 0; s[i] != '\0'; i++) n++;

    sort(s, s + n);

    bool flag = false;
    int counter = 1;
    for(int i = 0; i < n-1; i++) {
        if(s[i] == ' ') continue;
        if(s[i] == s[i+1]) counter++;
        else if(counter % 2 && !flag) flag = true;
        else if(counter % 2) return false;
        else counter = 1;
    }

    return counter % 2 == 0;
}

void toLower(char s[]) {
    for(int i = 0;  s[i] != '\0'; i++) {
        if((int)s[i] <= (int)'Z' && s[i] != ' ') {
            s[i] = (char)(s[i] - 'A' + 'a');
        }
    }
}

int main() {

    char s[MAX];
    scanf("%[^\n]", s);
    
    toLower(s);

    printf("%s\n", solve1(s) ? "YES" : "NO");
    printf("%s\n", solve2(s) ? "YES" : "NO");

    return 0;
}
