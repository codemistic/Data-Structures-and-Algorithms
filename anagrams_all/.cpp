class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        int sn = s.length();
        int pn = p.length();
        List<Integer> res = new ArrayList<>();
        if (sn<=0 || pn<=0) return res;
        
        int[] pArr = new int[26];
        for (int i = 0; i < pn; i ++)
        {
            char c = p.charAt(i);
            pArr[(int)(c-'a')] ++;
        }
        
        for (int i = 0; i <= sn-pn; i ++)
        {
            char c = s.charAt(i);
            if (pArr[(int)(c-'a')]==0) continue;
            if (isAnagram(s, i, i+pn-1, pArr))
            {
                res.add(i);
            }
        }
        
        return res;
    }
    
    private boolean isAnagram(String s, int start, int end, int[] pArr)
    {
        int[] sArr = new int[26];
        for (int i = start; i <= end; i ++)
        {
            char c = s.charAt(i);
            if (pArr[(int)(c-'a')]==0) return false;
            sArr[(int)(c-'a')] ++;
            if (pArr[(int)(c-'a')]<sArr[(int)(c-'a')]) return false;
        }
        
        return true;
    }
}
