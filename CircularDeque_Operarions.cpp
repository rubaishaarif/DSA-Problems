#include<iostream>
using namespace std;
class MyCircularDeque{
	int capacity;
	int *arr;
	int size, front,rear;
	public:
		MyCircularDeque(int k){
			capacity = k;
			front = rear = size = 0;
			arr = new int[capacity];
		}
		~MyCircularDeque(){
			delete[] arr;
			cout<<"Destructor called\n";
		}
		bool isEmpty(){
			return size ==0;
		}
		bool isFull(){
			return size==capacity; }
		bool insertFront(int val){
			if(isFull())
			return false;
			front = (front-1+capacity) % capacity;
			arr[front] = val;
			size++;
			return true; 
		}
		bool insertLast(int val){
			if(isFull())
			return false;
			arr[rear] = val;
			rear = (rear+1) % capacity;
			size++; 
			return true;
		}
		bool deleteFront(){
			if(isEmpty()) 
			return false;
				front = (front+1) % capacity;
				size--;
				return true;
		}
		bool deleteLast(){
			if(isEmpty()) 
			return false;
				rear = (rear-1 + capacity) % capacity;
				size--;
				return true;
		}
		int getFront(){
			if(isEmpty())
			return -1;
			return arr[front];	
		} 
		int getRear(){
			if(isEmpty())
			return -1;
			return arr[rear];	
		} 
		void print(){
			do{
				cout<<getFront()<<" ";
				deleteFront();
			}
			while(!isEmpty());
		}
		
};
int main(){
MyCircularDeque cq(10);
	cq.insertFront(1);
	cq.insertFront(2);
	cq.insertFront(3);
	cq.insertFront(4);
	cq.insertFront(5);
	cq.insertLast(6);
	cq.insertLast(7);
	cq.insertLast(8);
	cq.insertLast(9);
	cq.insertLast(10);
	cq.insertLast(11); //cap==size
	cq.print();
  
return 0;
}