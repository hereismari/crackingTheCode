#include <stdio.h>
#include <utility>

#define F first
#define S second

using namespace std;

int mean(int begin, int end) {
    return begin + (end-begin)/2;
}

pair<int, int> search_diagonal(int matrix[][4], int begin_row, int end_row, int begin_col, int end_col, int x) {

    pair<int, int> begin = make_pair(begin_row, begin_col);
    pair<int, int> end = make_pair(end_row, end_col);

    while(begin <= end) {
        pair<int, int> middle = make_pair(mean(begin.F, end.F), mean(begin.S, end.S));
        
        int middle_value = matrix[middle.F][middle.S];
        if(middle_value == x) return middle;
        else if(middle_value < x) { begin.F++; begin.S++; }
        else { end.F--; end.S--; }
    }

    return begin;
}

bool check_pos(int x, int y) {

    if(x >= 4 || x < 0) return false;
    if(y >= 4 || y < 0) return false;
    return true;
}


pair<int, int> binary_search(int matrix[][4], int begin_row, int end_row, int begin_col, int end_col, int x) {

    pair<int, int> not_found = make_pair(-1, -1);

    // if limits are wrong, we couldnt find a solution
    if((begin_row > end_row) || (begin_col > end_col)) return not_found;
    if(!check_pos(begin_row, end_row)) return not_found;
    if(!check_pos(begin_col, end_col)) return not_found;

    pair<int, int> diag = search_diagonal(matrix, begin_row, end_row, begin_col, end_col, x);

    printf("diagonal: (%d,%d) = %d\n", diag.F, diag.S, matrix[diag.F][diag.S]);
    if(matrix[diag.F][diag.S] == x) return diag;

    printf("left sqr: (%d, %d, %d, %d)\n", diag.F, end_row, begin_col, diag.S-1);
    pair<int, int> left_sqr = binary_search(matrix, diag.F, end_row, begin_col, diag.S-1, x);
    if(matrix[left_sqr.F][left_sqr.S] == x) return left_sqr;

    pair<int, int> right_sqr = binary_search(matrix, begin_row, diag.F-1, diag.S, end_col, x);
    if(matrix[right_sqr.F][right_sqr.S] == x) return right_sqr;

    return make_pair(-1, -1);
}

pair<int, int> solve(int matrix[][4], int x, int n, int m) {
    return binary_search(matrix, 0, n-1, 0, m-1, x);
}

void print_pair(pair<int, int> p) {
    printf("(%d %d)\n", p.F, p.S);
}

int main() {

    int matrix[4][4];

    matrix[0][0] = 15;
    matrix[0][1] = 20;
    matrix[0][2] = 70;
    matrix[0][3] = 85;

    matrix[1][0] = 20;
    matrix[1][1] = 35;
    matrix[1][2] = 80;
    matrix[1][3] = 95;

    matrix[2][0] = 30;
    matrix[2][1] = 55;
    matrix[2][2] = 95;
    matrix[2][3] = 105;

    matrix[3][0] = 40;
    matrix[3][1] = 80;
    matrix[3][2] = 120;
    matrix[3][3] = 120;

    print_pair(solve(matrix, 55, 4, 4));
    print_pair(solve(matrix, 85, 4, 4));
    print_pair(solve(matrix, 35, 4, 4));

    return 0;
}
