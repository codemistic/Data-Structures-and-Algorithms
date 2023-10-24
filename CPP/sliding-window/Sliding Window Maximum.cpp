class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int>v;
    deque<int> dq;
     for (int i = 0; i < k; ++i) {
        
        while (!dq.empty() && nums[i] >= nums[dq.back()])
            dq.pop_back(); 

        
        dq.push_back(i);
    }
     
    for (int i=k; i < n; ++i) {
        
        // cout << nums[dq.front()] << " ";
        v.push_back(nums[dq.front()] );

        
        while ((!dq.empty()) && dq.front() <= i - k)
            dq.pop_front();

       
        while ((!dq.empty()) && nums[i] >= nums[dq.back()])
            dq.pop_back();

       
        dq.push_back(i);
    }
//    cout << nums[dq.front()];
   v.push_back(nums[dq.front()]);
   return v;

    }
};

//************************* 1. O(NlogK) ********************************

// vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     vector<int> result;
//     if (k == 0) return result;
//     multiset<int> w;
//     for (int i = 0, n = (int)nums.size(); i < n; i++) {
//         if (i >= k)
//             w.erase(w.find(nums[i-k]));
//         w.insert(nums[i]);
//         if (i >= k-1)
//             result.push_back(*w.rbegin());
//     }
//     return result;
// }

//************************* 2. O(NlogN) ***********************************

// vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     vector<int> result;
//     if (k == 0) return result;
//     priority_queue<pair<int, int>> w;
//     for (int i = 0, n = (int)nums.size(); i < n; i++) {
//         while (!w.empty() && w.top().second <= i-k)
//             w.pop();
//         w.push(make_pair(nums[i],i));
//         if (i >= k-1)
//             result.push_back(w.top().first);
//     }
//     return result;
// }

//***************************** 3. O(N) ********************************

// vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     vector<int> result;
//     if (k == 0) return result;
//     deque<int> w;
//     for (int i = 0, n = (int)nums.size(); i < n; i++) {
//         while (!w.empty() && w.front() <= i-k)
//             w.pop_front();
//         while (!w.empty() && nums[w.back()] <= nums[i])
//             w.pop_back();
//         w.push_back(i);
//         if (i >= k-1)
//             result.push_back(nums[w.front()]);
//     }
//     return result;
// }