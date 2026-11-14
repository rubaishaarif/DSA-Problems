#include<iostream>
#include<string>
using namespace std;
class Stack{
	char *c;
	int size;
	int top;
	public:
		Stack(int s){
			size = s;
			c = new char[s];
			top = -1;
		}
		bool isEmpty(){
		return top==-1; }
		bool isFull(){
			return top == size-1;
		}
	void push(char s){
		if(isFull())
		cout<<"Stack is full\n";
		else
		c[++top] = s;	 
	}
	char pop(){
		if(isEmpty()){
		cout<<"Stack is empty\n"; 
		return -1; }
		else
		return c[top--];
	}
	string check(string &st){
		for(int i=0;i<st.length();i++){
			if(st[i] != '#')
			push(st[i]);
			else
			pop();
		}
		string temp = "";
		while(!isEmpty()){
			temp += pop(); 
		}
		return temp;
	}
	bool Compare(string &s, string &t){
		return check(s)==check(t);
	}
	~Stack(){
		delete[] c;
		cout<<"\nDestructor called\n";
	}
};
int main(){
	string s= "ab#c";
	string t = "ad#c";
	Stack st1(5);
	cout<<st1.Compare(s,t);
	string a = "a#c";
	string b = "b";
	Stack st2(5);
	cout<<st2.Compare(a,b);
	return 0;
}
	
	
	
	
	
	
	
	
		