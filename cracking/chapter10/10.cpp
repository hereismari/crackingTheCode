#include <stdio.h>

using namespace std;

struct Node {
	
	Node *left;
	Node *right;
	int data;
	int left_child;
	
	Node() {}
};

Node* create(int data) {
	Node *node = new Node;
	node->data = data;
	node->right = NULL;
	node->left = NULL;
	node->left_child = 1;
	return node;
}

void insert(int data, Node *root) {

    printf("Inserting %d\n", data);
	// if root is empty
	if(root->data == -1) {
		root->data = data;
	}
	else {
		Node *new_node = create(data);
		while(true) {
			if(root->data >= data) {
				root->left_child++;
				if(root->left == NULL) {
					root->left = new_node;
					break;
				}
				else {
					root = root->left;
				}
			}
			else {
				if(root->right == NULL) {
					root->right = new_node;
					break;
				}
				else
					root = root->right;
				
			}
		}
	}
}

int num_left_child(int data, Node *root) {

	int ans = 0;	
	if(root->data == -1) return 0;
	while(true) {
	//	printf("%d %d\n", root->data, ans);
		if(data < root->data) {
			if(root->left == NULL) return ans;
			else root = root->left;
		}
		else if(data == root->data) {
			ans += root->left_child;
			return ans;
		}
		else {
			ans += root->left_child;
			if(root->right != NULL) root = root->right;
			else return ans;		
		}
	}
}

int main() {

	Node *root = create(-1);

	insert(20, root);
	insert(10, root);
	insert(24, root);
	insert(21, root);
	insert(15, root);

	printf("2: %d\n", num_left_child(2, root));
	printf("20: %d\n", num_left_child(20, root));
	printf("1: %d\n", num_left_child(1, root));
	printf("24: %d\n", num_left_child(24, root));
	printf("23: %d\n", num_left_child(23, root));

	return 0;
}
