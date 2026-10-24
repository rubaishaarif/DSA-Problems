#include<iostream>
using namespace std;
class Node{
		public:
	int data;
	Node *next;
	Node *prev;

	Node(int val){
		data = val;
		next = prev = NULL;}
};
class Deque{
	Node *tail;
	Node *head;
	public:
	Deque(){ tail = head = NULL;}
	//push from rear
	void EnqueueAtEnd(int val) 
	{
		Node *newNode = new Node(val);
		if(head==NULL)
			head = tail = newNode;
		else
		{	
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
	}
	//push from front
		void EnqueueAtFront(int val) 
	{
		Node *newNode = new Node(val);
		if(head==NULL)
			head =tail = newNode;
		else
		{	
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
	}
	//delete from front
	void DequeueAtFront() 
	{
		if(head==NULL)
		{
			cout<<"Queue is empty\n";
			return;
		}
		Node *temp = head;
		if(head==tail)
			head = tail = NULL; 
		else
		{
			head = head->next;
			head->prev = NULL;	
		}
		delete temp;
	}
	//delete from rear
		void DequeueAtRear() 
	{
		if(head==NULL)
		{
			cout<<"Queue is empty\n";
			return;
		}
		Node *temp = tail;
		if(head==tail)
		head = tail = NULL;
		else
		{
			tail = tail->prev;
			tail->next = NULL;
		}
		delete temp;
	}
	void print() //display nodes
	{
		if(head==NULL){
		cout<<"Queue is empty\n";
		return ;}
		Node *temp = head;
		while(temp!=NULL)
		{
			cout<<temp->data<<"->";
			temp = temp->next;
		}
		cout<<"NULL"<<endl;
		
	}
	~Deque(){
		Node *temp = head;
		while(temp!=NULL)
		{
			Node *nextNode = temp->next;
			delete temp;
			temp = nextNode;
		}
		cout<<"Destructor called"<<endl;
		
	}
};

int main(){
	Deque q1;
	cout<<"Queue:\n";
	q1.EnqueueAtEnd(1);
	q1.EnqueueAtEnd(2);
	q1.EnqueueAtEnd(68);
	q1.EnqueueAtEnd(7);
	q1.EnqueueAtEnd(90);
	cout<<"After enqueue at rear\n";
	q1.print();
	q1.EnqueueAtFront(5);
	q1.EnqueueAtFront(4);
	q1.EnqueueAtFront(3);
	cout<<"After enqueue at front\n";
	q1.print();
	q1.DequeueAtRear();
	q1.DequeueAtRear();
	q1.DequeueAtRear();
	cout<<"After dequeue at rear\n";
	q1.print();
	q1.DequeueAtFront();
	q1.DequeueAtFront();
	cout<<"After dequeue at front\n";
	q1.print();
	
	return 0;
}