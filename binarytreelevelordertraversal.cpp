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
		this->data=d;
		this->left=NULL;
		this->right=NULL;
	}

};

node*build_tree(node*root){
    cout<<"Enter data"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for inserting left of: "<<endl;
    root->left=build_tree(root->left);
    cout<<"Enter data for inserting right of: "<<endl;
    root->right=build_tree(root->right);
    return root;
	
}

void levelOrderTraversal(node*root){
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node*temp=q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left){
            q.push(temp->left);
        }
         if(temp->right){
            q.push(temp->right);
        }
    }
}

int main() {
	 node*root=NULL;
    root= build_tree(root);
    //8 3 1 -1 6 4 -1 7 -1 10 -1 14 13 -1 -1 
    //3 1 4 -1 -1 2 -1 -1 5 6 -1 -1 -1
    cout<<"printing level order taversal"<<endl;
    levelOrderTraversal(root);

	return 0;
}