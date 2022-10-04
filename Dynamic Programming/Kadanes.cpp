// C++ program to print largest contiguous array sum
#include <bits/stdc++.h>
using namespace std;
//This is the smallest code for kadanes algorithm
int maxSubArraySum(int A[], int size)
{
 int ans = A[0];
    int sum = A[0];
    for(int i =1 ; i<size;i++){
       sum = max(A[i],sum+A[i]);
       ans = max(ans,sum);
    }
    return ans;
}

// Driver Code
int main()
{
	int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
	int n = sizeof(a) / sizeof(a[0]);

	// Function Call
	int max_sum = maxSubArraySum(a, n);
	cout << "Maximum contiguous sum is " << max_sum;
	return 0;
}
