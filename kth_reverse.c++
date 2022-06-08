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
		Node *head;

	public:
		Solution() {
			head = NULL;
		}

		void addNodeUtil(Node *ptr, Node *node) {
			if (head == NULL) head = node;
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

		void printList() {
			cout << "Linked List: ";
			printListUtil(head);
			cout << endl;
		}

		void kthReverse(int k) {
			Node *cur = head, *prev = NULL, *next, *temp = head;
			while (cur and k) {
				next = cur -> next;
				cur -> next = prev;
				prev = cur;
				cur = next;
				k --;
			}
			head = prev;
			if (next) {
				temp -> next = next;
			}

		}
};

int main() {
	Solution s;
	for (int i = 1; i <= 10; i ++) s.addNode(i);
	s.printList();
	s.kthReverse(100);
	s.printList();
}
