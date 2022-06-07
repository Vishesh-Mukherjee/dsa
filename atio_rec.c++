#include <bits/stdc++.h>

using namespace std;

int convert(string s, int x) {
	if (x == 0) return s[x] - '0';
	return 10*convert(s, x-1) + (s[x]-'0');
}

int main() {
	string s1 = "1234", s2 = "15243";
	cout << convert(s1, s1.size()-1) << endl;
	cout << convert(s2, s2.size()-1) << endl;
}
