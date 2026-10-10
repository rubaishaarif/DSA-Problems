#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
class Stack{
    Node *top; //top of LL
     public:
     	LinkedList(){
     		top= NULL;
		 }
     	//insertion
     void push_front( int val){
     Node *newNode = new Node(val); //new node create  
     if(top == NULL) //LL is empty
     top =  newNode ;
     else {
     newNode -> next = top;
     top = newNode;
     }}
	 
 	//deletion
 	void pop_front(){
 		Node *temp = top;
 		top = top->next;
 		temp->next = NULL;
 		delete temp;
	 }
     
     void print(){
     	Node *temp = top;
     	while(temp!=NULL){
     		cout<<temp->data<<" "; 
     		temp = temp->next;
		 } 
	 cout<<endl;
}
	


};

int main() {

Stack LL;
LL.push_front(10);
LL.push_front(20);
LL.push_front(30);
LL.push_front(40);

LL.print();
LL.pop_front();

LL.print();

    return 0;
}