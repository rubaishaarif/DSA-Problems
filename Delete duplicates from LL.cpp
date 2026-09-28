#include <iostream>
#include<vector>
using namespace std;
class Node{ //for each element in LL
    public:
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
class LL //to merge all nodes in LL
{
	private:
    Node *head; //keep private
    Node *tail;
    public:
    LL(){
        head = tail = NULL;
    }
    void push_back(int val){
        Node *newNode = new Node(val);
        if(head == NULL)
            head = tail = newNode;
        else{
            tail->next = newNode;
            tail = newNode; }  
    }
    void print(){
    	Node *temp = head;
    	while(temp!=NULL)
    	{
    		cout<<temp->data<<" -> ";
    		temp = temp->next;
		}
		cout<<"NULL";
	}
	void duplicate(LL *FinalL){
		Node *a = head;
		Node *b = a->next;
		while(b!=NULL){
			if(a->data == b->data)
				b = b->next; 
			else //a<b
			{FinalL->push_back(a->data);
			a = b;
			b = b->next;
		}
	}
	FinalL->push_back(a->data);
}
	
};
int main() {
  	LL list, Flist;
  	list.push_back(1);
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(8);
	list.push_back(9);
	list.push_back(9);
	list.duplicate(&Flist);
	Flist.print();
	
    return 0;
}