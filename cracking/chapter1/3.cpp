#include <stdio.h>
#include <queue>

using namespace std;

#define MAX 10000 // suppose this is the maximum size a string can have with the %20 instead of spaces

void solve1(char s[], int n) {

    int i = 0, number_of_spaces = 0;
    queue<char> q;

    while(i < n + number_of_spaces * 2) {
        
        if(s[i] != ' ' && !q.empty()) {
            char aux = s[i];
            s[i] = q.front();
            q.pop();
            q.push(aux);
        }
        
        else if(s[i] == ' ') {
            
            if(!q.empty()) {
                s[i] = q.front(); 
                q.pop(); 
                q.push('%');
            }

            else s[i] = '%';
            q.push('2');
            q.push('0');
            number_of_spaces++;
        }

        i++;
    }

    s[i] = '\0';

    printf("%s\n", s);
}

void solve2(char s[], int n) {

    int i = 0, number_of_spaces = 0;
    
    for(int i = 0; i < n; i++)
        if(s[i] == ' ') number_of_spaces++;
    
    int new_len = n + number_of_spaces * 2; // we are changing one char - > three chars (' ' -> '%20')
    
    s[new_len] = '\0';

    int j = new_len;
    for(int i = n-1; i >= 0; i--) {
        if(s[i] == ' ') {
            s[--j] = '0';
            s[--j] = '2';
            s[--j] = '%';
        }
        else {
            s[--j] = s[i];
        }
    }
    
    printf("%s\n", s);
} 

int main() {

    char s[MAX];
    int n;

    scanf("\n%[^\n]", s);
    scanf("%d", &n);

    solve1(s, n);
    solve2(s, n);

    return 0;
}
