#include <stdio.h>

using namespace std;

char* solve(char s[], int n) {

    // checks if new string length is smaller then the original length
    int new_length = 2;

    for(int i = 1; i < n; i++) {
        if(s[i] != s[i-1]) {
            new_length += 2; // 1(number) + 1(char it self)
        }
    }
    
    if(new_length < n) {

        int counter = 1;
        int j = 0;
        char aux = s[0];
        for(int i = 1; i < n; i++) {
            if(s[i] != aux) {
                char help_aux = s[i];
                s[j++] = aux;
                s[j++] = (counter + '0');
                aux = help_aux;
                counter = 1;
            }
            else counter++;
        }

        s[j++] = aux;
        s[j++] = counter + '0';
        s[j] = '\0';
    }

    return s;
}

int main() {

    int n;
    scanf("%d", &n);
    
    char s[n];
    scanf("\n%s", s);

    printf("%s\n", solve(s, n));

    return 0;
}
