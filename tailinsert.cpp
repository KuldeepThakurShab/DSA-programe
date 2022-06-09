#include<iostream>
using namespace std;

class node{
    public:
   int data;
   node *next;
   node(int d){
       data=d;
       next=NULL;
   }

};

void insertat_tail(node*&head, node*&tail, int data){
    //new node create
    node*n=new node(data);
    if(head==NULL){
        head=n; 
        tail=n;
        return;
    }
    else{
        tail->next=n;
        tail=n;
    }
}

void printll(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}

int main(){

     node*head=NULL;
     node*tail=NULL;
     insertat_tail(head,tail,6);
      insertat_tail(head,tail,9);
       insertat_tail(head,tail,19);
    printll(head);
    return 0;
}