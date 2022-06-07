#include <bits/stdc++.h>

using namespace std;

void fun(vector<char> v, string prefix, int k) {
	int n = v.size();
	if (k == 0) {
		cout << prefix << endl;
		return;
	}
	for (int i = 0; i < n; i ++) {
		string newPrefix = prefix + v[i];
		fun(v, newPrefix, k-1);
	}
}

int main() {
	vector<char> v = {'a', 'b'};
	int k = 3;
	string prefix = "";
	fun(v, prefix, k);
}
