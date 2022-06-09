#include <iostream>
#include<queue>
using namespace std;

class node{
	public:
	int data;
	node*left;
	node*right;
  //constructor
	node(int d){
	   data=d;
	   left=NULL; 
	   right=NULL;
	}

};

node*build_tree(node*root){
    cout<<"Enter data"<<endl;
    int data;
    cin>>data;
    node* n= new node(data);
    if(data==-1){
        return NULL;
    }
    else{
     cout<<"Enter data for inserting left of: "<<endl;
     n->left=build_tree(n->left);
     cout<<"Enter data for inserting right of: "<<endl;
     n->right=build_tree(n->right);
    return n;
    }
	
}

void preorder(node*root){
    //base 
    if(root==NULL) return ;
    //recursive
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node*root){
    if(root==NULL) return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int countnodes(node*root){
    //base 
    if(root==NULL) return 0;

    //recursive case
   return countnodes(root->left)+countnodes(root->right)+1;
}

int heightof_tree(node*root){
    //base 
    if(root==NULL) return 0;
    //recursive case
   return max( heightof_tree(root->left),heightof_tree(root->right))+1;
}

int sumof_node(node*root){
    //base 
    if(root==NULL) return 0;
    //recursive case
   return sumof_node(root->left)+sumof_node(root->right)+root->data;
}

int diameterof_tree(node*root){
    //base 
    if(root==NULL) return 0;
     int op1=diameterof_tree(root->left);
     int op2=diameterof_tree(root->right);
     int op3=heightof_tree(root->left)+heightof_tree(root->right);
    return  max(op1,max(op2,op3));
}
class Pair{
    public:
    int diameter;  //diameter
    int height; //height

};

Pair diameterof_treefast(node*root){
    Pair p;
    //base 
    if(root==NULL){
        p.height=0;
        p.diameter=0;
        return p;
    }

    //recursive
    Pair l=diameterof_treefast(root->left);
    Pair r=diameterof_treefast(root->right);
    p.height=max(l.height, r.height)+1;

    int opt1=l.diameter;
    int opt2=r.diameter;
    int opt3=l.height+r.height;
    p.diameter=max(opt1,max(opt2,opt3));
    return p;
}

int main() {
	//  node*root=NULL;
    //  root=build_tree(root);
    node*root=build_tree(root);
    // 8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1
    cout<<"printing preorder "<<endl;
    preorder(root);
    cout<<endl;
    cout<<"printing inorder "<<endl;
    inorder(root);
    cout<<endl; 
    cout<<"Number of Nodes in Tree is: ";
    cout<<countnodes(root)<<endl;
    cout<<"Height of tree is: "<<heightof_tree(root)<<endl;
    cout<<"Sum Of Nodes Of tree is: "<<sumof_node(root)<<endl;
    cout<<"Diameter of tree is: "<<diameterof_tree(root)<<endl;
    Pair x=diameterof_treefast(root);
    cout<<"Diameter of tree is: "<<x.diameter<<endl;
	return 0;
}