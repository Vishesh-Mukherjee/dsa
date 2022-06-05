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
		
		vector<int> spiralorder() {
			vector<int> res;
			if (root == NULL) return res;
			stack<Node *> s1, s2;
			s1.push(root);
			while (!s1.empty() || !s2.empty()) {
				while (!s1.empty()) {
					Node *temp = s1.top();
					res.push_back(temp -> data);
					s1.pop();
					if (temp -> left) s2.push(temp -> left);
					if (temp -> right) s2.push(temp -> right);
				}
				while (!s2.empty()) {
					Node *temp = s2.top();
					res.push_back(temp -> data);
					s2.pop();
					if (temp -> right) s1.push(temp -> right);
					if (temp -> left) s1.push(temp -> left);
				}
			}
			return res;
		}

};


int main() {
	Solution obj;
	for (int i:obj.spiralorder())cout << i << " ";
	cout << endl;

}
