/*
Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
Example:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5


Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

*/

#include<bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for(int i=0;i<nums.size();i++){
        pq.push(nums[i]);
    }
    k--;
    while(k--){
        pq.pop();
    }
    return pq.top();
}