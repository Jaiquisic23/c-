////
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	struct Node* next;
	Node(int x)
	{
		val = x;
		next = NULL;
	}
};

class Linkedlist {

public:
	Node* head;
	Node* sorted;

	void push(int new_val)
	{
		Node* newnode = new Node(new_val);
		newnode->val= new_val;
		newnode->next = head;
		head = newnode;
	}

	void insertionSort(Node* headref)
	{

		sorted = NULL;
		Node* current = headref;

		while (current != NULL) {
			
			Node* next = current->next;
			sortedInsert(current);
			current = next;
		}
		
		head = sorted;
	}

	void sortedInsert(Node* newnode)
	{
		if (sorted == NULL || sorted->val >= newnode->val) {
			newnode->next = sorted;
			sorted = newnode;
		}
		else {
			Node* current = sorted;

			while (current->next != NULL
				&& current->next->val < newnode->val) {
				current = current->next;
			}
			newnode->next = current->next;
			current->next = newnode;
		}
	}
	void deleteNode(Node** head, int key){

	Node* temp = *head;
	Node* prev = NULL;

	if (temp != NULL && temp->val == key) {
		*head = temp->next;
		delete temp;
		return;
	}
	else {
		while (temp != NULL && temp->val != key) {
			prev = temp;
			temp = temp->next;
		}
		if (temp == NULL)
			return;

		prev->next = temp->next;
		delete temp;
	}
}

	void printlist(Node* head)
	{
		while (head != NULL) {
			cout << head->val << " ";
			head = head->next;
		}
	}
};

//////
int main()
{

	Linkedlist list;
    list.head = NULL;
    list.push(1);
    list.push(5);
    list.push(4);
    list.push(3);
    list.push(2);

	deleteNode(list.head, 1);
	puts("\nLinked List after Deletion of 1: ");

	cout << "original Linked List" << endl;
	list.printlist(list.head);
	cout << endl;
	list.insertionSort(list.head);
	cout << "sort Linked List" << endl;
	list.printlist(list.head);
}

