#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	Node *left, *right;
	Node(int data, Node *left, Node *right) {
		this -> data = data;
		this -> left = left;
		this -> right = right;
	}
};

class Solution {
	private:
		Node *root;

	public:
		Solution() {
			Node *n4 = new Node(4, NULL, NULL);
			Node *n5 = new Node(5, NULL, NULL);
			Node *n6 = new Node(6, NULL, NULL);
			Node *n7 = new Node(7, NULL, NULL);
			Node *n2 = new Node(2, n4, n5);
			Node *n3 = new Node(3, n6, n7);
			root = new Node(1, n2, n3);
		}

		Node *getRoot() {
			return root;
		}

		void inOrder(Node *root) {
			if (root == NULL) return;
			if (root -> left) inOrder(root -> left);
			cout << root -> data << endl;
			if (root -> right) inOrder(root -> right);
		}

		void preOrder(Node *root) {
			if (root == NULL) return;
			cout << root -> data << endl;
			if (root -> left) preOrder(root -> left);
			if (root -> right) preOrder(root -> right);
		}

		void postOrder(Node *root) {
			if (root == NULL) return;
			if (root -> left) postOrder(root -> left);
			if (root -> right) postOrder(root -> right);
			cout << root -> data << endl;
		}
};


int main() {
	Solution obj;
	obj.inOrder(obj.getRoot());
	cout << endl;
	obj.preOrder(obj.getRoot());
	cout << endl;
	obj.postOrder(obj.getRoot());
	cout << endl;
}
