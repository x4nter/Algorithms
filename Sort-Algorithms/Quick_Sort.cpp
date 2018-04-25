#include <iostream>
#include <vector>

using namespace std;

vector<int> quickSort(vector<int> arr) {
	int pivot = arr.back();
	int pe = arr.size() - 1;
	for (int i = 0; i < pe; i++) {
		if (arr[i] > pivot) {
			arr.push_back(arr[i]);
			arr.erase(arr.begin() + i);
			i--;
			pe--;
		}
	}
	vector<int> left(arr.begin(), arr.begin() + pe);
	vector<int> right(arr.begin() + pe, arr.end());
	if(left.size() > 1)
		left = quickSort(left);
	if(right.size() > 1)
		right = quickSort(right);
	left.insert(left.end(), right.begin(), right.end());
	return left;
}

int main() {
	vector<int> unsorted = {10, 39, 84, 57, 4, 46, 98, 65, 21, 72};
	vector<int> sorted = quickSort(unsorted);
	for (int i = 0; i < sorted.size(); i++)
		cout << sorted[i] << " ";
	cout << endl;
	return 0;
}
