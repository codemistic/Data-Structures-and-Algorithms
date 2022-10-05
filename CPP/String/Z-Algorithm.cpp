void solve(string str,int n,vector<int>& arr){
    int l = 0;
    int r = 0;
    arr[0] = 0;
    for(int i = 1;i < n;i++){
        if(i > r){
            l = i;
            r = i;
            while(r < n && str[r] == str[r-l]){
                r++;
            }
            arr[i] = r - l;
            r--;
        }else{
            int k = i - l;
            if((arr[k] + i) <= r){
                arr[i] = arr[k];
            }else{
                l = i;
                while(r < n && str[r] == str[r-l]){
                    r++;
                }
                arr[i] = r-l;
                r--;
            }
        }
    }
}

int zAlgorithm(string s, string p, int n, int m)
{
	// Write your code here
    string str = p + "$" + s;
    int len = str.size();
    vector<int> arr(len,0);
    solve(str,len,arr);
    int c = 0;
    for(int i = 0;i < len;i++){
        if(arr[i] >= p.size()){
            c++;
        }
    }
    return c;
}