# include <stdio.h>

using namespace std;

struct Node {
    
    Node* next;
	Node* previous;
    int data;

    Node() {}
	Node(int data, Node* previous, Node* next) {
		this->data = data;
		this->previous = previous;
		this->next = next;
	}
   
    void appendToTail(int d) { 

        printf("Appending: %d\n", d);
        
        Node* n = this;
        if(n->data == -1) n->data = d;
        else {
            Node* end = new Node(d, NULL, NULL);
			
            while(n->next != NULL) { 
				n = n->next;
            }
			
			n->next = end;
			end->previous = n;
		}

        this->printLinked();
    }

    void printLinked() {

        Node* n = this;
		if(n->data == -1) return;

        while(n->next != NULL) { 
            printf("%d --> ", n->data); 
            n = n->next;
       	}
        printf("%d\n", n->data);

		while(n->previous != NULL) {
		    printf("%d --> ", n->data); 
            n = n->previous;
		}
		printf("%d\n", n->data);
    }

    void remove(int d) {

        printf("Removing: %d\n", d);
        
        Node* n = this;
        if(n->data == d && n->next != NULL) {
            if(n->next->next != NULL) n->next->next->previous = n;
            n->data = n->next->data;
            n->next = n->next->next;
        }
        else if(n->data == d) n->data = -1;
        else {
            Node *n_p = NULL;
            while(n->data != d && n->next != NULL) {
                n_p = n;
                n = n->next;
            }
            if(n->data == d) {
                n_p->next = n->next;
                if(n->next != NULL) n->next->previous = n_p;
            }
        }

        this->printLinked();
    }
};

int main() {

    Node *node = new Node(-1, NULL, NULL);

    node->appendToTail(1);
    node->appendToTail(2);
    node->appendToTail(3);
    node->appendToTail(4);

    node->remove(1);
    node->remove(3);

    node->appendToTail(11);
    node->appendToTail(10);

    node->remove(10);

    return 0;
}
