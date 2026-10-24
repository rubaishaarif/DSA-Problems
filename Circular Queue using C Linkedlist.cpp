#include<iostream>
using namespace std;
class Node{
		public:
	int data;
	Node *next;
	Node(int val){
		data = val;
		next = NULL;}
};
class CQueue{
	Node *tail;
	public:
	CQueue(){ tail = NULL;}
	void Enqueue(int val){
		Node *newNode = new Node(val);
		if(tail==NULL){
			tail = newNode;
            tail->next = tail;	}
        else
		{	
			newNode->next = tail->next;
			tail->next = newNode;
			tail = newNode; 
		}
	}
	void Dequeue() {
        if (tail == NULL) {
		cout<<"Queue is empty\n";
		return;
		}  
		Node* head = tail->next;
        if (tail == head) { // Single element case
            delete head;
            tail = NULL;
        } else {
            tail->next = head->next; // Bypass head node
            delete head;
        }
    }
    void print() {
        if (tail == NULL) {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = tail->next; // Start from head
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "NULL\n";
    }

    ~CQueue() {
        while (tail != NULL) {
            Dequeue();
        }
        cout<<"Destructor called\n";
    }
};
int main(){
	CQueue cq;
	cq.Enqueue(1);
	cq.Enqueue(3);
	cq.Enqueue(4);
	cq.Enqueue(5);
	cq.Dequeue();
	cq.print();
	return 0;
}
              