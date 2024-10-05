import java.util.ArrayList;
import java.util.Collections;
public class arraylist{
    public static void main(String args[]){
        // declaring an array list..
        ArrayList<Integer> list= new ArrayList<Integer>();
         // adding elements to arraylist..
         list.add(0);
         list.add(6);
         list.add(7);
         // printing the arraylist;
         System.out.println(list);
         //getting the element;
         int element= list.get(0);
         System.out.println(element);
         //add element in between..
         list.add(1,1);
         System.out.println(list);
         //setting element or modifying array list
         list.set(0,9);
         System.out.println(list);
         // removing the elements from array list;
         list.remove(1);
         System.out.println(list);
         //getting the size;
         System.out.println(list.size());
         
         //loops
         for(int i=0;i<list.size();i++){
             System.out.println(" elements of arraylist" + list.get(i));
         }
         
          Collections.sort(list);
          System.out.println(list);
    }
}
