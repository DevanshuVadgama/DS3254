#include <iostream>
using namespace std;

class node {
public:
int data;
node* next;

node(int val){
    data=val;
    next=NULL;
}
};

class List {
    node* head;
    node* tail;

public:
    List(){
        head=tail=NULL;
    }
    void prepend(int val){
        node* newnode = new node(val);
        if(head==NULL){
            head=tail=newnode;
        }
        else{
            (*newnode).next=head;
            head=newnode;
        }  
    }
    
    void append(int val){
        node* n = new node(val);
        if(head == NULL){
            head = tail = n;
        }
        else{
            (*tail).next = n;
            tail = n;
        }
    }

    void remove(int val){
        if(head == NULL){
            cout << "no content to remove" << endl;
            return;
        }
        if(head->data == val){
            node* temp = head;
            head = head->next;
            delete temp;
            if(head == NULL) tail = NULL; 
            return;
        }
        node* temp = head;
        while(temp->next != NULL && temp->next->data != val){
            temp = temp->next;
        }
        if(temp->next == NULL){
            cout << "value not found" << endl;
            return;
        }
        node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        if(nodeToDelete == tail) tail = temp;
        delete nodeToDelete;
    }

    void removelast(){
        if(head == NULL){
            cout << "nolast" << endl;
            return;
        }
        if(head == tail){
            delete head;
            head = tail = NULL;
            return;
        }
        node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void removeFirst(){
        if(head==NULL){
            cout<<"nothing to remove";
            return;
        }
        if(head==tail){
            delete head;
            head=NULL;
            tail=NULL;
            return;
        }
        node*temp;
        temp=head->next;
        delete head;
        head=temp;

    }
    void insert(int pos,int val){
        if(pos<0){
            cout<<"invalid";
            return;
        }
        if(pos==0){
            prepend(val);
            return;
        }

        node* temp = head;
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        node* new_node= new node(val);
        new_node->next=temp->next;
        temp->next=new_node;
    }

    int search(int key){
        
        node* temp;
        temp=head;
        int i=0;
        while(temp!=NULL){
            if((*temp).data==key){
                return i;
            }
            temp=temp->next;
            i++;
        }
        return -1;
    }

    int length(){
        node*temp;
        temp=head;
        int x=0;
        while(temp!=NULL){
            temp=temp->next;
            x++;
        }
        return x;
    }

    void printLL(){
        node* temp;
        temp=head;
        while(temp!=NULL){
            cout<<(*temp).data<<"-> ";
            temp=(*temp).next;
        }
        cout<<"NULL"<<endl;
    }

};
int main(){
  List ll;
  ll.prepend(3);
  ll.prepend(2);
  ll.prepend(1);
  cout<<ll.length()<<endl;

  ll.printLL();
}