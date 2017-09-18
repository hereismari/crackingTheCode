#include <stdio.h> 
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

# define MAX 10000

struct Node {

    Node *left;
    Node *right;
    int data;
};

void insert(Node* root, int data) {
    
    if(root->data == -1)
        root->data = data;
    else {
        
        Node *new_node = new Node;
        new_node->data = data;

        while(true) {
            if(data > root->data) {
                if(root->right == NULL) {
                   root->right = new_node; 
                    break;
                }
                else {
                    root = root->right;
                }
            }
            else {
                if(root->left == NULL) {
                    root->left = new_node;
                    break;
                }
                else {
                    root = root->left;
                }
            }
    
        }
    }
}

void print_spaces(int spaces) {
    for(int i = 0; i < spaces; i++) printf(" ");
}

void print_tree(Node* root, int spaces, bool print_n=true) {

    queue<pair<int, Node*> > q;
    q.push(make_pair(0, root));

    int aux = spaces;
    while(!q.empty()) {

        int top_level = q.front().first;
        Node *node =  q.front().second;
        q.pop();

        int num_spaces = spaces / (1 << top_level);
        if(num_spaces != aux) {
//            printf("%d %d\n", num_spaces, spaces);
            printf("\n");
            aux = num_spaces;
        }
        print_spaces(num_spaces);

        if(node == NULL) {
            print_spaces(num_spaces);
            continue;
        }

        printf("%d", node->data);
        print_spaces(num_spaces);

        q.push(make_pair(top_level + 1, node->left));
        q.push(make_pair(top_level + 1, node->right));
    }

    printf("\n");
}

Node* minimal_tree(const vector<int> &v, int i, int j) {

    if(j < i) {
        return NULL;
    }

    int m = i + (j-i)/2;
    Node *n = new Node;    
    n->data = v[m];
        
    n->left = minimal_tree(v, i, m-1);
    n->right = minimal_tree(v, m+1, j);
    return n;
}

int main() {

    int n;
    scanf("%d", &n);

    vector<int> v;
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        v.push_back(x);
    }

    print_tree(minimal_tree(v, 0, v.size()-1), 32);

    return 0;
}
