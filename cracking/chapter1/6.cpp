#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

string solve(string s) {

    // checks if new string length is smaller then the original length
    int new_length = 2;

    for(int i = 1; i < s.size(); i++) {
        if(s[i] != s[i-1]) {
            new_length += 2; // 1(number) + 1(char it self)
        }
    }
    
    if(new_length < s.size()) {

        int counter = 1;
        int j = 0;
        
        string output = "";
        for(int i = 1; i < s.size(); i++) {
            if(s[i] != s[i-1]) {
                output += s[i-1];
                output += to_string(counter);
                counter = 1;
            }
            else counter++;
        }
    
        output += s[s.size()-1];
        output += to_string(counter);
        
        return output;
    }
    else {
        return s;
    }
}

int main() {

    string s;
    cin >> s;

    cout << solve(s) << '\n';

    return 0;
}
