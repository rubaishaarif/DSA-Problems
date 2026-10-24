#include <iostream>
#include <string>

using namespace std;

// Node structure for Doubly Linked List
class Node {
	public:
    string url;
    Node* prev;
    Node* next;

    Node(string val) {
    	url = val;
		next = prev = NULL;	
	}
};

class BrowserHistory {
    Node* current;
public:

    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }

    void visit(string url) {
       
        Node *temp = current->next;
        while(temp !=NULL)
        {
        	Node *nextNode = temp->next;
        	delete temp;
        	temp = nextNode;
		}
		 Node* newPage = new Node(url);
        current->next = newPage;
        newPage->prev = current;
        current = newPage;

    }

    string back(int steps) {
        while (steps > 0 && current->prev != nullptr) {
            current = current->prev;
            steps--;
        }
        return current->url;
    }

    string forward(int steps) {
        while (steps > 0 && current->next != nullptr) {
            current = current->next;
            steps--;
        }
        return current->url;
    }
};
int main(){
	BrowserHistory b("facebook.com");
	cout<<"facebook.com\n";
	b.visit("youtube.com");
	cout<<"youtube.com\n";
	b.visit("leetcode.com");
	cout<<"leetcode.com\n";
	b.back(2); //facebook
	b.forward(1); //youtube
	
	
	return 0;
}