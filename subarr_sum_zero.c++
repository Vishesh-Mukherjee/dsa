#include <bits/stdc++.h>

using namespace std;

int maxLen(vector<int>arr, int n)
{   
	unordered_map<int, int> m;
	m[0] = -1;
	int sum = 0, res = 0;
	for (int i = 0; i < n; i ++) {
		sum += arr[i];
		if (m.find(sum) == m.end()) 
			m[sum] = i;
		else res = max(res, i-m[sum]);
	}
	return res;
}

int main() {
	vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
	cout << maxLen(arr, arr.size()) << endl;
}
