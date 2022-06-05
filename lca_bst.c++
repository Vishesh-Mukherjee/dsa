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
			Node *n3 = new Node(3, NULL, NULL);
			Node *n9 = new Node (9, NULL, NULL);
			Node *n15 = new Node(15, NULL, NULL);
			Node *n21 = new Node(21, NULL, NULL);
			Node *n6 = new Node(6, n3, n9);
			Node *n18 = new Node(18, n15, n21);
			root = new Node(12, n6, n18);
		}

		Node *lowest_common_ancestor(int n1, int n2) {
			int minEle = min(n1, n2);
			int maxEle = max(n1, n2);
			Node *temp = root;
			while (temp) {
				int d = temp -> data;
				if (minEle < d and maxEle < d) temp = temp -> left;
				else if (minEle > d and maxEle > d) temp = temp -> right;
				else break;
			}
			return temp;
		}

};


int main() {
	Solution obj;
	cout << obj.lowest_common_ancestor(9, 15) -> data << endl;
	cout << obj.lowest_common_ancestor(3, 6) -> data << endl;
	cout << obj.lowest_common_ancestor(6, 12) -> data << endl;
}
