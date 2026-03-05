#include<bits/stdc++.h>
using namespace std;

class Node{

    public : 
    int val;
    Node * next;
    
    Node(int val){
        this->val = val;
        next = NULL;
    }

    // delete ptr : when we use the word delete only then the memory pointing to it is deleted and destructor is called
    ~Node(){
        //delete next; this can be still used to delete all nodes recusrively
    }
};

void travserseLL(Node* head){

    Node* temp = head;

    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
}
int main(){

    int n;
    vector<int> arr(n);

    cin >> n;

    Node* head  = NULL;
    Node* tail = NULL;
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
        Node* node = new Node(arr[i]);
        if(head == NULL){
            head = node;
            tail = node;
        }

        else {
            tail->next = node;
            tail = tail->next;
        }
    }

    // make a linked list from this array

    // delete head calls the destructor : delete head : destrutor of the class LL
    // Destructor is called via a. delete ptr b. or when go out of scope from stack/ heap/ data segment
    // 

    travserseLL(head);
    return 0;
}