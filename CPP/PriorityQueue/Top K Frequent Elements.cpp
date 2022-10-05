/*
Problem: Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
Example:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

To solve this problem following steps are taken:-

-> Create an Unordered Set (Hashmap) to store the frequency of the number along with the number itself.
-> Create a Min Heap (Priority Queue) of pair of element (key) and frequency (value) and push them in the heap.
-> Push the elements in the Heap till the size of the Heap is less than K, if it crosses K then pop the top element.
-> After the traversal of the whole unordered map, the remaining heap contains the required solution.
-> Now from the remaining heap push the element in an ans vector.
*/
    #include<bits/stdc++.h>
    using namespace std;

    vector<int> topKFrequent(vector<int>& nums, int k) {
		
		// hashmap to store the element and frequency
        unordered_map<int, int> m;
		
		// just incrementing the frequency of the present element in the hashmap
        for(int i=0; i<nums.size(); i++) m[nums[i]]++;
		
		// Min Heap to store the frequency(key) and element(value) 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		
		// Traversing the hashmap for inserting in the heap
        for(auto i:m){
			// Pushing in the Heap
            pq.push({i.second, i.first});
			
			// If the size of the Heap crosses K then the top element is popped
            if(pq.size()>k){
                pq.pop();
            }
        }
		
		// The required vector, which is to be returned
        vector<int> ans;
		
		// Traversing the Heap to insert in the required vector
        while(!pq.empty()){
			
			// Pushing in the ans vector
            ans.push_back(pq.top().second);
			
			// deleting the element from the Heap
            pq.pop();
        }
		
		// Returning the ans vector
        return ans;
    }

    int main(){
        vector<int> arr={1,1,1,2,2,3};
        int k=2;
        vector<int> result=topKFrequent(arr,k);
        for(int i=0;i<result.size();i++){
            cout<<result[i]<<" ";
        }
        return 0;
    }