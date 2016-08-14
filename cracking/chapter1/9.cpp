#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

#define BASE 10
#define ll long long int

#define KMP 1
#define HASH 2

bool isSubstringHash(string s, string t) {
	
	ll base[s.size()], hash_s[s.size()], hash_t[t.size()];
	
	base[0] = 1;
	for(int i = 1; i < s.size(); i++) base[i] = BASE * base[i-1];
	
	hash_s[0] = s[0] - 'a' + 1;
	for(int i = 1; i < s.size(); i++) hash_s[i] = hash_s[i-1] + base[i] * (s[i] - 'a' + 1);
	
	hash_t[0] = t[0] - 'a' + 1;
	for(int i = 1; i < t.size(); i++) hash_t[i] = hash_t[i-1] + base[i] * (t[i] - 'a' + 1);
	
	
	for(int i = t.size()-1, counter = 0; i < s.size(); i++, counter++) {
		
		ll new_hash = hash_s[i];
		if(counter) new_hash -= hash_s[counter-1];
		new_hash = new_hash / base[counter];
		
		if(new_hash == hash_t[t.size()-1]) return true;
	}

    return false;
}

bool isSubstringKMP(string s, string t) {
    
    /* Prefix function */
    
    int prefix[t.size() + 1];
    prefix[0] = -1; // flag
    
    int k = prefix[0];
    for(int j = 1; j <= t.size(); j++) {
        while(k != -1 && t[k] != t[j-1]) k = prefix[k];
        prefix[j] = k + 1;
        k = prefix[j];
    }
    
    /* String Matching */
    int i = 0;
    int j = 0;

    while(j < s.size()) {
        if(i == -1) { i = 0; j++; }
        else if(t[i] == s[j]) {
            i++,j++;
            if(i == t.size()) return true;
        }
        else i = prefix[i];
    }
    
    return false;
}

bool isSubstring(string s, string t, int option) {
    switch(option) {
        case KMP:
            return isSubstringKMP(s, t); 
            break;
        case HASH:
            return isSubstringHash(s, t);
            break;
        default:
            return false;
            break;
    }
}

bool isRotation(string s, string t) {

    if (s.size() == t.size() && s.size() > 0) {
        string auxiliar = s + s;
        return isSubstring(auxiliar, t, HASH);
    }
    else 
        return false;
}


int main() {

    string s1, s2;

    cin >> s1 >> s2;

    printf("%s\n", isRotation(s1, s2) ? "YES" : "NO");

    return 0;
}
