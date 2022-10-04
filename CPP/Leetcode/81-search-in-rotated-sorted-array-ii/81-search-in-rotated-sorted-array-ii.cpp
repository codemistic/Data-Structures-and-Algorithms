#include<bits/stdc++.h>
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        std::vector<int>::iterator it;
        it = std::find (nums.begin(), nums.end(), target);
        if (it != nums.end())
        {
            return true;
        }
        else return false;
        
    }
};