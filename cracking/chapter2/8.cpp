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

pair<bool, Node*> checkLoop(Node* n) {

    Node *it1 = n;
    Node *it2 = n;

    bool flag = false;

    while(it1 != NULL && it2 != NULL) {

        if(it1 == it2 && flag) break;
        flag = true;
        it1 = it1->next;
        if(it2->next != NULL)
            it2 = it2->next->next;
        else
            it2 = it2->next;
    }

    if(it1 == NULL || it2 == NULL) return make_pair(false, new Node);

    it1 = n;
    while(it1 != it2) {
        it1 = it1->next;
        it2 = it2->next;
    }

    return make_pair(true, it1);
}

int main() {

    Node *n = new Node;
    n->data = 3;
    n->next = NULL;
    
    int size_a = 8;
    int a[] = {1, 2, 3, 4, 5, 3, 2, 3};
    for(int i = 0; i < size_a; i++) n->appendToTail(a[i]);

    Node *n1 = n->getElement(3);
    
    printf("%d\n", n1->data);
    n->getElement(7)->next = n1;

    pair<bool, Node*> answer = checkLoop(n);
    if(answer.first) {
        printf("%d\n", answer.second->data);
    }
    else {
        printf("No loop\n");
    }

    return 0;
}
