#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	Node *next;
	Node (int data) {
		this -> data = data;
		next = NULL;
	}
};

class Solution {
	private:
		Node *head;
		Node *h1, *h2;

	public: 
		Solution() {
			head = NULL;
			h1 = NULL;
			h2 = NULL;
		}

		void addNodeUtil(Node *ptr, Node *node) {
			if (ptr == NULL) head = node;
			else if (ptr -> next == NULL) ptr -> next = node;
			else addNodeUtil(ptr -> next, node);
		}

		void addNode(int data) {
			Node *node = new Node(data);
			addNodeUtil(head, node);
		}		

		void printListUtil(Node *ptr) {
			if (ptr == NULL) return;
			cout << ptr -> data << " ";
			printListUtil(ptr -> next);
		}

		void printH1() {
			Node *ptr = h1;
			cout << "H1: ";
			while (ptr) {
				cout << ptr -> data << " ";
				ptr = ptr -> next;
			}
			cout << endl;
		}

		void printH2() {
			Node *ptr = h2;
			cout << "H2: ";
			while (ptr) {
				cout << ptr -> data << " ";
				ptr = ptr -> next;
			}
			cout << endl;
		}

		void printList() {
			cout << "Linked list: ";
			printListUtil(head);
			cout << endl;
		}

		void funUtil(Node *h1, Node *h2) {
			if (h1 == NULL || h2 == NULL) return;
			if (h1 -> next != NULL) h1 -> next = h1 -> next -> next;
			if (h2 -> next != NULL) h2 -> next = h2 -> next -> next;
			funUtil(h1 -> next, h2 -> next);
		}

		void fun() {
			h1 = head;
			h2 = head -> next;
			funUtil(h1, h2);
		}

};

int main() {
	Solution s;
	s.addNode(1);
	s.addNode(2);
	s.addNode(3);
	s.addNode(4);
	s.addNode(5);
	s.printList();
	s.fun();
	s.printH1();
	s.printH2();
}
