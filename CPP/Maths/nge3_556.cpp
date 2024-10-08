class Solution {
public:
    int nextGreaterElement(int num) {
        vector<int> v;
        while(num){
            v.push_back(num%10);
            num /= 10;
        }
        if(is_sorted(v.begin(), v.end()))
            return -1;
        reverse(v.begin(), v.end());
        next_permutation(v.begin(), v.end());
        long long temp = 0;
        for(int i = 0; i < v.size(); i++){
            temp = temp*10 + v[i];
        }
        if(temp > INT_MAX) return -1;
        return temp;
    }
};