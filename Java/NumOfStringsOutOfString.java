package XtraQuestions.StringsArrayMixed;

import java.util.ArrayList;

// Count of strings that can be formed from another string using each character at-most once
// Link: https://www.geeksforgeeks.org/count-of-strings-that-can-be-formed-from-another-string-using-each-character-at-most-once/

public class NumOfStringsOutOfString {
    public static void main(String[] args) {
        
        String st1= "gkefesoreeksgekseg";
		String st2 = "geeks";
        System.out.println("The number of str2 which can be made out of str1 are: " + countStrings(st1, st2));
    }

    // NOTE: We can use hashmap for characters and their counts (it will make things easy)
    // ALGORITHM
    // but we are using an arraylist to store the distict characters of string 2
    // Then we created two arrays of same length to store the frequencies of those characters present in string 1 and 2 respectedly
    // now, we have frequencies of characters for both strings in 2 arrays
    // fr1 is for string 1
    // fr2 is for string 2
    // now, we will use a while loop that will run till flag is true
    // inside this we will run a for loop
    // this loop will traverse the frequency array again and again
    // while traversing we will subtarct the each character frquency of fr1 from fr2
    // if fr1[] - fr2[] not goes below -1 
    // we will continue the while loop and after each traversal of for loop we will increase the maincount
    // if fr1[] - fr2[] goes below -1, we will set our flag = false and break the for loop
    // in last, return maincount 

    public static int countStrings(String st1, String st2){
	    ArrayList<Character> ch2 = new ArrayList<>();
	    
	    int maincount = 0;
	    
	    for(int i=0; i<st2.length(); i++){
	        if(!ch2.contains(st2.charAt(i))){
	            ch2.add(st2.charAt(i));
	        }
	    }
	    
	    int[] fr2 = new int[ch2.size()];
	    int[] fr1 = new int[ch2.size()];
	    
	    for(int i=0; i<ch2.size(); i++){
	        char ch = ch2.get(i);
	        int count = 0;
	        for(int j=0; j<st2.length();j++){
	            if(ch==st2.charAt(j)){
	                count++;
	            }
	        }
	        
	        fr2[i] = count;
	    }
	    
	    for(int i=0; i<ch2.size(); i++){
	        char ch = ch2.get(i);
	        
	       int count = 0;
	        for(int j=0; j<st1.length();j++){
	            if(ch==st1.charAt(j)){
	                count++;
	            }
	        }
	        
	        fr1[i] = count;
	    }
	    
	    boolean flag = true;
	    while(flag==true){
	        for(int i=0; i<fr1.length; i++){
	            fr1[i]-=fr2[i];
	            if(fr1[i]<=0){
	                flag = false;
	            }
	        }
	        maincount++;
	    }
	    
	    return maincount;
	}
}
