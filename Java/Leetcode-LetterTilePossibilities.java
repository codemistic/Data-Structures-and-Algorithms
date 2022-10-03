/**Leetcode - 1079 - Letter Tile Possibilities (https://leetcode.com/problems/letter-tile-possibilities/)
Question:You have n  tiles, where each tile has one letter tiles[i] printed on it.
Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.
*/

class Solution {
    public int numTilePossibilities(String t) {
      Set<String> ar=new HashSet<String>();
        boolean b[]=new boolean[t.length()];
        traversal(ar,t,b,"");
        return ar.size()-1;
    }
    public void traversal(Set ar, String t,boolean [] vis, String s){
        ar.add(s);
        for(int i=0;i<vis.length;i++){
            if(!vis[i]){
                vis[i]=true;
                traversal(ar, t,vis,s+t.charAt(i));
                vis[i]=false;
            }
        }
    }
}
