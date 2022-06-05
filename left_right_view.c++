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
			Node *n8 = new Node(8, NULL, NULL);
			Node *n4 = new Node(4, NULL, NULL);
			Node *n5 = new Node(5, n8, NULL);
			Node *n6 = new Node(6, NULL, NULL);
			Node *n7 = new Node(7, NULL, NULL);
			Node *n2 = new Node(2, n4, n5);
			Node *n3 = new Node(3, n6, n7);
			root = new Node(1, n2, n3);
		}

		void left_view() {
			queue<Node *> q;
			q.push(root);
			while (!q.empty()) {
				int n = q.size();
				for (int i = 0; i < n; i ++) {
					Node *node = q.front();
					q.pop();
					if (i == 0) cout << node -> data << " ";
					if (node -> left) q.push(node -> left);
					if (node -> right) q.push(node -> right);
				}
			}
		}

		void right_view() {
			queue<Node *> q;
			q.push(root);
			while (!q.empty()) {
				int n = q.size();
				for (int i = 1; i <= n; i ++) {
					Node *node = q.front();
					q.pop();
					if (i == n) cout << node -> data << " ";
					if (node -> left) q.push(node -> left);
					if (node -> right) q.push(node -> right);
				}
			}
		}

};


int main() {
	Solution obj;
	obj.left_view();
	cout << endl;
	obj.right_view();

}
