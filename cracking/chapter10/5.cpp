#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int binSearchSpaces(string s, vector<string> v) {
    
    int b = 0, e = v.size()-1;
    
    while(b <= e) {
        int m = b + (e-b)/2;
       
        int original_m = m;
        int m_l = m-1, m_e = m+1; 
        while(v[m] == " " && (m_e <= e && m_l >= b)) {

            if(m_l >= b && v[m_l] != " ") m = m_l;
            if(m_e <= e && v[m_e] != " ") m = m_e;
            original_m = m;

            if(m_e <= e) m_e++;
            if(m_l >= b) m_l--;
        }

        if(v[m] == " ") return -1;

        string m_s = v[m];

        if(m_s.compare(s) == 0) return m;
        else if(m_s.compare(s) < 0) b = original_m + 1;
        else e = original_m - 1;
    }

    return -1;
}

void insertSpaces(vector<string> &v, int n) {
    for(int i = 0; i < n; i++) v.push_back(" ");
}

int main() {

    vector<string> v;

    v.push_back("car");
    insertSpaces(v, 3);
    v.push_back("dance");
    v.push_back("delicious");
    insertSpaces(v, 5);
    v.push_back("xa");
    insertSpaces(v, 10);

    printf("%d\n", binSearchSpaces("car", v));
    printf("%d\n", binSearchSpaces("delicious", v));
    printf("%d\n", binSearchSpaces("zoom", v));

    return 0;
}
