
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    struct Node* next;
};

class LinkedList{

    // private:

    public:

    struct Node* head;

    LinkedList(){
        head = nullptr;
    }

    void addNode(int data){
        Node* newNode = new Node();
        newNode->val = data;
        newNode->next = NULL;
        if(head == NULL){
            head = newNode;
            return;
        }

        Node* last = head;

        while(last->next != NULL){
            last = last->next;
        }

        last->next = newNode;
    }

    void insertAfter(int val, int after){

        Node* node = head;

        while(node->val != after && node != NULL){
            node = node->next;
        }

        Node* newNode = new Node();
        newNode->val = val;
        newNode->next = node->next; 
        
        node->next = newNode;

    }

    void insertBefore(int val, int before){
        Node* node = head;
        Node* prev = new Node();

        while(node->val != before){
            prev = node;
            node = node->next;
        }

        Node* newNode = new Node();
        newNode->val = val;
        newNode->next = node;

        prev->next = newNode;

        if(head->val == before){
            head = newNode;
        }

    }

    struct Node* reverse(){
        Node* prev = NULL;
        Node* current = head;
        Node* next = head->next;

        while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    void display(struct Node* head){
        Node* node = head;

        while(node != NULL){
            cout<<node->val<<endl;
            node = node->next;
        }
    }

};

int main(){

    LinkedList l1;

    l1.addNode(10);
    l1.addNode(20);
    l1.addNode(30);
    l1.addNode(40);
    l1.addNode(50);

    // struct Node* head = l1.reverse();
    l1.insertAfter(100, 50);

    l1.insertBefore(400, 10);
    
    l1.display(l1.head);
}