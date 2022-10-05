class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<double,int> map;
        for(int i = 0;i<arr.size();i++)
        {
            if(map.count((double)arr[i]*2) || (map.count((double)arr[i]/2)))
            {
                return true;
            }
            map[arr[i]]++;
                
        }
        return false;
    }
};