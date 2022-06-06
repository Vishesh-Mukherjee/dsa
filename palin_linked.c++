#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	Node *next;
	Node (int data, Node *next) {
		this -> data = data;
		this -> next = next;
	}
};

class Solution {
	private:
		Node *head, *tail;
	
	public:
		Solution() {
			head = NULL;	
			tail = NULL;
		}

		void print_linked() {
			Node *temp = head;
			cout << "Linked list: ";
			while (temp) {
				cout << temp -> data << " ";
				temp = temp -> next;
			}
			cout << endl;
		}	

		bool isPalindromeStack() {
			stack<int> s;
			Node  *temp = head;
			while(temp) {
				s.push(temp -> data);
				temp = temp -> next;
			}
			temp = head;
			while (!s.empty()) {
				if (temp -> data != s.top()) return false;
				temp = temp -> next;
				s.pop();
			}
			return true;
		}

		bool isPalindromeRecursion(Node **left, Node *right) {
			if (right == NULL) return true;
			bool isp = isPalindromeRecursion(left, right -> next);
			if (isp == false) return false;
			bool isp2 = (right -> data == (*left) -> data);
			*left = (*left) -> next;
			return isp2;
		}

		Node *getHead() {
			return head;
		}

		void addNode(int data) {
			Node *node = new Node(data, NULL);
			if (head == NULL) {
				head = node;
				tail = node;
			} else {
				tail -> next = node;
				tail = node;
			}
		}
};

int main() {
	Solution o1;
	o1.addNode(1);
	o1.addNode(2);
	o1.addNode(3);
	o1.addNode(4);

	o1.print_linked();
	cout << o1.isPalindromeStack() << endl;
	Node *temp = o1.getHead();
	cout << o1.isPalindromeRecursion(&temp, temp) << endl;
	
	Solution o2;
	o2.addNode(1);
	o2.addNode(2);
	o2.addNode(2);
	o2.addNode(1);

	o2.print_linked();
	cout << o2.isPalindromeStack() << endl;
	temp = o2.getHead();
	cout << o2.isPalindromeRecursion(&temp, temp) << endl;
}
