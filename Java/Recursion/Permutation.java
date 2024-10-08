import java.util.*;
class Permutation {
    static String swap(String mystring, int i, int j) // function to swap the characters in the string
    {
        char ch[] = mystring.toCharArray();
        char tempo = ch[i];
        ch[i] = ch[j];
        ch[j] = tempo;
        return String.valueOf(ch);
    }
    static void permutation(String s, int index) // To permuatate the string
    {
        if (index == s.length() - 1) // if the index equals the length, print the string
            System.out.println(s);
        for (int j = index; j < s.length(); j++) {
            s = swap(s, j, index); // Swap the character to manipulate the string
            permutation(s, index + 1); // Send it to get the permutation
            s = swap(s, j, index); // Swap back to get the original string
        }
    }
    public static void main(String args[]) {
        Scanner I = new Scanner(System.in);
        System.out.println("ENTER A STRING");
        String s = I.nextLine();
        System.out.println("Given Below are all the permutations of the string");
        permutation(s, 0);
        I.close();
    }
}
// Time Complexity : N * N!
/*
//Cpp function to get the shit done, lexographically and unique elements
class Solution
{
	public:
	set<string> ans;
	    void permutate(string s, int in)
	    {
	        if(in == s.size()-1)
	        {
	            ans.insert(s);
	            return;
	        }
	        for(int j = in; j < s.size();j++)
	        {
	            swap(s[j],s[in]);
	            permutate(s, in + 1);
	            swap(s[j],s[in]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    permutate(S,0);
		    vector<string> res(ans.begin(), ans.end());
		    return res;
		}
};
*/