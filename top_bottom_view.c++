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

		void topview() {
			map<int, int> m;
			queue<pair<int, Node*>> q;
			q.push({0, root});
			while (!q.empty()) {
				int key = q.front().first;
				Node *node = q.front().second;
				q.pop();
				if (m.find(key) == m.end()) m[key] = node -> data;
				if (node -> left) q.push({key-1, node -> left});
				if (node -> right) q.push({key+1, node -> right});
			}
			for (auto it = m.begin(); it != m.end(); it ++) cout << it -> second << " ";
			cout << endl;
		}

		void bottomview() {
			map<int, int> m;
			queue<pair<int, Node*>> q;
			q.push({0, root});
			while (!q.empty()) {
				int key = q.front().first;
				Node *node = q.front().second;
				q.pop();
				m[key] = node -> data;
				if (node -> left) q.push({key-1, node -> left});
				if (node -> right) q.push({key+1, node -> right});
			}
			for (auto it = m.begin(); it != m.end(); it ++) cout << it -> second << " ";
			cout << endl;
		}

};

int main() {
	Solution obj;
	obj.topview();
	obj.bottomview();
}
