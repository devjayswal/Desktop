#include<iostream>
using namespace std;

    class node{
        public:
        int data;
        node*next;
        node(int val){data=val;
        next=NULL;}
    };
    void insertattail(node* &head,int val){
        
        node*n=new node(val);
        if(head==NULL)
        {
            head=n;
            return;
        }
        node*temp=head;
        while(temp->next!=NULL){temp=temp->next;}
        temp->next=n;        
    }
    //for insert any element at a different place you can make a special type of function here//
void insertathead(node* &head, int val){

node*n=new node(val);
n->next=head;
head=n;
};
//like this^^^^^^^^
    void disply(node* head){
        node*temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" --> ";
            temp=temp->next;}
            cout<<endl;

        }
    bool searh(node*head, int key){
        node*temp=head;
        while(temp!=NULL){
            if(temp ->data==key){return true;}
            temp=temp->next;

        }return false;
    }

    int main (){
        node*head=NULL;
     //if you wanna make a element you can make here
        insertattail(head,1);
         insertattail(head,2);
          insertattail(head,3);
          disply(head);
          // insertathead(head,4);
         //disply(head);
         //like this
          insertathead(head,4);
         disply(head);
          return 0;

    }