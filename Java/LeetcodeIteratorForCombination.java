/**Leetcode - 1286 - Iterator for Combination (https://leetcode.com/problems/iterator-for-combination/)
Question:
Design the CombinationIterator class:
*CombinationIterator(string characters, int combinationLength) Initializes the object with a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
*next() Returns the next combination of length combinationLength in lexicographical order.
*hasNext() Returns true if and only if there exists a next combination.
*/

class CombinationIterator {

    String s;
    int l;
    int c=0;
    List<String> ar=new LinkedList<String>();
    
    public CombinationIterator(String sr, int d) {
        s=sr;l=d;
        traversal("",d,0);
    }
    
    public String next() {
        c++;
        return ar.get(c-1);
    }
    
    public boolean hasNext() {
        if(c<ar.size()){
            return true;
        }
        return false;
    }
    public void traversal(String st,int d,int idx){
        if(st.length()==d){
            ar.add(st);
            return;
        }
        for(int i=idx;i<s.length();i++){
            traversal(st+s.charAt(i),d,i+1);
        }
    }
}
//Contribution by shubhrastogi07
