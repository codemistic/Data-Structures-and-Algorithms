public class StrBuilder {
    

public static void main(String[] args) {
    StringBuilder sc = new StringBuilder(""); 
for(char ch='a'; ch < 'z';ch++   ){
sc.append(ch);
}

System.out.print(sc+ " ") ;
}
}

// Java StringBuilder class is used to create mutable (modifiable) String. The Java StringBuilder class is same as StringBuffer class except that it is non-synchronized. It is available since JDK 1.5.

/*  Important Constructors of StringBuilder class
 Constructor	Description
 StringBuilder()	It creates an empty String Builder with the initial capacity of 16.
 StringBuilder(String str)	It creates a String Builder with the specified string.
 StringBuilder(int length)	It creates an empty String Builder with the specified capacity as length.*/