#include <stdio.h>
#include <vector>

using namespace std;

int get_max_index(const vector<int> &v, int i, int j, int k) {
    if(v[i] >= v[j] && v[i] >= v[k]) return i;
    if(v[j] >= v[i] && v[j] >= v[k]) return j;
    if(v[k] >= v[i] && v[k] >= v[j]) return k;
}

vector<int> peaks_and_valleys(const vector<int> &v) {

    vector<int> res;
    for(int i = 0; i < v.size(); i++) res.push_back(v[i]);
    for(int i = 1; i < res.size(); i += 2) {
        int max_i = get_max_index(v, i-1, i, i+1);
        if(max_i != i) {
            int tmp = res[max_i];
            res[max_i] = res[i];
            res[i] = tmp;
        }
    }
    return res;
}

void print_vector(const vector<int> &v) {

    for(int i = 0; i < v.size()-1; i++) {
        printf("%d ", v[i]);
    }

    printf("%d\n", v[v.size()-1]);
}

int main() {

    vector<int> v;
    int a[] = {5, 8, 6, 2, 3, 4, 6, 8};
    for(int i = 0; i < sizeof(a) / 4; i++) {
        v.push_back(a[i]);
    }

    print_vector(v);
    print_vector(peaks_and_valleys(v));

	return 0;
}
