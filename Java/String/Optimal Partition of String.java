class Solution {
    public int partitionString(String s) {
         int ans = 1;
        HashSet<Character> st = new HashSet<>();
        for(int i=0;i<s.length();i++){
 		  // Insert Till we find duplicate element.
            if(!st.contains(s.charAt(i))){
                st.add(s.charAt(i));
            }
            else{
			 // If we found duplicate char then increment count and clear set and start with new set.
                ans++;
                st.clear();
                st.add(s.charAt(i));
            }
        }
        return ans;
    }
}
