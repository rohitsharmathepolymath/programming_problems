#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        this->data= val;
        this->next =nullptr;
    }
};

class sll
{
private:
    /* data */
public:
    Node* head;
    sll(){
        this->head=nullptr;
    }
    void insertAtHead(int val){
        Node* n = new Node(val);
        n->next=head;
        head = n;
    }

    void displayll(){
        Node* temp= head;
        while(temp != nullptr){
            cout<<temp->data<<"->";
            temp= temp->next;
        }
        cout<< "NULL" << endl;
    }

    void insertAtPosition(int val, int pos){
        Node* n = new Node(val);
        if(head==nullptr || pos == 1 ){
            insertAtHead(val);
            return;
        }
        Node* temp = head;
        int count=0;
        while (count<pos-2)
        {
            temp = temp->next;
            count++;
        }
        n->next = temp->next;
        temp->next= n;
    }
    
    void insertAtTail(int val){
        Node* n = new Node(val);
        if (head== nullptr){
            head = n;
        }else{
            Node* temp = head;
            while (temp->next!= nullptr)
            {
                temp= temp->next;   
            }
            temp->next= n;
        }
    }
};
 int main() {
    sll ll;
    cout<<"working"<<endl;
    ll.insertAtPosition(78,1);
    ll.displayll();
    ll.insertAtHead(34);
    ll.insertAtHead(43);
    ll.insertAtHead(65);
    ll.displayll();
    ll.insertAtTail(1010);
    ll.displayll();
    return 0;
 }