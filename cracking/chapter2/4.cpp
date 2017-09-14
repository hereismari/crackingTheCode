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

Node* partition(int x, Node *n) {

    Node* head = n;
    Node* tail = n;

    Node *t = n->next;
    while(t != NULL) {

        Node *old_next = t->next;

        if(t->data < x) {
            t->next = head;
            head = t;
        }
        else {
            tail->next = t;
            tail = t;
        }
        t = old_next;
    }

    tail->next = NULL;
    return head;
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

    n = partition2(3, n);
    printf("Partition 3\n");
    n->printLinked();
 

    n = partition2(5, n);
    printf("Partition 5\n");
    n->printLinked();

    return 0;
}
