#include <bits/stdc++.h>
using namespace std;

void buildTree(vector<int> &nums, vector<int> &tree, int si, int ei, int idx)
{
    if (si == ei)
    {
        tree[idx] = nums[si];
        return;
    }

    int mid = si + ((ei - si) / 2);

    buildTree(nums, tree, si, mid, (2 * idx) + 1);
    buildTree(nums, tree, mid + 1, ei, (2 * idx) + 2);
    tree[idx] = tree[(2 * idx) + 1] + tree[(2 * idx) + 2];
}

void buildTree(vector<int> &nums, vector<int> &tree)
{
    int n = nums.size();
    buildTree(nums, tree, 0, n - 1, 0);
}

int getSum(vector<int> &tree, int L, int R, int si, int ei, int idx)
{
    if (ei < L || si > R)
    {
        return 0;
    }

    if (L <= si && R >= ei)
    {
        return tree[idx];
    }

    int mid = si + ((ei - si) / 2);

    return getSum(tree, L, R, si, mid, (2 * idx) + 1) + getSum(tree, L, R, mid + 1, ei, (2 * idx) + 2);
}

int getSum(vector<int> &nums, vector<int> &tree, int L, int R)
{
    return getSum(tree, L, R, 0, nums.size() - 1, 0);
}

void update(vector<int> &tree, int si, int ei, int idx, int index, int val)
{
    if (si > index || ei < index)
    {
        return;
    }
    tree[idx] += val;
    if (si < ei)
    {
        int mid = si + ((ei - si) / 2);
        update(tree, si, mid, (2 * idx) + 1, index, val);
        update(tree, mid + 1, ei, (2 * idx) + 2, index, val);
    }
}

void update(vector<int> &nums, vector<int> &tree, int index, int val)
{
    update(tree, 0, tree.size() - 1, 0, index, val - nums[index]);
    nums[index] = val;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> tree(4 * n);
    buildTree(nums, tree);
    cout << getSum(nums, tree, 0, 1) << endl;
    cout << getSum(nums, tree, 0, 0) << endl;
    cout << getSum(nums, tree, 0, 2) << endl;
    cout << getSum(nums, tree, 0, 3) << endl;
    cout << getSum(nums, tree, 1, 3) << endl;
    cout << getSum(nums, tree, 2, 3) << endl;
    cout << getSum(nums, tree, 3, 3) << endl;
    cout << getSum(nums, tree, 1, 2) << endl;
    cout << getSum(nums, tree, 2, 2) << endl;
    update(nums, tree, 1, 25);
    return 0;
}
