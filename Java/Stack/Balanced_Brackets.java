//For a given a string expression containing only round brackets or parentheses, check if they are balanced or not. Brackets are said to be balanced if the bracket which opens last, closes first.

package Stack;
import java.util.Stack;

public class Balanced_Brackets {

    public static boolean checkBalanced(String str) {
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if (ch == '(' || ch == '{' || ch == '[') {
                stack.push(ch);
            } else if( ch=='}' || ch==')' || ch==']' ) {

                if(stack.isEmpty()) {
                    return false;
                }
                else if(ch==')' && stack.peek()=='('||ch==']'&& stack.peek()=='['||ch=='}'&& stack.peek()=='{')
                    stack.pop();
                else {
                    return false;
                }
            }
        }
        if(stack.isEmpty()) {
            return true;
        }
        else {
            return false;
        }
    }

    public static void main(String[] args) {
        String string = "{ a + [ b+ (c + d)] + (e + f) }";
        System.out.println(checkBalanced(string));
    }
}
