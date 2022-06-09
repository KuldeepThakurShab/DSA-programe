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
int main(){
    node n1(5),n2=8, n3(9);
    n1.next=&n2; 
    n2.next=&n3;
    node*n4=new node(15);
    cout<<(*n1.next).data<<endl;
    cout<<n4->next<<" "<<n4->data<<endl;
    cout<<n1.next<<" "<<(n1.next)->data<<endl;

    return 0;
}