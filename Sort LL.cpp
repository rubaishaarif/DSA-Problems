#include<iostream>
#include<vector>
using namespace std;
class Node{
	public:
	int data;
	Node *next;
		Node(int val){
			data = val;
			next = NULL;
		}
};
class LL{
	Node *head;
	Node *tail;
	public:
		LL(){
			head = tail = NULL; }
	void push_back(int val){ //push from back
		Node *newNode =  new Node(val);
		if(head ==NULL)
			head=tail= newNode;
		else{
		tail->next = newNode;
		tail = newNode;
		} }
		
		void print(){ //display
			Node *temp =  head;
			while(temp != NULL){
				cout<<temp->data<<" -> ";
				temp = temp->next;
			}
			cout<<"NULL"<<endl;
		}
		void concatenate(LL *list1, LL *list2){
			Node *l1 = list1->head;
			Node *l2 = list2->head;
			while(l1!=NULL){
				this->push_back(l1->data);
				l1 = l1->next;
			} 
		while(l2!=NULL){
			this->push_back(l2->data);
			l2 = l2->next;
		}

	}
		void sort(){
		if(head==NULL)
		return ;
		Node* t1 = head;
		
		while(t1!=NULL){
			Node *t2 = t1->next;
			while(t2!=NULL){
			if(t1->data < t2->data){
			int temp =t1->data; //use int to swap values
			
			t1->data=t2->data;
			t2->data=temp; 
			}
			t2= t2->next; 
			}
			t1= t1->next;
		}
		
	} 
};
int main(){
     LL L,M,N;
	L.push_back(2);
	L.push_back(4);
	L.push_back(6);
	L.push_back(8);
	L.push_back(10);
	L.print();
	M.push_back(1);
	M.push_back(3);
	M.push_back(5);
	M.push_back(7);
	M.push_back(9);
	M.print();
	N.concatenate(&L,&M);
	cout<<"concatenate list :\n"; 
	N.print();
	cout<<"sorted list\n";
	N.sort();
	N.print();
	
	return 0;}