//BST  //keft<parent<right
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Node{
	public:
	int value;
	Node *left;
	Node *right;
		Node(int v){
			value = v;
			right= left = NULL;
		}		
};
Node *insert(Node *root, int val) //insert 1 value at a time
{
	if(root==NULL){ //base case
		root = new Node(val);
		return root;
	}
	if(val < root->value)
	root->left = insert(root->left, val);
	else
	root->right = insert(root->right, val);
	
	return root;
}



bool search(Node *root, int key) //search a value
{
	if(root==NULL) //base case
		return false;
	if(key==root->value)
	 return true;
	if(key < root->value)
	return search(root->left, key);
	else
	return search(root->right, key);
	
	 return false;
}
Node *buildBST(vector <int> &nums){
	Node *root = NULL;
	for(int i=0;i<nums.size();i++)
	root = insert(root,nums[i]);
	return root; }
	
	Node *getInorderSuccessor(Node *root){ //left most node iin right subtree
	while(root!=NULL && root->left != NULL)
		root = root->left;
	return root;
}

Node *deleteNode(Node *root, int val) //value you want to delete
{
	if(root==NULL)
	return NULL;
	if(val<root->value)
		root->left = deleteNode(root->left,val);
	else if(val>root->value)
		root->right = deleteNode(root->right,val);
	else{ //case where root->value == val
		if(root->left == NULL){ //guaranteed 1 child NULL
		Node *temp = root->right; //right == any value or NULL
		delete root;
		return temp; }
		else if(root->right ==NULL)
		{
			Node *temp = root->left;
			delete root;
			return temp;
		}		
	else //2children
	{ 
		Node *IS = getInorderSuccessor(root->right);
		root->value = IS->value;
		root->right = deleteNode(root->right, IS->value);
	} }
	return root;
	}	
void inorder(Node *root){
	if(root==NULL)
	return;
	inorder(root->left);
	cout<<root->value<<" ";
	inorder(root->right);


}	

int main(){
	vector<int> nums = {3,2,1,5,6,4}; //DFS
	Node *root = buildBST(nums);
	cout<<root->value<<endl;
	inorder(root);
	cout<<endl;
//	cout<<search(root,10);
cout<<"after : ";
deleteNode(root,6);
inorder(root);
	return 0;
}