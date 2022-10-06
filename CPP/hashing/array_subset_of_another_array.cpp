string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int, int> mp;
    // Store all elements of a1 in mp
    for(int i = 0; i < n; i++) mp[a1[i]]++;
    // Check if all elements of a2 are present in mp
    for(int i = 0; i < m; i++){
        if(mp[a2[i]] > 0){
            mp[a2[i]]--;
        }
        else{
            return "No";
        }
    }
    return "Yes";
}
