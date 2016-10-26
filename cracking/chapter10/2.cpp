#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>


using namespace std;

#define ALPHA_MAX 400

bool areAnagrams(string s1, string s2) {
   
    if(s1.size() != s2.size()) return false;

    int a[ALPHA_MAX], b[ALPHA_MAX];
    for(int i = 0; i < ALPHA_MAX; i++) a[i] = b[i] = 0;

    for(int i = 0; i < s1.size(); i++) a[s1[i]]++;
    for(int i = 0; i < s2.size(); i++) b[s2[i]]++;

    for(int i = 0; i < ALPHA_MAX; i++)
        if(a[i] != b[i]) {
            printf("%c\n", i);
            return false;
        }
    
    cout << s1 << " " << s2 << endl;
    return true;
}

bool comp1(string s1, string s2) {
    return areAnagrams(s1, s2);
}

int main() {

    vector<string> v;

    v.push_back("oi");
    v.push_back("amor");
    v.push_back("io");
    v.push_back("dkjdoiaj");
    v.push_back("roma");

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    
    map<string, vector<string> > m;
    for(int i = 0; i < v.size(); i++) {
        string unsorted = v[i];
        sort(v[i].begin(), v[i].end());
        if(m.find(v[i]) != m.end()) {
            m[v[i]].push_back(unsorted);
            v[i] = unsorted;
        }
        else {
            m[v[i]];
            m[v[i]].push_back(unsorted);
            v[i] = unsorted;
        }
    }

    int i = 0;
    for(map<string, vector<string> >::iterator it = m.begin(); it != m.end(); it++) {
        for(int j = 0; j < (it->second).size(); j++) {
            v[i] = m[it->first][j];
            i++;
        }
    }

    printf("----\n");
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << endl;
    return 0;
}
