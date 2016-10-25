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

    Node* getKthLast(int k, int &i) {
        
        if(this ==NULL) {
            return NULL;
        }
        
        Node* res = (this->next)->getKthLast(k, i);
        i++;

        if(k == i) return this;
        else {
            return res;
        }
    }

    Node* getKthLast(int k) {
        int i = 0;
        return getKthLast(k, i);
    }

};

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
    
    printf("1kth: %d\n", n->getKthLast(1)->data);
    printf("2kth: %d\n", n->getKthLast(2)->data);
    printf("3kth: %d\n", n->getKthLast(3)->data);
    printf("4kth: %d\n", n->getKthLast(4)->data);
    
    return 0;
}
