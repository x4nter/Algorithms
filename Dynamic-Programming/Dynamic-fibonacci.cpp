//This is a dynamic bottom-up approach for calculating fibonacci sequence.
//The main idea is to store the solutions for future access so that they don't have to be calculated again.
//This is more efficient than calculating every single time.

#include <iostream>
#include <vector>

using namespace std;

vector<int> sols;//stores all the numbers for future access

int fib(int n) {
	//Find next number in the sequence from previously stored numbers
	//If not already stored, calculate it from the two previously stored numbers
	if (sols[n] == NULL) {
		for (int i = 2; i <= n; i++) {
			sols[i] = fib(i - 1) + fib(i - 2);
		}
	}
	return sols[n];
}

int main() {
	int n;
	cin >> n;
	sols.resize(n);
	//Two base cases to begin with
	sols[0] = 0;
	sols[1] = 1;
	fib(n - 1);
	cout << endl;
	for (int i = 0; i < sols.size(); i++)
		cout << sols[i] << endl;
	return 0;
}
