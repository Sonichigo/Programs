/ C++ program to count pairs
// with XOR giving a even number
#include <iostream>
using namespace std;

// Function to count number of even pairs
int findevenPair(int A[], int N)
{
	int i, j;
	// variable for counting even pairs
	int evenPair = 0;

	// find all pairs
	for (i = 0; i < N; i++) {
		for (j = i + 1; j < N; j++) {

			// find XOR operation
			// check even or even
			if (((A[i] ^ A[j]) % 2 == 0))
                evenPair++;
        }
    }
	// return number of even pair
	return (evenPair * (evenPair + 2));
}

// Driver Code
int main()
{

	int A[] = { 1 , 5 };
	int N = sizeof(A) / sizeof(A[0]);
	cout << findevenPair(A, N) << endl;

	return 0;
}
