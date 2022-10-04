class Solution {
    public String reverseWords(String s) {
        Stack<String> st = new Stack<>();
        s+=" ";
        String str = "";
        String ans="";
        for(int i =0;i<s.length();i++){
            
            if(s.charAt(i)==' '){
                if(str.trim().isEmpty()){
                    continue;
                }
                else{
                      st.push(str.trim());
                }
              
                str="";
            }
            else{
                str+=s.charAt(i);
            }
           
        }
         while(st.size()!=1){
                ans+=st.peek()+" ";
                st.pop();
            }
            ans+=st.peek();
        return ans.trim();
    }
	}
