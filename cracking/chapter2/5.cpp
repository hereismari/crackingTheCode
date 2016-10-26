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

Node* sumListsCaseI(Node *n1, Node *n2) {
    
    Node* res = new Node;
    Node* it = res;

    bool aux = 0;
    int sum;

    while(n1 != NULL or n2 != NULL) {
        if(n1 != NULL and n2 != NULL) {
            sum = n1->data + n2->data + aux;
        }
        else if(n1 != NULL) {
            sum = n1->data + aux;
        }
        else if(n2 != NULL) {
            sum = n2->data + aux;
        }        

        aux = sum >= 10;
        
        it->data = sum % 10;

        if((n1 != NULL && n1->next != NULL) || 
           (n2 != NULL && n2-> next != NULL) ||
           (aux))
            it->next = new Node;
        else
            it->next = NULL;

        it = it->next;
        if(n1 != NULL) n1 = n1->next;
        if(n2 != NULL) n2 = n2->next;
    }

    if(aux) {
        it->data = 1;
        it->next = NULL;
    }
    
    return res;
}

void auxListCaseII(Node* n1, Node* n2, int back, int &aux, Node* new_node, bool flag = true) {
    
    if(n1 == NULL && n2 == NULL) {
        return;
    }

    if(n1->next == NULL && n2->next == NULL)
        new_node->next = NULL;
    else
        new_node->next = new Node;
    
    if(back > 0) 
        auxListCaseII(n1->next, n2, back-1, aux, new_node->next, false);
    else 
        auxListCaseII(n1->next, n2->next, back-1, aux, new_node->next, false);

    int sum;
    if(back <= 0) {   
        sum = n1->data + n2->data + aux;
    }
    else {
        sum = n1->data + aux;
    }

    aux = sum >= 10;
    int data = sum % 10;

    if(flag && aux) {
        Node* old_next = new_node->next;
        new_node->data = 1;
        new_node->next = new Node;
        new_node->next->data = data;
        new_node->next->next = old_next;
    }
    else {
        new_node->data = data;
    }
}

Node* sumListsCaseII(Node* n1, Node* n2) {

    int size_n1 = 0;
    int size_n2 = 0;

    Node* it = n1;
    while(it != NULL) { size_n1++; it = it->next; }
    
    it = n2;
    while(it != NULL) { size_n2++; it = it->next; }

    int aux = 0;
    Node * new_node = new Node;
    if(n1 > n2) auxListCaseII(n1, n2, size_n1 - size_n2, aux, new_node);
    else auxListCaseII(n2, n1, size_n2 - size_n1, aux, new_node);    
    
    return new_node;
}

Node* createLinkedList(int a[], int size) {
    Node *n = new Node;
    n->data = a[0];
    n->next = NULL;

   for(int i = 1; i < size; i++) n->appendToTail(a[i]);
   return n;
}

int main() {

    int size_a = 2;
//  int a[] = {1, 2, 3};
//  int a[] = {9, 9};
    int a[] = {9, 9};
    Node* n1 = createLinkedList(a, size_a);
 
    int size_b = 2;
//  int b[] = {1, 2, 3, 1, 2};
//  int b[] = {9, 8, 1, 5, 9, 5};

    int b[] = {9, 9};
    Node* n2 = createLinkedList(b, size_b);
    
    printf("Linked list a\n");
    n1->printLinked();
 
    printf("Linked list b\n");
    n2->printLinked();

    printf("Sum case I\n");
    sumListsCaseI(n1, n2)->printLinked();

    printf("Sum case II\n");
    sumListsCaseII(n1, n2)->printLinked();

    return 0;
}
