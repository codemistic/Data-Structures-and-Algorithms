public class EqualsCheck {
    public static void main(String[] args) {
        Abc abc1 = new Abc("abc1", 1);
        Abc abc2 = new Abc("abc1", 1);

        boolean check = abc1.equals(abc2);
        if (check) {
            System.out.println("Both objects are equal");
        } else {
            System.out.println("Both objects are unequal");
        }
    }
}
