#include<bits/stdc++.h>
using namespace std;


/* Recursive approach - TLE */
int maxLengthRecur(vector<int>& nums, int ind, int prevInd) {
	if (ind == nums.size()) return 0;
	int notPick =  maxLengthRecur(nums, ind + 1, prevInd);
	int pick = 0 ;
	if (prevInd == -1 or nums[ind] > nums[prevInd])  pick = 1 + maxLengthRecur(nums, ind + 1, ind);
	return max(notPick, pick);
}

/* Memoization approach */
int maxLengthMemo(vector<int>& nums, int ind, int prevInd, vector<vector<int>>&dp) {
	if (ind == nums.size()) return 0;
	/*since prev ==-1 for a time and we know that we can't represent the negative values in the array
	so for that we have to  shift it one index towards 0 so that -1 is treated as 0 and vice versa...*/

	if (dp[ind][prevInd + 1] != -1) return dp[ind][prevInd + 1];

	//picking and not picking way -
	int notPick = maxLengthMemo(nums, ind + 1, prevInd, dp);
	int pick = 0 ;
	if (prevInd == -1 or nums[ind] > nums[prevInd])  pick = 1 + maxLengthMemo(nums, ind + 1, ind, dp);
	return dp[ind][prevInd + 1] = max(notPick, pick);
}

/*tabulation approach */
int maxLengthTabul(vector<int> &nums) {
	int n = nums.size();
	vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));

	for (int ind = n - 1; ind >= 0; ind--) {
		/*since the prevInd is the previous value of current index so start it from ind - 1 and go till -1 */
		for (int prevInd = ind - 1; prevInd >= -1; prevInd--) {
			int notPick = dp[ind + 1][prevInd + 1];//shift all previous states by 1
			int pick = 0;
			if (prevInd == -1 or nums[ind] > nums[prevInd]) pick = 1 + dp[ind + 1][ind + 1];//shift all previous states by 1
			dp[ind][prevInd + 1] = max(notPick, pick);
		}
	}
	return dp[0][0];
}


/*space optimization approach */
int maxLengthSpaceOpt(vector<int> &nums) {
	int n = nums.size();
	vector<int> prevRow(n + 1, 0), currRow(n + 1, 0);

	for (int ind = n - 1; ind >= 0; ind--) {
		for (int prevInd = ind - 1; prevInd >= -1; prevInd--) {
			int notPick = prevRow[prevInd + 1];//shift all previous states by 1
			int pick = 0;
			if (prevInd == -1 or nums[ind] > nums[prevInd]) pick = 1 + prevRow[ind + 1];//shift all previous states by 1
			currRow[prevInd + 1] = max(notPick, pick);
		}
		prevRow = currRow;
	}
	return prevRow[0];
}



int lengthOfLIS(vector<int>& nums) {
	int n = nums.size();
	/*	here - 1 is the previous indexed value which is used to
		check whether the subsequence we are generating is increasing or decreasing*/

	//for recursion
	// int res = maxLengthRecur(nums, 0, -1);


	//for memoization
	// vector<vector<int>> dp(n, vector<int> (n + 1, -1));
	// int res = maxLengthMemo(nums, 0, -1, dp);

	//for tabulation
	// int res = maxLengthTabul(nums);

	// for space optimisation
	int res = maxLengthSpaceOpt(nums);


	return res;
}


int main() {
	int n;
	cin >> n;
	vector<int>seq(n);
	for (int &i : seq) cin >> i;
	cout << lengthOfLIS(seq);
	return 0;

}
