// This is also the solution for leetcode combination sum 2 Link - https://leetcode.com/problems/combination-sum-ii/
// Sum of subsets using Backtracking
#include <bits/stdc++.h>

using namespace std;

void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if (ind == arr.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }

    if (arr[ind] <= target)
    {
        ds.push_back(arr[ind]);
        findCombination(ind + 1, target - arr[ind], arr, ans, ds);
        ds.pop_back();
    }
    findCombination(ind + 1, target, arr, ans, ds);
}

void print(vector<vector<int>> &ans, int target)
{
    cout << "The Subsets with Sum = " << target << " are : \n";
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << "\t";
        }
        cout << "\n";
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    int ind;
    vector<vector<int>> ans;
    vector<int> ds;

    findCombination(ind, target, candidates, ans, ds);

    print(ans, target);

    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> candidates;
    // {5, 10, 12, 13, 15, 18}
    int n;
    int target;
    cout << "Enter the number of candidates: ";
    cin >> n;
    cout<<"Enter the target: ";
    cin >> target;
    cout << "Enter the candidates: ";
    for(int i=0;i<n;i++)
    {
        int candidate;
        cin >> candidate;
        candidates.push_back(candidate);
    }
    combinationSum(candidates, target);


    return 0;
}

// Time Complexity :
//  O((2^n)*k*logn)

// Space Complexity :
// Hypothetical // Depends on the subset output
// Generally k*n