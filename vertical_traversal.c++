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
			Node *n9 = new Node(9, NULL, NULL);
			Node *n8 = new Node(8, NULL, NULL);
			Node *n7 = new Node(7, NULL, n9);
			Node *n6 = new Node(6, NULL, n8);
			Node *n5 = new Node(5, NULL, NULL);
			Node *n4 = new Node(4, NULL, NULL);
			Node *n3 = new Node(3, n6, n7);
			Node *n2 = new Node(2, n4, n5);
			root = new Node(1, n2, n3);
		}

		vector<int> verticalTra() {
			map<int, vector<int>> m;
			queue<pair<int, Node *>> q;
			vector<int> res;
			q.push({0, root});
			while (!q.empty()) {
				int key = q.front().first;
				Node *node = q.front().second;
				q.pop();
				if (m.find(key) == m.end()) {
					vector<int> temp;
					temp.push_back(node -> data);
					m[key] = temp;
				} else {
					m[key].push_back(node -> data);
				}
				if (node -> left) q.push({key-1, node -> left});
				if (node -> right) q.push({key+1, node -> right});
			}
			for (auto it = m.begin(); it != m.end(); it ++) {
				for (int i:it -> second) res.push_back(i);
			}
			return res;
		}
};

int main() {
	Solution obj;
	for (int i: obj.verticalTra()) cout << i << " ";
	cout << endl;
}
