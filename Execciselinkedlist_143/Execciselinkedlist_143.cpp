#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {
private:
	Node* LAST;

public:
	CircularLinkedList {
		LAST = NULL;
	}

	void addNode();
	bool search(int rollno, Node** ARDILLAH, Node** INAYAH);
	bool Listempty();
	bool dellNode();
	void traverse();

};
void CircularLinkedList::addNode() {
	int rn;
	string nm;
	cout << "\nEnter the roll number: ";
	cin >> rn;
	cout << "\nEnter the name: ";
	cin >> nm;
	Node* newNode = new Node();
	newNode->rollNumber = rn;
	newNode->name = nm;

	if (LAST == NULL ||	rn <= LAST->noMhs) {
		if (LAST != NULL && rn == LAST->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = LAST; 
			LAST->prev = newNode;  
		newNode->next = NULL; 
		LAST = newNode;   
		return;
	}

	Node* current = LAST; 
	Node* previous = NULL;  
	while (current->next != NULL && current->next->roolNumber < rn )  
		previous = current;   
		current = current->next;   
 }

bool CircularLinkedList::search(int rollno, Node** previous, Node** current) {
	*previous = LAST->next;
	*current = LAST->next;

	while (*current != LAST) {
		if (rollno == (*current)->rollNumber) {
			return true;
		}
		*previous = *current;
		*current = (*current)->next;
	}

	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularLinkedList::listempty() {
	return LAST == NULL;
}
bool CircularLinkedList::dellNode() {

 }

void CircularLinkedList::traverse() {
	if (Listempty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode -> next;
		} 
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}
int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from teh list " << endl;
			cout << "3. Viw all the records in the list" << endl;
			cout << "4. Exit " << endl;
			cout << "\nEnter your choice (1-5): ";

			char ch;
			cin >> ch;

			switch (ch) {
			case '1': {

			}
			case '2': {

			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option " << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}