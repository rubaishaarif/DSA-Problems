#include <iostream>
using namespace std;

class Node {
    int data;
    Node *next;
friend class LL;
public:
    Node(int val) {
        data = val;
        next = NULL;
    }
        
};
class LL{
    Node* head;
    Node *tail;
public:
    LL() {
    	head = tail = NULL;
	}
    Node* reverse(Node* headNode) {
        Node* prev = NULL;
        Node* curr = headNode;
        while (curr != NULL) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

void push_back(int val){
        Node *newNode = new Node(val);
        if(head == NULL)
            head = tail = newNode;
        else{
            tail->next = newNode;
            tail = newNode; }  
    }
    bool isPalindrome() {
        if (head==NULL || head->next==NULL)
		 return true;

        Node* slow = head;
        Node* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* secondHalf = reverse(slow);
        Node* firstHalf = head;
        Node* p2 = secondHalf;

        bool result = true;
        while (p2 != nullptr) {
            if (firstHalf->data != p2->data) {
                result = false;
                break;
            }
            firstHalf = firstHalf->next;
            p2 = p2->next;
        }

        reverse(secondHalf);
        return result;
    }
};
int main(){
	LL list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(4);
	list.push_back(1);
	if(list.isPalindrome())
	cout<<"List is palindrome\n";
	else
	cout<<"List is not palindrome\n";
	return 0;
}