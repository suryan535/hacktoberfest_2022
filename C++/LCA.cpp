#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left;
	Node *right;

	Node(int n)
	{
		data=n;
		left=NULL;
		right=NULL;
	}
};

Node *findLCA(Node *root,int n1,int n2)
{
	if(root==NULL) return NULL;

	if(root->data==n1 || root->data==n2) return root;

	Node *lLCA=findLCA(root->left,n1,n2);
	Node *rLCA=findLCA(root->right,n1,n2);

	if(lLCA && rLCA) return root;

	return lLCA?lLCA:rLCA;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<findLCA(root,4,5)->data<<"\n";
    cout<<findLCA(root,4,6)->data<<"\n";
    cout<<findLCA(root,3,4)->data<<"\n";
    cout<<findLCA(root,2,4)->data<<"\n";

    return 0;
}