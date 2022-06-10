#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > fourSum(vector<int> &arr, int k) {
		int n = arr.size();
		sort(arr.begin(), arr.end());
		vector<vector<int>> res;
		for (int i = 0; i < n-3; i ++) {
			if (i > 0 and arr[i] == arr[i-1]) continue;
			for (int j = i+1; j < n-2; j ++) {
				if (j > i+1 and arr[j] == arr[j-1]) continue;
				int l = j+1, r = n-1;
				while (l < r) {
					if (arr[l] + arr[r] < k-arr[i]-arr[j]) l ++;
					else if (arr[l] + arr[r] > k-arr[i] -arr[j]) r --;
					else {
						res.push_back({arr[i], arr[j], arr[l], arr[r]});
						while (l < r and arr[l] == arr[l+1]) l ++;
						while (l < r  and arr[r] == arr[r-1]) r --;
						l ++;
						r --;
					}
				}
			}
		}
		return res;
}

int main() {
	vector<int> arr = {-3, -3, -1, 0, 1, 2, -1};
	int k = 2;
	for (vector<int> v:fourSum(arr, k)) {
		for (int i:v) {
			cout << i << " ";
		}
		cout << endl;
	}
}

