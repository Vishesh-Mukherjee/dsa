#include <bits/stdc++.h>

using namespace std;

stack<int> s;

void insertAtBottom(int data) {
	if (s.empty()) {
	       s.push(data);
       	       return;
	}	       
	int x = s.top();
	s.pop();
	insertAtBottom(data);
	s.push(x);
}

void fun() {
	if (s.empty()) return;
	int data = s.top();
	s.pop();
	fun();
	insertAtBottom(data);
}

int main() {
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	fun();
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}
