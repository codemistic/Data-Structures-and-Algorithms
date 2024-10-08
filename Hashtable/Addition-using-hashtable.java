import java.io.*;
import java.util.*;
  
class AddElementsToHashtable {
    public static void main(String args[])
    {
        // Initialization of a Hashtable
        // using Generics
        Hashtable<Integer, String> ht1 = new Hashtable<>(), ht2 = new Hashtable<>();
  
        // Inserting the Elements
          // using put() method
        ht1.put(1, "Geeks");
        ht1.put(2, "For");
        ht1.put(3, "Geeks");
  
        ht2.put(1, "Geeks");
        ht2.put(2, "For");
        ht2.put(3, "Geeks");
          
          // Print mappings to the console
        System.out.println("Mappings of ht1 : " + ht1);
        System.out.println("Mappings of ht2 : " + ht2);
    }
}
 

