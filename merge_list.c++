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
		Node *head, *tail;
	
	public: 
		Solution() {
			head = NULL;
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
				

		void addNodes(vector<int> v) {
			for (int i:v) addNode(i);
		}

		Node *getHead() {
			return head;
		}

		void printList() {
			cout << "List: ";
			Node *temp = head;
			while (temp) {
				cout << temp -> data << " ";
				temp = temp -> next;
			}
			cout << endl;
		}
};

Node *sortList(Node *h1, Node *h2) {
	Node *res;
	if (!h1) return h2;
	else if (!h2) return h1;
	else if (h1 -> data < h2 -> data) {
		res = h1;
		res -> next = sortList(h1 -> next, h2);
	} else {
		res = h2;
		res -> next = sortList(h1, h2 -> next);
	}
	return res;
}


int main() {
	Solution s1, s2;
	s1.addNodes({1, 3, 5, 6, 10});
	s2.addNodes({2, 4, 7, 8, 9});
	s1.printList();
	s2.printList();
	Node *head = sortList(s1.getHead(), s2.getHead());
	while (head) {
		cout << head -> data << " ";
		head = head -> next;
	}
	cout << endl;
}

