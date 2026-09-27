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
class CQueue{
    Node *head; //front
    Node *tail; //rear
     public:
     	CQueue(){
     		head = tail = NULL;
     		
		 }
		bool empty(){
			 return head == NULL;
		} 
		void enqueue(int val){ //push from rear/tail
			Node* newNode = new Node(val);
			if(empty()){
			head = tail = newNode;
			tail->next = head;
		}
			else{
			tail->next = newNode;
			tail = newNode;
			tail->next = head;
	}
		}
		void dequeue() //delete from head
		{
			if(empty()){
			cout<<"Queue is empty\n";
			return ;
		}
			Node *temp = head;
			head = head->next;
			tail->next = head;
			delete temp;
		}
		int front()
		{
			if(empty()){
			cout<<"Queue is empty\n";
			return -1; }
			else
			return head->data;
		}
		void print(){
				if(empty()){
			cout<<"Queue is empty\n";
			return; }
			Node* temp = head;
			do{
				cout<<temp->data<<"->";
				temp = temp->next;
			}
			while (temp!=head);
			cout<<"NULL\n";
		}
		~CQueue() {
        while (!empty()) {
            dequeue();
        }
        cout<<"Destructor called\n";
    }
};
	
		int main(){
			CQueue q;
			q.enqueue(1);
			q.enqueue(5);
			q.enqueue(3);
			q.enqueue(9);
			q.print();
			cout<<q.empty()<<endl;
			cout<<q.front()<<endl;
			q.dequeue();
			q.print();
			
			return 0;
		}
