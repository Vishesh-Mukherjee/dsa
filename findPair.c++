#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> solOne(vector<int> a, vector<int> b, int x) {
	unordered_set<int> s;
	vector<pair<int, int>> res;
	sort(a.begin(), a.end());
	for (int i:b) s.insert(i);
	for (int i:a) if (s.find(x-i) != s.end()) res.push_back({i, x-i});
	return res;
}

vector<pair<int, int>> solTwo(vector<int> a, vector<int> b, int x) {
	vector<pair<int, int>> res;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());
	int i = 0, j = 0, n = a.size(), m = b.size();
	while (i < n and j < m) {
		if (x > a[i]+b[j]) i ++;
		else if (x < a[i]+b[j]) j ++;
		else {
			res.push_back({a[i], b[j]});
			i ++;
			j ++;
		}
	}
	return res;
}

int main() {
	vector<int> a = {1, 2, 4, 5, 7};
	vector<int> b = {5, 6, 3, 4, 8};
	for (pair<int, int> i:solOne(a, b, 9)) cout << i.first << " : " << i.second << endl;
	cout << endl;
	for (pair<int, int> i:solTwo(a, b, 9)) cout << i.first << " : " << i.second << endl;
}
