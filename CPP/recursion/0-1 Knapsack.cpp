// solution of 0-1 knapsack using recursion
#include <bits/stdc++.h>
using namespace std;

// this fuction returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, vector<int> &wt, vector<int> &val , int n)
{

	// Base Case
	if (n == 0 || W == 0)
		return 0;

	// If weight of the nth item is more
	// than Knapsack capacity W, then
	// this item cannot be included
	// in the optimal solution
	if (wt[n - 1] > W)
		return knapSack(W, wt, val, n - 1);

	// Return the maximum of two cases:
	// (1) nth item included
	// (2) not included
	else
		return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),knapSack(W, wt, val, n - 1));
}

// Driver code
int main()
{
	int n , W;
	cout<<"Enter the number of items"; 
	cin>>n;	// taking input n
	vector<int> val(n) , wt(n);
	for(int i = 0 ; i < n ; i++)
	   cin>>wt[i];
	for(int i = 0 ; i < n ; i++)
	   cin>>val[i];
	cout<<"Enter the capacity of knapsack";
	cin>>W;	//W of knapsack
	cout << knapSack(W, wt, val, n);
	return 0;
}
