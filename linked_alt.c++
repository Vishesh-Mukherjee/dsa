#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	Node *next;
	Node(int data) {
		this -> data = data;
		next = NULL;
	}
};

class Solution {
	private:
		Node *head, *tail;

	public:
		Solution() {
			this -> head = NULL;
		}

		void addNode(int data) {
			Node *node = new Node(data);
			if (head == NULL) {
				head = node;
				tail = node;
			} else {
				tail -> next = node;
				tail = node;
			}
		}

		void printAltUtil(Node *head, int state) {
			if (head == NULL) return;
			if (state) cout << head -> data << " ";
			printAltUtil(head -> next, !state);
		}

		void printAlt() {
			printAltUtil(head, 1);
		}
};

int main() {
	Solution s;
	s.addNode(1);
	s.addNode(5);
	s.addNode(2);
	s.addNode(4);
	s.addNode(3);
	s.addNode(6);
	s.addNode(0);
	s.printAlt();
}
