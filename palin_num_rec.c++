#include <bits/stdc++.h>

using namespace std;

bool isOneDigit(int n) {
	return (n >= 0 and n < 9);
}

bool isPalinUtil(int num, int *temp) {
	if (isOneDigit(num)) return (num == (*temp)%10);
	if (!isPalinUtil(num/10, temp)) return false;
	*temp /= 10;
	return (num%10 == (*temp)%10);
}
	

bool isPalin(int num) {
	int *temp = new int(num);
	return isPalinUtil(num, temp);
}

int main() {
	cout << isPalin(1234) << endl;
	cout << isPalin(1221) << endl;
	cout << isPalin(12321) << endl;
}
