#include<iostream>
#include<cstring>
using namespace std;
class Stack{
	char *ch;
	int size,top;
	public:
		Stack(int s){
			size = s;
			ch = new char[s];
			top=-1;
		}
		bool isEmpty(){
		return top==-1; }
		bool isFull(){
			return top == size-1;
		}
	void push(char val){
		if(isFull())
			cout<<"Stack is full\n";
		else
		ch[++top] = val;
	}
	char pop(){
		if(isEmpty()){
			cout<<"Cant pop, stack is empty\n";
			return -1;
		}
		return ch[top--];
	}	
	void print(){
		for(int i=0;i<size;i++)
		cout<<ch[i];
		cout<<endl;
	}
	~Stack(){
		delete[] ch;
		cout<<"\nDestructor called\n";
	}
	bool checkPalindrome(string &s){
		int l = s.length();
		for(int i=0;i<l;i++){ //push in stack
			push(s[i]);
		}
		for(int i=0;i<l;i++){
			if(tolower(s[i]) != tolower(pop()))
			{
				return false;
				break;
			}
		}
			return true;
		}
	
};
int main(){
	string s = "ab211c2ba";
	int size = s.length();
	Stack stack(size);
//	stack.print();
	if(stack.checkPalindrome(s))
	cout<<"Palindrome\n";
	else
	cout<<"Not a palindrome\n";
	return 0;
}