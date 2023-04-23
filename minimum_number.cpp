#include<iostream>
using namespace std;

int minimum1(int n, int arr[]) {
	// Code here
	//int k = 0;
	int flag;
	int max, m2;
	//int j = 0;
	while (1) {
		flag = 0;

		/*tim max, 2ndmax cham
		//tim lon nhat
		for (int i = 0; i < n; i++) {
			if (flag == 0 || arr[max] < arr[i]) {
				max = i;
				flag = 1;
			}
		}
		flag = 0;
		//tim 2nd lon nhat
		for (int i = 0; i < n; i++) {
			if ((flag == 0 || arr[m2] < arr[i]) && arr[i] != arr[max]) {
				m2 = i;
				flag = 1;
			}
		}

		*/

		// tim max, 2ndmax nhanh
		for (int i = 0; i < n; i++) {
			if (flag == 0) {
				max = i;
				m2 = i;
				flag = 1;
			}
			else if (arr[i] > arr[max]) {
				m2 = max;
				max = i;
			}
			else if (arr[i]<arr[max] && arr[i]>arr[m2]) {
				m2 = i;
			}
		}

		//kiem tra m2
		if (flag == 0 || arr[m2] == 0) {
			return arr[max];
		}
		else {
			arr[max] -= arr[m2];
		}
		/*for (int i = 0; i < n; i++) {
			if (arr[i] == 0) {
				j++;
			}
		}
		if (j == n - 1) {
			k = 1;
		}
		flag = 0;*/
	}
	//return arr[max];
}

int minimum2(int n, int arr[]) {
	//tim min
	int min;
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (flag == 0 || arr[min] > arr[i]) {
			min = i;
			flag = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] % arr[min] != 0) {
			return 1;
		}
	}
	return arr[min];
}

int main() {
	int arr[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << minimum2(n, arr);
}