#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;

    node(int d){
        data=d;
        next=NULL;
    }
     
};
void insert_At_Front(node*&head, node*&tail, int data){
    node*n=new node(data);
    if(head==NULL){ 
        head=n;
        tail=n;
        return;
    }
    else{
        n->next=head;
        head=n;
    }
}
void print(node*head){
    node*temp=head;
    while(temp!=NULL){
    cout<<temp->data<<"->";
    temp=temp->next;
    }
}
int main(){
     node*head=NULL;
     node*tail=NULL;
     insert_At_Front(head,tail,90);
     insert_At_Front(head,tail,63);
     insert_At_Front(head,tail,20);
     print(head);


    return 0;
}
/*
#include<iostream>
using namespace std;

class node{
   public:
   int data;
   node *next;
   //parametrized constructor
   node(int data){
    this->  data=data;
     this-> next=NULL;
   }

};

void insertAtHead(node *&head, int d){
	//new node create
	node *n=new node(d);
	n->next=head;
	head=n;
}

void print (node*&head){
	node*temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<'\n';
}

int main() {
    node* n1=new node(10);
	cout<<n1->data<<" "<<n1->next<<endl;  // 10   0
	node*head=NULL;
	insertAtHead(head,12);
	insertAtHead(head,15); 
	print (head);
	return 0;
}
*/