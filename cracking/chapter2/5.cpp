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

        if((n1 != NULL && n1->next != NULL) || (n2 != NULL && n2-> next != NULL))
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
    else it = NULL;
    
    return res;
}

pair<Node*, Node*> auxListCaseII(Node* n1, Node* n2, int back, int &aux) {
    
    if(n1 == NULL && n2 == NULL) return make_pair(NULL, new Node);
    
    pair<Node*, Node*> a1;
    if(back > 0)
        a1 = auxListCaseII(n1->next, n2, back-1, aux);
    else 
        a1 = auxListCaseII(n1->next, n2->next, back-1, aux);

    Node* res = a1.second;
    Node* ans = a1.first;

    if(back <= 0) {
        int sum = n1->data + n2->data + aux;
        printf("%d %d\n", res->data, sum);
        aux = sum >= 10;
        res->data = sum % 10;
            
        if(back == 0) {
            if(aux) {
                res->next = new Node;
                res->next->data = 1;
                res->next->next = NULL;
            }
            else {
                res->next = NULL;
            }
        }
        else res->next = new Node;

        if(ans == NULL) ans = res;
        return make_pair(ans, res->next);
    }
    else return a1;
}

/*Node* sumListsCaseII(Node* n1, Node* n2) {

    int size_n1 = 0;
    int size_n2 = 0;

    Node* it = n1;
    while(it != NULL) { size_n1++; it = it->next; }
    
    it = n2;
    while(it != NULL) { size_n2++; it = it->next; }

    int aux = 0;
    if(n1 > n2) return auxListCaseII(n1, n2, size_n1 - size_n2, aux).first;
    else return auxListCaseII(n2, n1, size_n2 - size_n1, aux).first;    
}*/

Node* createLinkedList(int a[], int size) {
    Node *n = new Node;
    n->data = a[0];
    n->next = NULL;

   for(int i = 1; i < size; i++) n->appendToTail(a[i]);
   return n;
}

int main() {

    int size_a = 3;
    int a[] = {1, 2, 3};
    Node* n1 = createLinkedList(a, size_a);
 
    int size_b = 5;
    int b[] = {1, 2, 3, 1, 2};
    Node* n2 = createLinkedList(b, size_b);
    
    printf("Linked list a\n");
    n1->printLinked();
 
    printf("Linked list b\n");
    n2->printLinked();

    printf("Sum case I\n");
    sumListsCaseI(n1, n2)->printLinked();

//  printf("Sum case II\n");
//    sumListsCaseII(n1, n2)->printLinked();

    return 0;
}
