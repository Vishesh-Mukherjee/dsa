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
		
		void levelorder() {
			queue<Node *> q;
			q.push(root);
			while (!q.empty()) {
				Node *temp = q.front();
				q.pop();
				cout << temp -> data << endl;
				if (temp -> left) q.push(temp -> left);
				if (temp -> right) q.push(temp -> right);
			}

		}

};


int main() {
	Solution obj;
	obj.levelorder();

}
