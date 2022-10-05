class Solution {
    public int longestStrChain(String[] words) {
        Map<String,Integer> map = new HashMap<>();
        Arrays.sort(words, (a,b)->a.length() - b.length());
        int res = 0;
        for(String word : words)
        {
            int best = 0;
            for(int i=0;i<word.length();i++)
            {
                String prev = word.substring(0,i) + word.substring(i+1);
                best = Math.max(best,map.getOrDefault(prev,0)+1);
            }
            map.put(word,best);
            res = Math.max(res,best);
        }
        return res;
    }
}