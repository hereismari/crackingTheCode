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
        new_node->left = NULL;
        new_node->right = NULL;

        while(true) {
            if(data > root->data) {
                if(root->right == NULL) {
                    printf("inserted right to %d\n", root->data);
                    root->right = new_node; 
                   break;
                }
                else {
                    root = root->right;
                }
            }
            else {
                if(root->left == NULL) {
                    printf("inserted left to %d\n", root->data);
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

void print_tree(Node* root, int spaces=32, bool print_n=true) {

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
            printf("**\n");
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

bool check_balanced(Node *node, int& left_h, int& right_h, bool is_left=true) {

    if(node == NULL){
        if(is_left) left_h = -1;
        else right_h = -1;
        return true;
    }

    int l_h, r_h;
    if(!check_balanced(node->left, left_h, right_h, true)) {
        return false;
    }
    else 
        l_h = left_h;
    if(!check_balanced(node->right, left_h, right_h, false)) {
        return false;
    }
    else
        r_h = right_h;

    if(!is_left) {
        right_h = 1 + (l_h > r_h ? l_h : r_h);
    }
    else {
        left_h = 1 + (l_h > r_h ? l_h : r_h);
    }

    return (l_h - r_h <= 1 && l_h - r_h >= -1);
}
// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += 5;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(Node *root) {
   // Pass initial space count as 0
   print2DUtil(root, 0);
}

int main() {

    Node *root = new Node;
    root->data = -1; // head
    root->left = NULL;
    root->right = NULL;

    insert(root, 4);
    insert(root, 10);
    insert(root, 5);
    insert(root, 11);
    insert(root, 3);
    insert(root, 2);
    insert(root, 20);
    insert(root, 20);

    print2D(root);
    int is_left, is_right;
    printf("is balanced: %d\n", check_balanced(root, is_left, is_right));
    return 0;
}
