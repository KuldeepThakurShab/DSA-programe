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
	 
    node*root=build_tree(root);
    // 8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1
    
    Pair x=diameterof_treefast(root);
    cout<<"Diameter of tree is: "<<x.diameter<<endl;
	return 0;
}