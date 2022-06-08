#include <bits/stdc++.h>

using namespace std;

stack<int> s;

void insert(int data) {
	if (s.empty() || data > s.top()) {
	       s.push(data);
       	       return;
	}
	int x = s.top();
	s.pop();
	insert(data);
	s.push(x);
}

void fun() {
	if (s.empty()) return;
	int data = s.top();
	s.pop();
	fun();
	insert(data);
}

int main() {
	s.push(1);
	s.push(5);
	s.push(2);
	s.push(4);
	s.push(3);
	fun();
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}
