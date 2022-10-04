public class HashCodeDemo {
    public static void main(String args[]){
        String text ="Ganga";
        String text1 ="GangaRiver";
        Integer e = text.hashCode();
        System.out.println(text1.hashCode());
        String str = text1.substring(0,5);
        System.out.println(str);
        Integer f = text1.hashCode();
        System.out.println(e.equals(f));
    }
}
