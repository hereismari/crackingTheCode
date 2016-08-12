#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

bool oneMistake(string s, string t) {
    
    int counter = 0;
    for(int i = 0; i < s.size(); i++) 
        if(s[i] != t[i]) counter++;

    return counter <= 1;
}

bool removedString(string s, string t) {
    int counter = 0;
    for(int i = 0, j = 0; i < s.size(); i++) { 
        if(s[i] != t[j] && counter != 0) return false;
        else if(s[i] != t[j]) counter++;
        else j++;
    }
    return true;
}


bool solve(string s, string t) {

    // possible replace operation
    if(s.size() == t.size()) {
        return oneMistake(s, t);
    }

    // possible remove operation
    else if(s.size() == t.size() + 1) {
        return removedString(s, t);
   }

    // possible insert operation
    else if(s.size() == t.size() - 1) {
        return removedString(t, s);
    }

    else return false;
}   

int main() {

    string s, t;

    cin >> s >> t;

    printf("%s\n", solve(s, t) ? "YES" : "NO");

    return 0;
}
