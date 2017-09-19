#include <stdio.h>
#include <stack>

using namespace std;

void sort_stack(stack<int> &s1, stack<int> &s2) {

    int size_s1 = 0;
    int cur_max = 0;
   
    if(s1.empty()) return;

    while(!s1.empty()) {
        // move element from s1 to s2
        int top = s1.top();
        s1.pop();
        s2.push(top);

        if(top > cur_max) cur_max = top;    
        size_s1++;
    }

    int count = 0;
    while(count < size_s1) {
        count++;
        int top = s2.top();
        s2.pop();
        if(top != cur_max) s1.push(top); 
    }

    s2.push(cur_max); 
    sort_stack(s1, s2);
}


int main() {

    stack<int> s1, s2;
    int n;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        s1.push(x);
    }

    sort_stack(s1, s2);
    while(!s2.empty()) {
        printf("%d ", s2.top());
        s2.pop();
    }
    printf("\n");

    return 0;
}
