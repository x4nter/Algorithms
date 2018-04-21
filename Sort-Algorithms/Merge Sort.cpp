#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> left, vector<int> right) {
	vector<int> arr;
	while (left.size() != 0 || right.size() != 0) {
		if (left.size() == 0) {
			arr.push_back(right[0]);
			right.erase(right.begin());
		}
		else if (right.size() == 0) {
			arr.push_back(left[0]);
			left.erase(left.begin());
		}
		else if (left[0] < right[0]) {
			arr.push_back(left[0]);
			left.erase(left.begin());
		}
		else {
			arr.push_back(right[0]);
			right.erase(right.begin());
		}
	}
	return arr;
}

vector<int> mergeSort(vector<int> arr) {
	if (arr.size() > 1) {
		int mid = arr.size() / 2;
		vector<int> left(arr.begin(), arr.begin() + mid);
		vector<int> right(arr.begin() + mid, arr.end());
		if (arr.size() > 2) {
			left = mergeSort(left);
			right = mergeSort(right);
		}
		return merge(left, right);
	}
	else return arr;
}

int main() {
	vector<int> unsorted = {10, 39, 84, 57, 4, 46, 98, 65, 21, 72};
	vector<int> sorted = mergeSort(unsorted);
	for (int i = 0; i < sorted.size(); i++)
		cout << sorted[i] << " ";
	cout << endl;
	return 0;
}
