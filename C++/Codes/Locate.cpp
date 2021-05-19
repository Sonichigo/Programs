#include <bits/stdc++.h>
using namespace std;
int countSquares(int arr[], int N)
{
	int count = 0;
	unordered_map<int, int> m;
	for (int i = 0; i < N; i++) {
		m[arr[i]] = m[arr[i]] + 1;
	}

	for (int i = 0; i < N; i++) {
		int square = arr[i] * arr[i];
		count += m[square];
	}
	cout << count;
}
int main()
{
	int arr[5];
	for(int i=0;i<5;i++){
		cin>>a[i];
	}
	int N = sizeof(arr) / sizeof(arr[0]);
	countSquares(arr, N);
	cout<<endl;
	return 0;
}
