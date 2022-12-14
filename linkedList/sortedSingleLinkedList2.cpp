////
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
    
};

void push(Node** head_ref, int new_data){
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void deleteNode(Node** head_ref, int key){

	Node* temp = *head_ref;
	Node* prev = NULL;
	if (temp != NULL && temp->data == key) {

		*head_ref = temp->next;
		delete temp;
		return;
	}
	else {
		while (temp != NULL && temp->data != key) {
			prev = temp;
			temp = temp->next;
		}
		if (temp == NULL)
			return;

		prev->next = temp->next;
		delete temp;
	}
}
void deletePositionNode(Node** head_ref, int position){

    if (*head_ref == NULL)
        return;
    Node* temp = *head_ref;

    if (position == 0) {
        *head_ref = temp->next;

        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
    return;

    Node* next = temp->next->next;
    free(temp->next); 
    temp->next = next;
}

void sortedInsert(Node* new_node){
    Node* sorted;
	if (sorted == NULL || sorted->data >= new_node->data) {
		new_node->next = sorted;
		sorted = new_node;
	}
	else {
		Node* current = sorted;

		while (current->next != NULL
			&& current->next->data < new_node->data) {
			current = current->next;
			}
			new_node->next = current->next;
			current->next = new_node;
		}
	}
void insertionSort(Node* head_ref){
    Node* sorted;
	sorted = NULL;
	Node* current = head_ref;

	while (current != NULL) {
			
		Node* next = current->next;
		sortedInsert(current);
		current = next;
	}
		
		head_ref = sorted;
	}
bool search(Node* head, int x){
    Node* current = head; 
    while (current != NULL) {
        if (current->data == x)
            return true;
    current = current->next;
    }
    return false;
}

void printList(Node* node){
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}

///////

int main()
{

	Node* head = NULL;
	push(&head, 7);
	push(&head, 15);
	push(&head, 3);
	push(&head, 2);
    push(&head, 6);
    push(&head, 9);
    push(&head, 1);

	puts("Created Linked List: ");
	printList(head);

	insertionSort(head);
	puts("\nsorted Linked List: ");
	printList(head);

    deletePositionNode(&head, 5);
    puts("\nLinked List after Deletion at position 5: ");
    printList(head);

	//deleteNode(&head, 6);
	//puts("\nLinked List after Deletion of 6: ");
    //printList(head);

    search(head, 6) ? cout << "\nSearched result: Yes\n" : cout << "\nSearched result: No\n";
    
	return 0;
}

