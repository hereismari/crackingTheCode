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
        
        if(n->data == -1) {
            printf("EMPTY\n");
        }
        else {
            
            while(n->next != NULL) { 
                printf("%d --> ", n->data); 
                n = n->next;
            }
            printf("%d\n", n->data);
    
        }
    }

    void removeMiddle() {

        Node* t1 = this;
        Node *prev_t2 = NULL;
        Node *t2 = this;

        if(t1->next == NULL) {
            t1->data = -1;
        }
        else {
            int cont = 0;
            while(t1 != NULL) {
                if(cont == 2) {
                    prev_t2 = t2;
                    t2 = t2->next;
                }

                cont = cont % 2;
                cont = cont + 1;
                t1 = t1->next;
            }
            if(cont == 2) {
                  prev_t2 = t2;
                  t2 = t2->next;
            }


            prev_t2->next = t2->next;
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

    n->removeMiddle();
    n->printLinked();
    
    n->removeMiddle();
    n->printLinked();
    
    n->removeMiddle();
    n->printLinked();
    
    n->removeMiddle();
    n->printLinked();
    
    n->removeMiddle();
    n->printLinked();
    
    n->removeMiddle();
    n->printLinked();
   
    n->removeMiddle();
    n->printLinked();
     
    n->removeMiddle();
    n->printLinked();
    
    n->removeMiddle();
    n->printLinked();
    

    return 0;
}
