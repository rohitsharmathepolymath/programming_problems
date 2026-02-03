#include<iostream>
using namespace std;
class Node{
    public:
    char data;
    Node* prev;
    Node* next;
    Node(char val){
        this->data= val;
        this->prev = nullptr;
        this->next =nullptr;
    }
};

class dll
{
private:
    /* data */
public:
    Node* head;
    dll(){
        this->head=nullptr;
    }
    // void insertAtHead(int val){
    //     Node* n = new Node(val);
    //     n->next=head;
    //     head = n;
    // }
    // void insertAtPosition(int val, int pos){
    //     Node* n = new Node(val);
    //     if(head==nullptr || pos == 1 ){
    //         insertAtHead(val);
    //         return;
    //     }
    //     Node* temp = head;
    //     int count=0;
    //     while (count<pos-2)
    //     {
    //         temp = temp->next;
    //         count++;
    //     }
    //     n->next = temp->next;
    //     temp->next= n;
    // }

    void insertAtTail(char val){
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
            n->prev = temp;
        }
    }

    void displayll(){
        Node* temp= head;
        while(temp != nullptr){
            cout<<temp->data<<"->";
            temp= temp->next;
        }
        cout<< "NULL" << endl;
    }

    void rotateByN(int n){
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = head;
        head->prev = temp;
        while(n--){
            head = head->next;
            temp = temp->next;
        }
        head->prev = nullptr;
        temp->next = nullptr;

    }
    
};
 int main() {
    dll ll;
    cout<<"working"<<endl;
    ll.insertAtTail('a');
    ll.insertAtTail('b');
    ll.insertAtTail('c');
    ll.insertAtTail('d');
    ll.insertAtTail('e');
    ll.displayll();
    ll.rotateByN(3);
    ll.displayll();
    return 0;
 }