public class Compress {
    
    public static String compressq(String str){
        String newstr = "";
    for(int i=0 ; i<str.length() ; i++){
    Integer count =1;
    while( i < str.length()-1 &&  str.charAt(1) == str.charAt(i+1) ){
    count++;
    i++;
    }
    newstr += str.charAt(i);
    if(count > 1){
        newstr += count.toString();
    }
    }
        return newstr;
    }
    
    
    
        public static void main(String[] args) {
            String str = "aavv";
    System.out.print(compressq(str));
    
        }
    }
//time Complexcity O(N)    :) #NIshit