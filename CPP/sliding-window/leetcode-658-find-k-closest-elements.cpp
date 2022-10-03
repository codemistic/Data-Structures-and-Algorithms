//leet-code discuss link :
// https://leetcode.com/problems/find-k-closest-elements/discuss/2637568/Very-Simple-O(N)-solution-using-sliding-window

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //lets try sliding window
        //here sum  = sum of all differences between elements and x.
        //sum to store all values in your window of size k
        int sum =0;
        //indices of window with minimum sum
        pair<int,int> win = {0,k-1};
        for(int i =0;i<k;i++){
            sum+=abs(arr[i]-x);
        }
        int mn = sum;
        //traverse all windows and find one with minimum sum
        for(int i = 1;i<=arr.size()-k;i++){
            //remove first element
            sum-=abs(arr[i-1]-x);
            //add new element
            sum+=abs(arr[i+k-1]-x);
            //update mn and win in case a new min window is found
            if(mn>sum){
                mn = sum;
                win = {i,i+k-1};
            }
        }
        //store the result in res and return.
        vector<int> res;
        for(int i = win.first;i<=win.second;i++){
            res.push_back(arr[i]);
        }
        return res;
    }
};
