#include <iostream>

using namespace std;

class Node {
public:
    Node *prev, *next;
    int data;

    Node(int user_id)
    {
        this->prev = NULL;
        this->next = NULL;
        this->data = NULL;
    }

};

class LinkedList {
public:
    Node *head, *tail;
    int nodes, max_nodes;
    LinkedList(int maxnodes) 
    {
        this->max_nodes = maxnodes;
        this->head = NULL;
        this->tail = NULL;
        this->nodes = 0;
    }
    int size(){
        return nodes;
    }

    bool empty()
    {
       return nodes <= 0; 
    }
    bool full() {
        return nodes == max_nodes;
    }
    void insert_tail(Node* new_node){
        if(empty()) {
            new_node = head;
            new_node = tail;
            nodes++;
        }
        else if(full()) 
        {
            cout << "The list is full.";
        }
        else {
            new_node->prev=tail;
            tail->next=new_node;
            tail=new_node;
        }
    }
    void insert_head(Node* new_node)
    {
        if (empty())
        {
            head = new_node;
            tail = new_node;
            nodes++;
        }
        else if (full())
        {
            cout << "Attempting to insert when the list is full\n";
        }
        else
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
            nodes++;
        }   
    };
    void delete_tail()
    {
        if (empty())
        {
            cout << "Attempting to delete when the list is empty\n";
        }
        else if (nodes == 1)
        {
            head=NULL;
            tail=NULL;
            nodes--;
        }
        else
        {
            tail=tail->prev;
            tail->next->prev=NULL;
            tail->next=NULL;
            nodes--;
        }   
    };
    void delete_head()
    {
        if (empty())
        {
            cout << "Attempting to delete when the list is empty\n";
        }
        else if (full())
        {
            head=NULL;
            tail=NULL;
            nodes--;
        }
        else
        {
            head=head->next;
            head->prev->next=NULL;
            head->prev=NULL;
            nodes--;
        }   
    };
};

class Stack {
public:
    LinkedList* LL;

    Stack(int maxnodes) 
    {
        LL = new LinkedList(maxnodes);
    }

    int size()
    {
        LL->size();
    }

    bool isEmpty()
    {
        LL->empty();
    }
    bool isFull() 
    {
        LL->full();
    }
    void push(Node* new_node)
    {
        LL->insert_head(new_node);
    }
    void pop()
    {
        LL->delete_head();
    }
    void clear(Node* head)
    {
        while(head!=NULL){
            LL->delete_head();
        }
    }
};

int main() {
    NULL;
};