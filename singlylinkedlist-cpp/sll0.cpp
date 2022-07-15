// Copyright (C) 2022 bunnicash "@bunnicash" and licensed under GPL-2.0
#include <iostream>

struct Node {               // Node struct containing a data int and a pointer to another node
	int data;               // something of type integer 
	Node *next;             // pointer to next node
};

class LinkedList {                    // Head pointer (singly linked: forward, doubly linked: forwards, backwards)
    Node* head;                       // the end of the list would be the "tail"

	public:                           // ACCESS: by default, class objects are private
		LinkedList() {                // Default constructor
			head = NULL;              // Initializing head pointer
		}

		void insert(int val) {                    // FUNC: inserting elements (At start of the list)
			Node* new_node = new Node;            // make a new node
			new_node->data = val;
			new_node->next = NULL;

			if (head == NULL) {                   // If list is empty, make the new node the head (first)
				head = new_node;
			} else {                              // else, make the new_node the head and the previous head is the next in the list
				new_node->next = head;
				head = new_node;
			}
		}

		bool search(int val) {                    // FUNC: loop over the list, return true if element found
			Node* temp = head;
			while(temp != NULL) {
				if (temp->data == val) {
					return true;                  // skips lines 35-39 (incl. return false)
                }
				temp = temp->next;
			}
			return false;
		}

		void remove(int val) {                    // FUNC: Remove node
			if (head->data == val) {              // If the head is to be deleted
				delete head;
				head = head->next;                // Let the next item be the first (head)
				return;	
			}

			if (head->next == NULL) {             // If there is only one element in the list
				if (head->data == val) {          // If the head is to be deleted: Assign null to the head
					delete head;
					head = NULL;
					return;                       // skips lines 54-55
				}
				std::cout << "Value not found!" << std::endl;
				return;
			}

			Node* temp = head;
			while(temp->next!= NULL) {                     // Else loop over the list and search for the node to delete
				if (temp->next->data == val) {             // When node is found, delete the node and modify the pointers
					Node* temp_ptr = temp->next->next;
					delete temp->next;
					temp->next = temp_ptr;
					return;
				}
				temp = temp->next;                         // Move on to the next node 
			}

			std::cout << "Value not found" << std::endl;   // Else, the value was never in the list
		}

		void display() {                                   // FUNC: Show all node data for list 
			Node* temp = head;
			while(temp != NULL) {
				std::cout << temp->data << " ";
				temp = temp->next;
			}
			std::cout << std::endl;
		}
};

int main() {
	LinkedList l;

	std::cout << std::endl;

	std::cout << "Inserting nodes/elements: " << std::endl;
	l.insert(6);
	l.insert(9);
	l.insert(1);
	l.insert(3);
	l.insert(7);
	std::cout << "Current Linked List: ";
	l.display();

	std::cout << "Delete Request ( 1): ";
	l.remove(1);
	l.display();

	std::cout << "Delete Request (13): ";
	l.remove(13);

	std::cout << "Search Request ( 7): ";
	std::cout << l.search(7) << std::endl;

	std::cout << "Search Request (13): ";
	std::cout << l.search(13) << std::endl;

	std::cout << std::endl;
	return 0;
}
