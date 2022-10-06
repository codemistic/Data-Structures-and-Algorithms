// I have provided the optimal solution of the code find in moutain array of leetcode(hard). Question no: 1095
int binary(MountainArray &mountainArr, int s, int e, int target){
    int start = s;
    int end  = e;
    while(s<=e){
        int mid =  s+(e-s)/2;
        if(mountainArr.get(mid)==target){
            return mid;
        }
        else if(mountainArr.get(mid)>target){
            if(mountainArr.get(start)<=mountainArr.get(end)){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        else{
            if(mountainArr.get(start)<=mountainArr.get(end)){
                s = mid+1;
            }
            else{
                e = mid-1;
            }        
        }
    }
    return -1;
}
int mountainIndex(MountainArray &mountainArr){
    int s = 0, e= mountainArr.length()-1;
    while(s<e){
        int mid = s+(e-s)/2;
        if(mountainArr.get(mid) < mountainArr.get(mid+1)){
            s = mid + 1;
        }
        else{
            e = mid;
        }
    }
    return e;
}
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int mountain = mountainIndex(mountainArr);
        if(target>=mountainArr.get(0)&&target<=mountainArr.get(mountain)){
            int ans = binary(mountainArr,0,mountain,target);
            if(ans != -1){
                return ans;
            }
        }
           
         return binary(mountainArr,mountain+1,mountainArr.length()-1,target);
    }
    
};