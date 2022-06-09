#include<iostream>
using namespace std;
class node{
public:
	int data;
	node*left;
	node*right;
	node(int data)
	{
		this->data=data;
		left=NULL;
		right=NULL;
	}
};
node* insertinbst(node*root,int data){
	if(root==NULL){
		root=new node(data);
	}
	else if(data<=root->data){
		root->left=insertinbst(root->left,data);
	}
	else{
		root->right=insertinbst(root->right,data);
	}
	return root;
}
node* createbinarysearchtree(node *root)
{
	int data;
	cout<<"enter the root elemnt"<<endl;
	cin>>data;
	root=NULL;
	// node*root=new node(data);
	while(data!=-1)
	{
		
		root=insertinbst(root,data);
		cout<<"enter the elemnt/child of root node: "<<endl;
		cin>>data;
	}
	return root;
}
void inorder(node*root){
	//base case
	if(root==NULL){
		return;
	}
	//recursive case
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void printpre(node*root){
	//base case
	if(root==NULL){
		return;
	}
	//recursive case
	cout<<root->data<<" ";
	printpre(root->left);
	printpre(root->right);
}
int main(){
	node*root=createbinarysearchtree(root);
	cout<<"inorder is : "<<endl;
	 inorder(root);
     cout<<endl;
	printpre(root);
	return 0;
}