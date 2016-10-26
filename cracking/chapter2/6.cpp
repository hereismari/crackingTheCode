#include <bits/stdc++.h>

using namespace std;

struct Node {
    
    Node* next;
    int data;
   
    Node(int data = 0) {
        this->data = data;
        this->next = NULL;
    }

    void appendToTail(int d) {
        
        Node *end = new Node;
        end->data = d;
        end->next = NULL;

        Node* n = this;
        while(n->next != NULL) { 
            n = n->next;
        }
        
        n->next = end;
    }

    void printLinked() {
        Node* n = this;
        while(n->next != NULL) { 
            printf("%d --> ", n->data); 
            n = n->next;
        }
        printf("%d\n", n->data);
    }

};

Node* reverse(Node *n) {
    Node *head = NULL;
    Node *it = n;

    while(it != NULL) {
        Node* new_node = new Node;
        new_node->data = it->data;
        new_node->next = head;
        head = new_node;
        it = it->next;
    }

    return head;
}

bool isPalindrome(Node *n) {

    Node* rev_n = reverse(n);
    rev_n->printLinked();

    Node* it1 = n;
    Node* it2 = rev_n;

    while(it1 != NULL && it2 != NULL) {
        if(it1->data != it2->data)
            return false;

        it1 = it1->next;
        it2 = it2->next;
    }

    return true;
}

int main() {

    Node *n = new Node;
    n->data = 3;
    n->next = NULL;

    printf("Just the head == 3\n");
    n->printLinked();

    int size = 8;
    int a[] = {1, 2, 3, 4, 5, 3, 2, 3};
    for(int i = 0; i < size; i++) n->appendToTail(a[i]);
    
    printf("Linked list :)\n");
    n->printLinked();

    if(isPalindrome(n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
