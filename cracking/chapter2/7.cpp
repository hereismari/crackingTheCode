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

    int getLength() {

        int length = 1;
        Node* n = this;
        while(n->next != NULL) { 
            length++;
            n = n->next;
        }
        
        return length;
    }

    Node* getElement(int index) {
        int length = 0;
        Node* n = this;
        while(n->next != NULL) { 
            if(length == index) return n;
            length++;
            n = n->next;
        }     

        return NULL;
    }
};

Node * intersection(Node *n1, Node *n2) {
    
    int len_n1 = n1->getLength();
    int len_n2 = n2->getLength();

    Node *it1 = n1;
    Node *it2 = n2;

    int cont = 0;
    if(len_n1 > len_n2) {
        while(len_n2 + cont < len_n1) {
            it1 = it1->next;
            cont++;
        }
    }
    else {
        while(len_n1 + cont < len_n2) {
            it2 = it2->next;
            cont++;
        }
    }

    while(it1 != NULL && it2 != NULL) {
        if(it1 == it2) return it1;
        else {
            it1 = it1->next;
            it2 = it2->next;
        }
    }

    return NULL;
}

int main() {

    Node *n1 = new Node;
    n1->data = 3;
    n1->next = NULL;
    
    Node *n2 = new Node;
    n2->data = 3;
    n2->next = NULL;

    int size_a = 8;
    int a[] = {1, 2, 3, 4, 5, 3, 2, 3};
    
    int size_b = 4;
    int b[] = {2, 2, 1, 4};
    
    for(int i = 0; i < size_a; i++) n1->appendToTail(a[i]);
    for(int i = 0; i < size_b; i++) n2->appendToTail(b[i]);
    
    printf("Linked list :)\n");
    n1->printLinked();
    
    n2->getElement(1)->next = n1->getElement(3);
    
    n2->printLinked();

    printf("%d\n", intersection(n1, n2)->data);

    return 0;
}
