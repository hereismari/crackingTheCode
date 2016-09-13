#include <bits/stdc++.h>

using namespace std;

struct Node {
    
    Node* next;
    int data;
    
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

    void removeAll(int x) {
        
        Node* n = this;
        
        while(n->next != NULL && n->data == x) n = n->next;
        this->data = n->data;
        this->next = n->next;

        Node *t1 = this;
        if(t1->next != NULL) {
            Node *t2 = this->next;
            while(t2 != NULL) {
                if(t2->data == x) {
                    t1->next = t2->next;
                    t2 = t2->next;
                }
                else {
                    t1 = t2;
                    t2 = t2->next;
                }
            }
        }
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
    
    n->removeAll(3);
    printf("Removed 3\n");
    n->printLinked();

    return 0;
}
