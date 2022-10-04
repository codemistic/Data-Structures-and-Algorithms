public class LargeStr {
    

    public static void main(String[] args) {
        String Fruits[] = {"Nishit","Bhumika","Kapila"};
String Largest = Fruits[0];
for(int i=1 ;i< Fruits.length;i++){
if(Largest.compareTo(Fruits[i]) < 0 ){
Largest = Fruits[i];
}
}
System.out.println(Largest);
    }
}
