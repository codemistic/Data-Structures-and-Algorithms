// program of constructor overloading
// constructors can be defined by  three types in case of passing arguments 1) parameterized 2) non parameterized 3) default
class overload{
    int a;
    int b;
 float c;
    public overload(){ // non parameterized constructor
        a=0;
        b=0;c=0;
        System.out.println("the values are :" +a+ "," +b+ "," +c);
    } 
    public overload(int x) {// parameterized constructor
        a=x;
        b=0;c=0;
         System.out.println(" after given one parameter, values are :" +a+ "," +b+"," +c);
}
public overload(int x, int y, float z){
   a=x;
   b=y;
   c=z;
    System.out.println(" final values are :" +a+ "," +b+"," +c);
}
public static void main(String[]args){
    overload obj1= new overload();
    overload obj2= new overload(4);
    overload obj3= new overload( 3,5,7);
    
}
}
/*default construtor..
public class constructor{
    int num;
    public constructor(){
        num=0; // default constructor
    }
    public constructor(int value){
        num= value;
    }
    public static void main(String[]args){
       constructor obj1= new constructor();
       constructor obj2= new constructor();
    }
}
*/
